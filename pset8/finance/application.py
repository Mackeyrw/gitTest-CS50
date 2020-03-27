import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""

    rows = []
    inner = []
    grandTotal = 0

    symbol = db.execute("SELECT DISTINCT symbol FROM trans WHERE id = ?", session["user_id"])

    for i in range(0, len(symbol)):

        shares = db.execute("SELECT SUM(shares) FROM trans WHERE symbol = ? AND id = ?", symbol[i]["symbol"], session["user_id"])

        symbolOnly = symbol[i]["symbol"]

        sharesOnly = shares[0]["SUM(shares)"]

        price = lookup(symbol[i]["symbol"])["price"]

        total = price * shares[0]["SUM(shares)"]

        inner.append(symbolOnly)
        inner.append(sharesOnly)
        inner.append(price)
        inner.append(total)
        rows.append(inner)
        inner = []

    cashOnHand = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])

    for i in range(len(rows)):
        grandTotal += rows[i][3]

    grandTotal += cashOnHand[0]["cash"]

    return render_template("index.html", rows=rows, cashOnHand=usd(cashOnHand[0]["cash"]), grandTotal=usd(grandTotal))


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""

    if request.method == "POST":

        symbol = request.form.get("symbol")

        if not symbol:
            return apology("No Symbol Entered", 403)

        if lookup(symbol) == None:
            return apology("Stock not found", 403)

        shares = request.form.get("shares")

        if not shares or int(shares) <= 0:
            return apology("You must enter a positive integer", 403)

        cost = lookup(symbol)["price"] * int(shares)

        cash = db.execute("SELECT cash FROM users WHERE id = :username", username=session["user_id"])

        if cost > cash[0]["cash"]:
            return apology("You cannot afford this transaction", 403)

        db.execute("INSERT INTO trans (id, symbol, shares, price) VALUES (?, ?, ?, ?)", session["user_id"], symbol.upper(), shares, lookup(symbol)["price"])

        cashUpdate = cash[0]["cash"] - cost

        db.execute(f"UPDATE users SET cash = ? WHERE id = ?", cashUpdate, session["user_id"])

        return redirect("/")

    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""

    rows = db.execute("SELECT symbol, shares, price, date FROM trans WHERE id = ?", session["user_id"])

    return render_template("history.html", rows=rows)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = :username",
                          username=request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""

    if request.method == "POST":

        if not request.form.get("symbol"):
            return apology("No Symbol Entered", 403)

        obj = lookup(request.form.get("symbol"))

        if obj == None:
            return apology("No stock found", 403)

        return render_template("quoted.html", name=request.form.get("symbol") ,quote=obj["price"])

    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    session.clear()

    if request.method == "POST":

        if not request.form.get("username"):
            return apology("username required", 403)

        rows = db.execute("SELECT * FROM users WHERE username = :username", username=request.form.get("username"))

        if len(rows) != 0:
            return apology("username already exists", 403)

        elif not request.form.get("password") or not request.form.get("confirmation"):
            return apology("password and confirmation required", 403)

        elif request.form.get("password") != request.form.get("confirmation"):
            return apology("passwords must match", 403)

        hashPass = generate_password_hash(request.form.get("password"), method='pbkdf2:sha256', salt_length=8)

        db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", request.form.get("username"), hashPass)

        return redirect("/login")

    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    if request.method == "POST":

        totalShares = 0
        symbol = request.form.get("symbol")

        if not symbol:
            return apology("No Symbol Entered", 403)

        stockCheck = db.execute("SELECT symbol FROM trans WHERE id = ?", session["user_id"])
        if stockCheck == None:
            return apology("Stock not owned", 403)

        shares = request.form.get("shares")

        if not shares or int(shares) <= 0:
            return apology("You must enter a positive integer", 403)

        totalShares = db.execute("SELECT SUM(shares) FROM trans WHERE symbol = ? AND id = ?", symbol, session["user_id"])[0]["SUM(shares)"]

        if int(shares) > totalShares:
            return apology("You don't own enough shares", 403)

        db.execute("INSERT INTO trans (id, symbol, shares, price) VALUES (?, ?, ?, ?)", session["user_id"], symbol.upper(), -int(shares), lookup(symbol)["price"])

        cash = db.execute("SELECT cash FROM users WHERE id = :username", username=session["user_id"])[0]["cash"]

        profit = int(shares) * lookup(symbol)["price"]

        cashUpdate = cash + profit

        db.execute("UPDATE users SET cash = ? WHERE id = ?", cashUpdate, session["user_id"])

        return redirect("/")

    else:

        rows = db.execute("SELECT DISTINCT symbol FROM trans WHERE id = ?", session["user_id"])

        return render_template("sell.html", rows=rows)


@app.route("/add", methods=["GET", "POST"])
@login_required
def add():
    """Add cash to users total"""

    if request.method == "POST":

        add = int(request.form.get("add"))

        if not add:
            apology("Enter a number to add cash", 403)

        if add <= 0:
            apology("Number must be a positive integer", 403)

        cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])[0]["cash"]

        add += cash

        db.execute("UPDATE users SET cash = ? WHERE id = ?", add, session["user_id"])

        return redirect("/")

    else:
        return render_template("add.html")

def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)


# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
