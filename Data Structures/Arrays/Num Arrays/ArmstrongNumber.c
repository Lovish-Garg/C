#include <stdio.h>
#include <math.h>

void isArmstrong(int);

int main(void)
{
    int num;   

    printf("Number: ");
    scanf("%d", &num);

    isArmstrong(num);
}

void isArmstrong(int num)
{
    int factorial = 0, copy = num;

    while (num)
    {
        int rev = num % 10;
        factorial += pow(rev, 3);
        num /= 10;
    }

    if (factorial == copy)
        printf("\n%d is an Armstrong Number\n", copy);
    else
        printf("\n%d isnot an Armstrong Number\n", copy);
}
