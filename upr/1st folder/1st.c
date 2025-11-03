#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  //1

  int a, b;
  scanf(" %d", &a);
  scanf(" %d", &b);
  printf("Perimetura e: %d\n", a * b);

  //2

  double d;
  scanf("%lf",&d);
  printf("Perimetura e: %lf\n", 2 * 3.14 * d);

}