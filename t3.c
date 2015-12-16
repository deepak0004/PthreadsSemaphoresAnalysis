#include <stdio.h>
#include "mythreads.h"
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include "14036_counter1_nonsafe.c"

int max;
int counter;

int main()
{      
    int mm;
    double tot = 0;             
    max = 1e9;
    clock_t start, end;
    double cpu_time_used;

    for( mm=0; mm<50; mm++ )
    {
       mymain(); 	
       printf( "%d\n", mm+1 );	 
       pthread_t p1, p2;
      
       printf("main: begin [counter = %d] [%x]\n", counter, (unsigned int) &counter);
       
       start = clock();
       Pthread_create(&p1, NULL, funct, "A"); 
       
       Pthread_join(p1, NULL); 
       end = clock();

       printf("main: done\n [counter: %d]\n [should: %d]\n", counter, max);

       cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
       tot += cpu_time_used;
       printf( "%lf\n", cpu_time_used );
    }

    printf( "%lf\n", tot/50 );

    return 0;
}