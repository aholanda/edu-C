#include <stdio.h>
#include <stdlib.h>
/**
   FILENAME: magic.c
   AUTHOR: Adriano J. Holanda
   LICENSE: Public Domain
   
   This program implements a function to verify if a matrix (square)
   of integers is magic.
   
   Magic property: 
   sum of each line = sum of each column = sum of each diagonal
*/

int mat_elem(int *mat[], int ncols, int row, int col) {
	return  (int)*(((int*)mat + row*ncols) + col);
}

int is_magic(int N, int *m[])
{
int i, j;
int *sum; /* array to store the sum of lines, columns and diagonals */
	
if (m == NULL || N <=0)
	return 0;

sum = calloc(N+N+2, sizeof(int));

for (i = 0; i < N; i++)
	for (j = 0; j < N; j++) {
                /* sum of each  line */
		sum[i] += mat_elem(m, N, i, j);

                /* sum of each column */
		sum[N+j] += mat_elem(m, N, i, j);

                /* sum of main diagonal */
		if (i == j)
			sum[N+N] += mat_elem(m, N, i, j);

                /* sum of secondary diagonal */
		if ((i + j + 1) == N)
			sum[N+N+1] += mat_elem(m, N, i, j);
	}
        /* use transitivity to verify the magic property of sums */
for (i = 1; i < N+N+2; i++)
	if (sum[i] != sum[i-1])
		return 0;

free(sum);

return 1;
}
int main(int argc, char *argv[])
{
	enum {N=3};
        /* matrix to test */
	int m[N][N] = {{2,7,6}, 
		       {9,5,1}, 
		       {4,3,8}};
	int i, j, is_mag;
	
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) 
			printf("%d\t", m[i][j]);
		printf("\n");
	}	
	is_mag = is_magic(N, (int **)&m[0][0]);

	printf("The matrix is ");
	if (is_mag)
		printf("magic!\n");
	else
		printf("not magic!\n");
	
	return 0;
}
