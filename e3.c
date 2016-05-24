#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>
#include <time.h>

#define N 10000

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
	int* temp = malloc ( n *sizeof(int));

#pragma omp parallel for num_threads(nthreads)
	for (int i = 0; i < n; i ++) 
	{
		int count = 0;
		for (int j = 0; j < n; j ++)
		{
			if (a[j] < a[i])
				count ++;
			else if (a[j] == a[i] && j < i)
				count++;
		}
		temp[count] = a[i];
	}
	memcpy (a , temp , n *sizeof(int));
	free (temp);
}

int main(int argc, char const *argv[])
{
	
	//int v[10]={3,6,5,9,2,4,1,9,7,0};

	srand(time(NULL));
    int v[N];
    for (int i = 0; i < N; ++i)
        v[i]=rand()%100000;

    for (int i = 0; i < N; ++i)
        printf("%d ", v[i]);
    printf("\n\n");

	Count_sort_parallel(v,N,8);
    //Count_sort(v,N);

	for (int i = 0; i < N; ++i)
		printf("%d ", v[i]);
	printf("\n\n");

	return 0;
}