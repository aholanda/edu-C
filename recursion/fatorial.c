/* 
   Author: Adriano J. Holanda
   License: Public Domain
   Date: 2016-02-27
   
   Funcoes para calculo do fatorial.
*/

/* Cálculo de n! pelo metodo iterativo */
int Fatorial(int n)
{
  int i, fat = n >= 0 ? 1 : 0;
  
  for (i = 2; i <= n; i++)
    fat = fat * i;
  
  return fat;
}

/* Calculo de n! com recursividade */
int FatorialR(int n)
{
  if (n < 0)
    return 0;
  else if (n == 0 || n == 1)
    return 1;
  else
    return n * FatorialRec(n - 1);
}
