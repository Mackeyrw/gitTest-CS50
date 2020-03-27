from cs50 import get_string
import math
import re

lettercounter = 0
wordcounter = 0
sentencecounter = 0
L = 0
S = 0
index = 0
text = get_string("Text: ")
text = text.lower()

for i in range(len(text)):

    if re.search('[a-z]', text[i]):

        lettercounter += 1


for i in range(len(text)):

    if (text[i] == ' '):

        wordcounter += 1

wordcounter += 1

for i in range(len(text)):

    if text[i] == '.' or text[i] == '?' or text[i] == '!':

        sentencecounter += 1

L = (lettercounter / wordcounter) * 100

S = (sentencecounter / wordcounter) * 100

index = round(0.0588 * L - 0.296 * S - 15.8)

if index >= 16:

    print("Grade 16+")

elif index < 1:

    print("Before Grade 1")

else:

    print(f"Grade {index}")


