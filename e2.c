#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

int main(int argc, char const *argv[])
{
	srand(time(NULL));

	int thread_count = strtol(argv[1], NULL, 10);

	int number_in_circle = 0;
	int number_of_tosses = 16;

	double pi_estimate;

# pragma omp parallel num_threads(thread_count)
	for (int toss = 0; toss < number_of_tosses ; toss ++) 
	{
		double x = (rand()%201-100)/100.0;
		double y = (rand()%201-100)/100.0;
		double distance_squared = x * x + y * y ;
		#pragma omp critical
		if ( distance_squared <= 1)
		{ 
			//#pragma omp atomic
			number_in_circle+=1;
		}
		printf("Num Thread: %d\t x: %1.2f\t y: %1.2f\t distance_squared: %1.2f\t number_in_circle: %d\n",
			omp_get_thread_num(), x,y,distance_squared,number_in_circle);

	}

	pi_estimate = 4*number_in_circle /((double) number_of_tosses );
	printf("valor pi: %1.2f\n", pi_estimate);

	return 0;
}

//gcc -g -Wall -fopenmp e2.c