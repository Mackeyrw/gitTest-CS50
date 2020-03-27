#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc <= 1 || argc >= 3)
    {
        printf("Enter one number.\n");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]) || argv[1] < 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    string text = get_string("plaintext: ");

    int key = atoi(argv[1]);

    if (key > 26)
    {
        key = key % 26;
    }

    printf("ciphertext: ");

    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] > 64 && text[i] < 91) || (text[i] > 96 && text[i] < 123))
        {
            if (text[i] > 64 && text[i] < 91)
            {
                if (text[i] + key > 90)
                {
                    printf("%c", text[i] - (26 - key));
                }
                else
                {
                    printf("%c", text[i] + key);
                }
            }

            if (text[i] > 96 && text[i] < 123)
            {
                if (text[i] + key > 122)
                {
                    printf("%c", text[i] - (26 - key));
                }
                else
                {
                    printf("%c", text[i] + key);
                }
            }
        }
        else
        {
            printf("%c", text[i]);
        }
    }

    printf("\n");

    return 0;
}