// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include "dictionary.h"
#include <strings.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int counter = 0;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int val = hash(word);

    node *cursor = table[val];

    while (cursor != NULL)
    {

        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }

        cursor = cursor->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int hnum = word[0];
    hnum -= 97;
    if (hnum < 0)
    {
        hnum += 32;
    }
    return hnum;

}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    for (int i = 0; i < 26; i++)
    {
        node *head = malloc(sizeof(node));
        if (head == NULL)
        {
            unload();
            return false;
        }

        table[i] = head;
        strcpy(table[i]->word, "end");
        table[i]->next = NULL;

    }

    FILE *dict;

    dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        return false;
    }

    char buffer[LENGTH];

    while (fscanf(dict, "%s", buffer) != EOF)
    {

        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            unload();
            return false;
        }

        strcpy(n->word, buffer);

        unsigned int key = hash(n->word);

        n->next = table[key];

        table[key] = n;

        counter++;
    }

    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if (counter > 0)
    {
        return counter;
    }

    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < 26; i++)
    {
        node *cursor = table[i];
        node *tmp = table[i];

        while (cursor != NULL)
        {
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }

    }

    return true;
}
