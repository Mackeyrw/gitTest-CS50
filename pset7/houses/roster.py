import sys
from cs50 import SQL

if len(sys.argv) != 2:
    print('Wrong')
    sys.exit()

db = SQL("sqlite:///students.db")

output = db.execute("SELECT first, middle, last, birth FROM students WHERE house = ? ORDER BY last, first", sys.argv[1])

for i in range(len(output)):
    if output[i]['middle'] != None:
        print(output[i]['first'], output[i]['middle'], output[i]['last'], output[i]['birth'])
    else:
        print(output[i]['first'], output[i]['last'], output[i]['birth'])
