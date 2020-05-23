#include <stdio.h>
#include <cs50.h>

int count (int n);

int main (void)
{
    long int h;
    do
    {
        h = get_long("Enter the Number:  ");
    }
    while (h <= 0);

    // making a copy of the card no.
    long n = h;

    // counting no. of digits

    int count = 0, l;
    while (h != 0)
    {
        h /= 10;
        if (count == 14)
        {
            l = h;
        }
        count++;
    }
    int sum =0, digit, digitnum=1;
    while (n != 0)
    {
        digit = n % 10;
        n /= 10;
        if (digitnum % 2 == 0)
        {
            digit *= 2;
            if (digit > 9)
            {
                digit -= 9;
            }
            sum += digit;
        }
        else
        {
            sum += digit;
        }
        digitnum ++;

    }
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
    }
    if(count == 15)
    {
        printf("AMEX\n");
    }
    else if(count == 13)
    {
        printf("VISA\n");
    }
    else if (count == 16 && l == 4)
    {
        printf("VISA\n");
    }
    else if (count == 16)
    {
        printf("MASTERCARD\n");
    }

}
