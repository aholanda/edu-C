#include <stdio.h>

void troca(int *x, int *y)
{
  int tmp;

  tmp = *x;
  *x = *y;
  *y = tmp;
}

int main(int argc, char **argv)
{
  int a = 3;
  int b = 8;

  troca(&a, &b);

  printf("a=%d, b=%d\n", a, b);

  return 0;

}
