#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
//Declare all variables here
int lettercounter = 0;
int wordcounter = 0;
int sentencecounter = 0;
float L = 0;
float S = 0;
int index = 0;

int main(void)
{
    string text = get_string("Text: ");

    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            lettercounter++;
        }
    }

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            wordcounter++;
        }
    }
    wordcounter += 1;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentencecounter++;
        }
    }

    L = ((float) lettercounter / (float) wordcounter) * 100;
    S = ((float) sentencecounter / (float) wordcounter) * 100;

    index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}