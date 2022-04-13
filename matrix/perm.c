#include <stdio.h>
#include <stdlib.h>
/**
   FILENAME: magic.c
   AUTHOR: Adriano J. Holanda
   LICENSE: Public Domain
   
   This program implements a function to verify if a matrix (square)
   is of permutation.
   
   Permutation property: 
   sum of each line = sum of each column = 1
*/

int mat_elem(int *mat[], int ncols, int row, int col) {
	return  (int)*(((int*)mat + row*ncols) + col);
}

int is_perm(int N, int *m[])
{
	int i, j;
	int *sum; /* array to store the sum of lines, columns and diagonals */
	
	if (m == NULL || N <=0)
		return 0;

	sum = calloc(N+N, sizeof(int));

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++) {
			/* sum of each  line */
			sum[i] += mat_elem(m, N, i, j);

			/* sum of each column */
			sum[N+j] += mat_elem(m, N, i, j);

		}

	for (i = 0; i < N+N; i++)
		if (sum[i] != 1)
			return 0;

	free(sum);

	return 1;
}
int main(int argc, char *argv[])
{
	enum {N=3};
        /* matrix to test */
	int m[N][N] = {{0,1,0}, 
		       {1,0,0}, 
		       {0,0,1}};
	int i, j, is_mag;
	
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) 
			printf("%d\t", m[i][j]);
		printf("\n");
	}	
	is_mag = is_perm(N, (int **)m);

	printf("The matrix is ");
	if (is_mag)
		printf("of permutation!\n");
	else
		printf("not of permutation!\n");
	
	return 0;
}
