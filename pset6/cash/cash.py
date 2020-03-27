from cs50 import get_float
import math

owed = get_float("Change: ")

while owed < 0:
    owed = get_float("Change: ")

owed = math.floor(owed * 100)

counter = 0
dimecounter = 0
nickelcounter = 0
pennycounter = 0

#Control flow: Check if quarters go in then divide and assign variables. Rinse and repeat. Update counter as you go.
if owed >= 25:
    counter = math.floor(owed / 25)
    owed = owed - (counter * 25)

if owed >= 10:
    dimecounter = math.floor(owed / 10)
    counter = counter + dimecounter
    owed = owed - (dimecounter * 10)

if owed >= 5:
    nickelcounter = math.floor(owed / 5)
    counter = counter + nickelcounter
    owed = owed - (nickelcounter * 5)

if owed >= 1:
    pennycounter = math.floor(owed / 1)
    counter = counter + pennycounter
    owed = owed - (pennycounter * 1)

#print the final counter.
print(counter)