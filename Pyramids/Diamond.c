#include <stdio.h>

int main(void)
{
  int n;

  printf("Input the size of the pyramid: ");
  scanf("%d", &n);

  printf("\n");


  int space = n - 1;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < space; j++)
    {
      printf(" ");
    }
    space--;
    for (int j = -i; j <= i; j++)
    {
      printf("*");
    }
    printf("\n");
  }
  
  int print = n + n - 1;
  /* because we are printing n + n - 1 times example (4 - (4 - 1)) = 7 */
  for (int i = 0; i < n; i++)
  {
    for (int j = i; j > 0; j--)
    {
      printf(" ");
    }

    for (int j = 0; j < print; j++)
    {
      printf("*");
    }
    
    printf("\n");
    print -= 2;
  }
}
