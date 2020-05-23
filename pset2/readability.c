#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int lettercount(string h);
int wordcount(string h);
int sentcount(string g);

int main (void)
{
    string txt;
    txt = get_string("TEXT:\t");

    //determining the letters in the text
    int letters = lettercount(txt);

    //determining the words in the text
    int words = wordcount(txt);

    //determining the sentences in the text
    int sen = sentcount(txt);

    //average no. of letters in 100 words
    float l = ((float)letters/(float)words)*100;

    //average no. of sentences in 100 words
    float s = ((float)sen/(float)words)*100;

    int index;
    index = round((0.0588 * l) - (0.296 * s) - 15.8) ;

    if (index < 1 )
    {
        printf("befor grade 1\n");
    }
    else if(index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("GRADE %i\n", index );
    }

}



int lettercount(string h)
{
    //counting the length of the text
    int k = strlen(h);
    int count = 0;

    //counting no. of letters
    for(int i = 0; i < k; i++)
    {
        if(isalpha(h[i])!=0)
        {
            count++;
        }
    }
    // returning no. of letters
    return count;
}


int wordcount(string h)
{
    int count=0;
    for(int i= 0; h[i]!='\0'; i++)
    {
        if(isspace(h[i]) != 0)
        {
            count++;
        }
    }
    return count+1;
}


int sentcount(string g)
{
    int count = 0;
    for (int i = 0; g[i]!='\0';i++)
    {
        if (g[i]=='.' || g[i]=='?' || g[i]=='!')
        {
            count++;
        }
    }
    return count;
}