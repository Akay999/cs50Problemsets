#include <stdio.h>
#include <cs50.h>

int fact(int n);

int main(void)
{
    int numb;

    do
    {
        numb = get_int("specify any positive integer\n");
    }
    while (numb < 0);

    printf("the factorial of %i is %i\n",numb ,fact(numb));
}

int fact (int n)
{
    if (n == 1)
       return 1;
    else
       return n*fact(n-1);
}