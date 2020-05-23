// Implements a dictionary's functionality
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include "dictionary.h"

long int wordcount = 0;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 5381;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    node *temp;
    char *tword = malloc(46);
    strcpy(tword, word);
    for (int i = 0; tword[i] != '\0'; i++)
    {
        tword[i] = tolower(tword[i]);
    }
    int hashno = hash(tword);
    temp = table[hashno];
    while(temp != NULL)
    {
        if(strcasecmp(tword, temp -> word) == 0)
        {
            return true;
        }
        temp = temp -> next;

    }
    free(tword);
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned long hash = 5381;
    int c;


    while ((c = *word++))
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    hash = hash % 5381;

    return hash;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{

    // opening the dictionary
    FILE *fin = fopen(dictionary, "r");
    if (fin == NULL)
    {
        printf("File not open \n");
        return false;
    }

    unsigned int hashno;
    char *tempword = malloc(46);

    //reading data from dictionary
    while (fscanf(fin, "%s", tempword) != EOF)
    {
        //getting a temp node for table
        node *temp = malloc(sizeof(node));
        if (temp == NULL)
        {
            fclose(fin);
            return false;
        }

        //setting its next pointer to null
        temp -> next = NULL;
        hashno = hash(tempword);
        strcpy(temp -> word, tempword);
        temp -> next = table[hashno];
        table[hashno] = temp;
        wordcount++;

    }
    free(tempword);
    fclose(fin);


    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return wordcount;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < 5381; i++)
    {
        node *temp, *freeup;
        temp = freeup = table[i];
        while(temp != NULL)
        {
            temp = temp -> next;
            free(freeup);
            freeup = temp;
        }
    }
    return true;
}

