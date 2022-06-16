// A simple program which calulates factorial of a number from standard input.

#include <stdio.h>

int main(void)
{
    int n, i, fact = 1;
    printf("Enter a number: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        fact = fact * i;
    printf("Factorial of %d is %d\n", n, fact);
    return 0;
}
