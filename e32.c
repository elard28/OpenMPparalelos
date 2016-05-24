#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>
#include <time.h>

#define N 100

void qsp(int A[],int izq, int der )
{ 
int i, j, pivot , tmp; 
i = izq; 
j = der; 
pivot = A[(izq+der)/2]; 
    do{ 
        while( (A[i] < pivot) && (j <= der) )
            i++;
        while( (pivot < A[j]) && (j > izq) )
            j--;
        if( i <= j )
        { 
            tmp = A[i]; 
            A[i] = A[j]; 
            A[j] = tmp; 
            i++;  
            j--; 
        }
    }while( i <= j ); 

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            //printf("Lado izquierdo con id=%d\n",omp_get_thread_num());
            if( izq < j ) 
                qsp( A, izq, j );
        } 

        #pragma omp section
        {
            //printf("Lado derecho con id= %d\n",omp_get_thread_num());
            if( i < der ) 
                qsp( A, i, der ); 
        }
    }
}

void qs(int A[],int izq, int der )
{ 
int i, j, pivot , tmp; 
i = izq; 
j = der; 
pivot = A[(izq+der)/2]; 
    do{ 
        while( (A[i] < pivot) && (j <= der) )
            i++;
        while( (pivot < A[j]) && (j > izq) )
            j--;
        if( i <= j )
        { 
            tmp = A[i]; 
            A[i] = A[j]; 
            A[j] = tmp; 
            i++;  
            j--; 
        }
    }while( i <= j ); 

   
    if( izq < j ) 
        qs( A, izq, j );
        
    if( i < der ) 
        qs( A, i, der ); 
}

void quicksort(int list[],int n)
{
    qsp(list,0,n-1);
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

    quicksort(v,N);

    for (int i = 0; i < N; ++i)
        printf("%d ", v[i]);
    printf("\n\n");

    return 0;
}