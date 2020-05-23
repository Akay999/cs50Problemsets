#include <stdio.h>
#include <cs50.h>

void formbricks (int n);

int main (void)
{
    int h;
    do 
    {
    h = get_int("specify the height of pyramid between 1 and 8\n");    
    }
    while (h < 1 || h > 8);
    formbricks (h);
    
}

void formbricks (int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < (2*n+2); j++)
        {
            if ( (j-n) < -i - 1 || (j-n)==0 || (j-n)> i+2 || (j-n)==1)
            {
                printf(" ");
            }
            else 
            {
                printf("#");
            }
        }
        printf("\n");
    }
}