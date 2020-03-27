import csv
import sys
from cs50 import SQL

if len(sys.argv) != 2:
    print('Wrong')
    sys.exit()

db = SQL("sqlite:///students.db")
name = ''

with open(sys.argv[1], 'r') as csvFile:
    csv = csv.reader(csvFile)

    for row in csv:
        if row[0] != 'name':
            name = row[0].split(' ')

            if len(name) < 3:
                name.append(name[1])
                name[1] = None

            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)", name[0], name[1], name[2], row[1], row[2])




