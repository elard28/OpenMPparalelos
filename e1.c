#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>
#include <time.h>

int data_count=10;
float data[data_count];
int min_meas;
int max_meas;
int bin_count;

int Find_bin()
{
	
}

int main(int argc, char const *argv[])
{
	float bin_maxes[bin_count];
	int bin_counts[bin_count];
	float bin_with=(max_meas-min_meas)/bin_count;

	int b;
	for (b = 0; b < bin_count ; b++)
		bin_maxes[b] = min_meas+bin_width*(b+1);

	for (b = 1; b < bin_count ; b++)
		bin_maxes[b−1] <= measurement < bin_maxes[b];
	min_meas <= measurement < bin_maxes[0];

	for (i=0; i < data_count; i++) 
	{
		int bin = Find_bin (data[i], bin_maxes, bin_count, min_meas);
		bin_counts[bin]++;
	}

	return 0;
}