#include <stdio.h>
#include <cs50.h>
#include <math.h>


int main (void)
{
    float n;
    do
    {
        n = get_float("How much change do you own\n");
    }
    while ( n < 0);

    int count = 0;

    int h = round(n * 100);

    // do till customer ows zero change.
    while (h !=0 )
    {
        // check for quaters.
        while (h >= 25)
        {
            h -= 25;
            count ++;
        }

        // check for dimes.6
        while ( h >= 10 )
        {
            h -= 10;
            count++;
        }

        // check for nickels.
        while ( h >= 5)
        {
            h -= 5;
            count++;
        }

        // check for pennies.
        while ( h >= 1)
        {
           h -= 1;
            count++;
        }
    }

    // printing the minimum number of coins required
    printf("The minimum number of coin required is %i\n", count);

}
