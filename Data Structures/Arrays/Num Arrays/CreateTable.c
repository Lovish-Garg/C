#include <stdio.h>

int main(void)
{
    int num;

    printf("Number: ");
    scanf("%d", &num);// taking input from user that of which table the table should be created

    int upto;// upto which number the table should be created

    printf("Upto Number: ");
    scanf("%d", &upto);

    printf("\n");
    for (int i = 0; i < upto; i++)
    {
        printf("%d * %d = %d\n", num, i, num * i);// printing actual number then i and then their product
    }
    
    return 0;
}
