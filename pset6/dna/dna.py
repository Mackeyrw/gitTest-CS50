import csv
import sys

if len(sys.argv) != 3:
    print('Wrong')
    sys.exit()

counter = 0
temp = 0
arr = []
final = 0
x = True
end = 0

dna = open(sys.argv[2])
dna = dna.read()

with open(sys.argv[1], 'r') as csvFile:
    csv = csv.reader(csvFile)

    for row in csv:
        for k in range(1, len(row)):
            for i in range(len(dna)):
                if row[k] == dna[i:i + len(row[k])]:
                    counter += 1
                    j = i

                    while row[k] == dna[j + len(row[k]): j + (len(row[k]) * 2)]:
                        counter += 1
                        j = j + len(row[k])

                    if counter > temp:
                        temp = counter

                    counter = 0

            if len(arr) < len(row) - 1:
                arr.append(temp)

            temp = 0

        if len(row[1]) < 3:
            for l in range(len(arr)):
                if int(row[l + 1]) == arr[l]:
                    final += 1

                if final == len(row) - 1:
                    print(row[0])
                    end = 1

        final = 0

if end != 1:
    print("No match")

















