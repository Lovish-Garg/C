#include <stdio.h>

int main(void)
{
    int x, y;

    printf("Input value for x: ");
    scanf("%d", &x);

    printf("Input value for y : ");
    scanf("%d", &y);
/*
  So here by taking an example such as x = 5, y = 10;
  x = x + y; So x = 15
  y = x - y; So y = 5
  x = x - y; So x = 10
    
  And swapping is done without using any temp variable. 
*/

    x = x + y; 
    y = x - y;
    x = x - y;

    printf("\nAfter swapping->\n x = %d and y = %d\n", x, y);
}
