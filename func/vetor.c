/* Baseado no livro "Expert C: deep secrets" */

int vetor1[100], vetor2[200];

void fun_p(int *pt)
{
  pt = vetor1;
}

void fun_v(int v[])
{
  v = vetor2;
}

int main(int argc, char **argv)
{
  int v[100];

  v = vetor1;
  vetor1 = vetor2; /* FALHA: vetor1 nao é passado como parametro */
  vetor2 = v;
  
  return 0;
}
