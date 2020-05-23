#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main (int argc, string argv[])
{
    //if no. of arguments are not 2
    if (argc!=2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    int l = strlen(argv[1]);
    // if the key is not of 26 letter length
    if(l != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for (int i=0; i< l; i++)
    {
        // if any of the key is not letter
        if(isalpha(argv[1][i]) == 0)
        {
            printf("The key should contain alphabets only\n");
            return 1;
        }
        //checking for the repetetion of letters
        for (int j=i+1; j<l; j++)
        {
            if(toupper(argv[1][i]) == toupper(argv[1][j]))
            {
                printf("NO repetion of letters are allowed\n");
                return 1;
            }

        }
    }
    string txt = get_string("plaintext :  ");
    for (int i =0; txt[i]!='\0'; i++)
    {
        int p = (int)txt[i];
        if (isupper(txt[i]) != 0)
        {
            txt[i] = toupper(argv[1][p-65]);
        }
        else if (islower(txt[i]) != 0)
        {
            txt[i] = tolower(argv[1][p-97]);
        }
    }
    printf("ciphertext : %s\n", txt);
    return 0;



}