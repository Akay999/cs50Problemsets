#include <stdio.h>
#include <cs50.h>

int collatz(int n);


int main(void)
{
    int numb;
    do
    {
        numb = get_int("specify any positive integer\n");
    }
    while (numb < 0);
    printf("the number steps required to get to 1 is %i\n", collatz(numb));

}

int collatz(int n)
{
    if (n == 1)
    {
        return 0;
    }
    else if ((n%2) == 0)
    {
        return collatz(n/2) + 1;
    }
    else
    {
        return collatz((3*n)+1) + 1;
    }
}