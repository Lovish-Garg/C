/*
    A Strong number is a number whose individual digits factorial is equal to number itself
*/
#include <stdio.h>

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

    while (num)// while (num != 0)
    {
        int rev = num % 10;
        factorial += Factorial(rev);// getting factorial of the individual number
        num /= 10;// removing the last digit of the number 
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
