#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>


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
    qs(list,0,n-1);
}

int main(int argc, char const *argv[])
{

    return 0;
}