#include <stdio.h>

int main(void)
{

  int n;

  printf("Input size of pyramid: ");
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
  return 0;
}

