#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>
#include <time.h>
#include <unistd.h>

#define N 20

int mem[N];


int main(int argc, char const *argv[])
{
	srand(time(NULL));

	int thread_count=8;

	int pos_prod=0;
	int pos_cons=0;

	# pragma omp parallel num_threads(thread_count)
	for (int t = 0; t < thread_count; ++t)
	{
		sleep(omp_get_thread_num());
		if (omp_get_thread_num()%2==0)
		{
			while(1)
			{
				if(mem[pos_prod]==0)
				{
					mem[pos_prod]=rand()%100+1;
					printf("id:%d produce %d en posicion %d\n",omp_get_thread_num(), mem[pos_prod], pos_prod+1);
					#pragma omp critical
					pos_prod=(pos_prod+1)%N;

					printf("Elementos al producir: ");
					for (int i = 0; i < N; ++i)
						printf("%d ", mem[i]);
					printf("\n\n");
					sleep(1);
				}
				else printf("Productor id:%d en espera\n\n",omp_get_thread_num());
				sleep(1);
			}
		}
		else
		{
			while(1)
			{
				if(mem[pos_cons]!=0)
				{
					mem[pos_cons]=0;
					# pragma omp critical
					pos_cons=(pos_cons+1)%N;

					printf("id:%d consume en posicion %d\n",omp_get_thread_num(), pos_cons+1);
					
					printf("id:%d Elementos al consumir: ",omp_get_thread_num());
					for (int i = 0; i < N; ++i)
						printf("%d ", mem[i]);
					printf("\n\n");
					sleep(2);
				}
				else printf("Consumidor id:%d en espera\n\n",omp_get_thread_num());
				sleep(2);
			}
		}
	}	

	return 0;
}