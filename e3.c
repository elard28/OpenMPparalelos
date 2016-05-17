#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>

void Count_sort(int a[], int n ) 
{
	int i, j, count;
	int* temp = malloc ( n *sizeof(int));
	for ( i = 0; i < n; i ++) 
	{
		count = 0;
		for (j = 0; j < n; j ++)
			if (a[j] < a[i])
				count ++;
			else if (a[j] == a[i] && j < i)
				count++;
		temp[count] = a[i];
	}
	memcpy (a , temp , n *sizeof(int));
	free (temp);
}

void Count_sort_parallel(int a[], int n ,int nthreads) 
{
	int i, j, count;
	int* temp = malloc ( n *sizeof(int));

#pragma omp parallel num_threads(nthreads)
	for ( i = 0; i < n; i ++) 
	{
		count = 0;
		for (j = 0; j < n; j ++)
			if (a[j] < a[i])
				count ++;
			else if (a[j] == a[i] && j < i)
				count++;
		temp[count] = a[i];
	}
#pragma omp critical
	memcpy (a , temp , n *sizeof(int));
	free (temp);
}

int main(int argc, char const *argv[])
{
	
	int v[10]={3,6,5,9,2,4,1,9,7,0};

	Count_sort_parallel(v,10,8);

	for (int i = 0; i < 10; ++i)
		printf("%d ", v[i]);
	printf("\n");

	return 0;
}