#include <stdio.h>
#include <stdlib.h>

void isStrong(int);
int Factorial(int);

int main(void)
{
    int num;   

    printf("Number: ");
    scanf("%d", &num);

    isStrong(num);
}

void isStrong(int num)
{
    int factorial = 0, copy = num;

    while (num)
    {
        int rev = num % 10;
        factorial += Factorial(rev);
        num /= 10;
    }

    if (factorial == copy)
        printf("\n%d is a Strong Number\n", copy);
    else
        printf("\n%d isnot a Strong Number\n", copy);
}

int Factorial(int num)
{
    int factorial = 1;
    for (int i = 2; i <= num; i++)
    {
        factorial *= i;
    }

    return factorial;
}
