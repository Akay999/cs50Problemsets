#include <cs50.h>
#include <stdio.h>

void smallbricks (int n);

int main(void)
{
  int h;
    do 
    {
        h = get_int ("give height between 1 and 8\n");
        
    }
    while ( h < 1 || h > 8 );
    smallbricks (h); 
}

void smallbricks (int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ( -(j-n) > i+1 )
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
