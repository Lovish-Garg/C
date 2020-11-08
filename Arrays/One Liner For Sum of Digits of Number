#include <stdio.h>

int get_sum(int num);

int main(void)
{
    int num;
    
    printf("Input a number: ");
    scanf("%d", &num);

    printf("The sum of %d digits is %d", num, get_sum(num));
}

int get_sum(int num)
{
    int sum;

/*
  here sum = 0 at first then check if num > 0 and then if num > 0 then sum += num % 10 EG. Num = 312 then num %10 = 2 and then num /= 10 and this continues till the number 
  not becomes zero.
*/

    for (sum = 0; num > 0; sum += num %10, num /= 10); 

    return sum;
}
