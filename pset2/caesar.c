#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


int main(int argc , string argv[])
{
    if (argc == 2)
    {
        // checking for digits only
        int l = strlen(argv[1]);
        int sum = 0;

        for(int i=0; i < l; i++)
        {
            int a = (int)argv[1][i];
            if(a >= 48 && a <= 57)
            {
                sum += pow(10,l-1-i)*(a-48);
            }
            else
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        if (sum > 26)
        {
            sum = sum%26;
        }
        string txt = get_string("Enter the text:  ");
        string txt2 = malloc(sizeof(txt));
        strcpy(txt2, txt);
        int p= 0;
        int len = strlen(txt2);
        for(int j=0; j<len; j++)
        {
            p = (int)txt2[j];
            if(p>=65 &&p<=90)
            {
                p = p+sum;
                if (p>90)
                {
                    p=65+((p-90)-1);
                }
            }
            if (p>=97 && p<=122)
            {
                p=p+sum;
                if(p>122)
                {
                    p = 97 +((p-122)-1);
                }
            }
            txt2[j] = (char)p;
        }
        printf("encrepted text is : %s\n", txt2);
    }



    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

}
