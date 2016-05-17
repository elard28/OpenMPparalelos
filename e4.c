#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>

#define N 3

int A[N][N],b[N],x[N];

/*for(row = n-1; row >= 0; row--) 
{
	x[row] = b[row];
	for(col = row+1; col<n ; col++)
		x[row] -= A[row][col]* x[col];
	x[row] /= A [row][row];
}



for(row = 0; row<n; row++)
	x[row] = b[row];
for(col = n-1; col >= 0; col--) 
{
	x[col] /= A[col][col];
	for(row = 0; row < col ; row++)
		x[row] -= A[row][col]*x[col];
}*/

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}