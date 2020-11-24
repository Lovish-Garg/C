#include <stdio.h>

int main(void)
{
  int n;

  printf("Input size for right-aligned half-pyramid: ");
  scanf("%d", &n);

  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (j >= n - i)
      {
        printf("*");
      }
      else
      {
        printf(" ");
      }
    }
    printf("\n");
  }
  return 0;
}
