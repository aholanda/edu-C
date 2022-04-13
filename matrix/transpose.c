#include <stdio.h>
#include <stdlib.h>
/**
   FILENAME: magic.c
   AUTHOR: Adriano J. Holanda
   LICENSE: Public Domain
   
   This program implements a function to print the transpose of a
   matrix.
*/

int mat_elem(int *mat[], int ncols, int row, int col) {
	return  (int)*(((int*)mat + row*ncols) + col);
}

void print_transpose(int nrows, int ncols, int *m[])
{
	int i, j;
	
	if (m == NULL || nrows<=0 || ncols <=0)
		return;

	for (i = 0; i < ncols; i++) {
		for (j = 0; j < nrows; j++) 
			printf("%d\t", mat_elem(m, ncols, j, i));
		printf("\n");
	}
}
int main(int argc, char *argv[])
{
	enum {ncols=2,nrows=3};
        /* matrix to test */
	int m[nrows][ncols] = {{1,3}, 
			       {2,5}, 
			       {8,-1}};
	int i, j;
	
	for (i = 0; i < nrows; i++) {
		for (j = 0; j < ncols; j++) 
			printf("%d\t", m[i][j]);
		printf("\n");
	}	
	printf("The transpose is \n");

	print_transpose(nrows, ncols, (int **)m);
	
	return 0;
}
