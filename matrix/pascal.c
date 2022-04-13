#include <stdio.h>
#include <stdlib.h>
/**
   FILENAME: pascal.c
   AUTHOR: Adriano J. Holanda
   LICENSE: Public Domain
   
   Program to generate Pascal triangle.
*/
int main(int argc, char *argv[])
{
	int i, j, N;
	int **pas;

	printf("Qual o valor de N: ");
	scanf("%d", &N);
	
	pas = (int**)calloc(N, sizeof(int*));
	for (i = 0; i < N; i++)
		pas[i] = (int*)calloc(N, sizeof(int));
	
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++) {
			if (i >= j) {
				if (j == 0)
					pas[i][j] = 1;
				else
					pas[i][j] = pas[i-1][j] + pas[i-1][j-1];
			}
		}
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) 
			printf("%d\t", pas[i][j]);
		printf("\n");
	}
	free(pas);

	return 0;
}
