#include <stdio.h>
#include "mythreads.h"
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define display(arr,s,e) for(int i=s; i<=e; i++) cout<<arr[i]<<" ";
#define mset(arr,x) memset(arr,x,sizeof(arr))

#define MOD 1000000007
#define I_MAX 9223372036854775807
#define I_MIN -9223372036854775807
#define epsilon 0.000000000001

#define rep(i,s,e) for(i=s;i<=e;i++)
#define rrep(i,s,e) for(i=s;i>=e;i--)
#define endl "\n"

#define ll long long
#define mid(a,b) ((a)+((b-a)/2))
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

// Useful STL commands:
#define pb push_back
#define mp make_pair

#define f first
#define s second
#define si set<int>
#define vi vector<ll>
#define ii pair<float, float>
#define sii set<ii>
#define vii vector<ii>
#define all(c) c.begin(),c.end()
#define tr(c,it) for(typeof(c.begin()) it=c.begin();it!=c.end();++it)

#define DEBUG
// debugging
#ifdef DEBUG
#define trace1(x)                    cerr << #x << ": " << x << endl;
#define trace2(x, y)                 cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)              cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)           cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)        cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f)     cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#else
#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)
#endif

#include "14036_counter2_safe.c"

int main()
{       
    int mm;
    double tot = 0;             
    max = 1e9;
    clock_t start, end;
    double cpu_time_used;

    int nn;
    scanf("%d", &nn);
   
    switch(nn)
    {
      case 2:  // 2 threads
              for( mm=0; mm<50; mm++ )
              {
                 counter = 0; 
                 
                 printf( "%d\n", mm+1 );   
                 pthread_t p1, p2;
                 printf("main: begin [counter = %d] [%x]\n", counter, (unsigned int) &counter);
                 
                 start = clock();
                 Pthread_create(&p1, NULL, funct, "A"); 
                 Pthread_create(&p2, NULL, funct, "B");

                 Pthread_join(p1, NULL); 
                 Pthread_join(p2, NULL);
                 end = clock();

                 printf("main: done\n [counter: %d]\n [should: %d]\n", counter, max);

                 cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
              //   printf( "%lf\n", cpu_time_used ); 
                 tot += cpu_time_used;
              }
              printf( "%lf\n", tot/50 ); 
              break;


       case 3:  // 3 threads
                tot = 0;
                for( mm=0; mm<50; mm++ )
                {
                   counter = 0; 
                   
                   printf( "%d\n", mm+1 );   
                   pthread_t p1, p2, p3;
                   printf("main: begin [counter = %d] [%x]\n", counter, (unsigned int) &counter);
                  
                   start = clock(); 
                   Pthread_create(&p1, NULL, funct, "A"); 
                   Pthread_create(&p2, NULL, funct, "B");
                   Pthread_create(&p3, NULL, funct, "C");

                   Pthread_join(p1, NULL); 
                   Pthread_join(p2, NULL);
                   Pthread_join(p3, NULL);
                   end = clock();

                   printf("main: done\n [counter: %d]\n [should: %d]\n", counter, max);

                   cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

                   tot += cpu_time_used;
                }
                printf( "%lf\n", tot/50 ); 
                break; 

        
        case 4:  // 4 threads
                tot = 0;
                for( mm=0; mm<50; mm++ )
                {
                   counter = 0; 
                   
                   printf( "%d\n", mm+1 );   
                   pthread_t p1, p2, p3, p4;
                   printf("main: begin [counter = %d] [%x]\n", counter, (unsigned int) &counter);
                   
                   start = clock(); 
                   Pthread_create(&p1, NULL, funct, "A"); 
                   Pthread_create(&p2, NULL, funct, "B");
                   Pthread_create(&p3, NULL, funct, "C");
                   Pthread_create(&p4, NULL, funct, "D");

                   Pthread_join(p1, NULL); 
                   Pthread_join(p2, NULL);
                   Pthread_join(p3, NULL);
                   Pthread_join(p4, NULL);
                   end = clock();

                   printf("main: done\n [counter: %d]\n [should: %d]\n", counter, max);

                   cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

                   tot += cpu_time_used;
                }
                printf( "%lf\n", tot/50 );
                break;  

        
        case 5: // 5 threads
                tot = 0;
                for( mm=0; mm<50; mm++ )
                {
                   counter = 0; 
                   
                   printf( "%d\n", mm+1 );   
                   pthread_t p1, p2, p3, p4, p5;
                   printf("main: begin [counter = %d] [%x]\n", counter, (unsigned int) &counter);
                   
                   start = clock();
                   Pthread_create(&p1, NULL, funct, "A"); 
                   Pthread_create(&p2, NULL, funct, "B");
                   Pthread_create(&p3, NULL, funct, "C");
                   Pthread_create(&p4, NULL, funct, "D");
                   Pthread_create(&p5, NULL, funct, "E");

                   Pthread_join(p1, NULL); 
                   Pthread_join(p2, NULL);
                   Pthread_join(p3, NULL);
                   Pthread_join(p4, NULL);  
                   Pthread_join(p5, NULL);
                   end = clock();

                   printf("main: done\n [counter: %d]\n [should: %d]\n", counter, max);

                   cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

                   tot += cpu_time_used;
                }
                printf( "%lf\n", tot/50 ); 
                break;         


        case 6: // 6 threads
                tot = 0;
                for( mm=0; mm<50; mm++ )
                {
                   counter = 0; 
                  
                   printf( "%d\n", mm+1 );   
                   pthread_t p1, p2, p3, p4, p5, p6;
                   printf("main: begin [counter = %;ld] [%x]\n", counter, (unsigned int) &counter);
                  
                   start = clock(); 
                   Pthread_create(&p1, NULL, funct, "A"); 
                   Pthread_create(&p2, NULL, funct, "B");
                   Pthread_create(&p3, NULL, funct, "C");
                   Pthread_create(&p4, NULL, funct, "D");
                   Pthread_create(&p5, NULL, funct, "E");
                   Pthread_create(&p6, NULL, funct, "F");

                   Pthread_join(p1, NULL); 
                   Pthread_join(p2, NULL);
                   Pthread_join(p3, NULL);
                   Pthread_join(p4, NULL);
                   Pthread_join(p5, NULL);
                   Pthread_join(p6, NULL);
                   end = clock();

                   printf("main: done\n [counter: %d]\n [should: %d]\n", counter, max);

                   cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

                   tot += cpu_time_used;
                }
                printf( "%lf\n", tot/50 ); 
                break;

                    
         case 7: // 7 threads
                tot = 0;
                for( mm=0; mm<50; mm++ )
                {
                   counter = 0; 

                   printf( "%d\n", mm+1 );   
                   pthread_t p1, p2, p3, p4, p5, p6, p7;

                   printf("main: begin [counter = %d] [%x]\n", counter, (unsigned int) &counter);
                   
                   start = clock();  
                   Pthread_create(&p1, NULL, funct, "A"); 
                   Pthread_create(&p2, NULL, funct, "B");
                   Pthread_create(&p3, NULL, funct, "C");
                   Pthread_create(&p4, NULL, funct, "D");
                   Pthread_create(&p5, NULL, funct, "E");
                   Pthread_create(&p6, NULL, funct, "F");
                   Pthread_create(&p7, NULL, funct, "G");

                   Pthread_join(p1, NULL); 
                   Pthread_join(p2, NULL);
                   Pthread_join(p3, NULL);
                   Pthread_join(p4, NULL);
                   Pthread_join(p5, NULL);
                   Pthread_join(p6, NULL);
                   Pthread_join(p7, NULL);
                   end = clock();

                   printf("main: done\n [counter: %d]\n [should: %d]\n", counter, max);

                   cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

                   tot += cpu_time_used;
                }
                printf( "%lf\n", tot/50 ); 
                break;

        case 8: // 8 threads
                tot = 0;
                for( mm=0; mm<50; mm++ )
                {
                   counter = 0; 
                   printf( "%d\n", mm+1 );   
                   pthread_t p1, p2, p3, p4, p5, p6, p7, p8;
                   printf("main: begin [counter = %d] [%x]\n", counter, (unsigned int) &counter);
                  
                   start = clock();
                   Pthread_create(&p1, NULL, funct, "A"); 
                   Pthread_create(&p2, NULL, funct, "B");
                   Pthread_create(&p3, NULL, funct, "C");
                   Pthread_create(&p4, NULL, funct, "D");
                   Pthread_create(&p5, NULL, funct, "E");
                   Pthread_create(&p6, NULL, funct, "F");
                   Pthread_create(&p7, NULL, funct, "G");
                   Pthread_create(&p8, NULL, funct, "H");

                   Pthread_join(p1, NULL); 
                   Pthread_join(p2, NULL);
                   Pthread_join(p3, NULL);
                   Pthread_join(p4, NULL);
                   Pthread_join(p5, NULL);
                   Pthread_join(p6, NULL);
                   Pthread_join(p7, NULL);
                   Pthread_join(p8, NULL);
                   end = clock();

                   printf("main: done\n [counter: %d]\n [should: %d]\n", counter, max);

                   cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

                   tot += cpu_time_used;
                }
                printf( "%lf\n", tot/50 );    
                break;


        case 9: // 9 threads
                tot = 0;
                for( mm=0; mm<50; mm++ )
                {
                   counter = 0; 
                   printf( "%d\n", mm+1 );   
                   pthread_t p1, p2, p3, p4, p5, p6, p7, p8, p9;
                   printf("main: begin [counter = %d] [%x]\n", counter, (unsigned int) &counter);

                   start = clock();
                   Pthread_create(&p1, NULL, funct, "A"); 
                   Pthread_create(&p2, NULL, funct, "B");
                   Pthread_create(&p3, NULL, funct, "C");
                   Pthread_create(&p4, NULL, funct, "D");
                   Pthread_create(&p5, NULL, funct, "E");
                   Pthread_create(&p6, NULL, funct, "F");
                   Pthread_create(&p7, NULL, funct, "G");
                   Pthread_create(&p8, NULL, funct, "H");
                   Pthread_create(&p9, NULL, funct, "I");

                   // join waits for the threads to finish
                   Pthread_join(p1, NULL); 
                   Pthread_join(p2, NULL);
                   Pthread_join(p3, NULL);
                   Pthread_join(p4, NULL);
                   Pthread_join(p5, NULL);
                   Pthread_join(p6, NULL);
                   Pthread_join(p7, NULL);
                   Pthread_join(p8, NULL);
                   Pthread_join(p9, NULL);
                   end = clock();

                   printf("main: done\n [counter: %d]\n [should: %d]\n", counter, max);

                   cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

                   tot += cpu_time_used;
                }
                printf( "%lf\n", tot/50 ); 
                break;


        case 10: // 10 threads
                tot = 0;
                for( mm=0; mm<50; mm++ )
                {
                   counter = 0; 

                   printf( "%d\n", mm+1 );   
                   
                   pthread_t p1, p2, p3, p4, p5, p6, p7, p8, p9, p10;
                   printf("main: begin [counter = %d] [%x]\n", counter, (unsigned int) &counter);
                  
                   start = clock(); 
                   Pthread_create(&p1, NULL, funct, "A"); 
                   Pthread_create(&p2, NULL, funct, "B");
                   Pthread_create(&p3, NULL, funct, "C");
                   Pthread_create(&p4, NULL, funct, "D");
                   Pthread_create(&p5, NULL, funct, "E");
                   Pthread_create(&p6, NULL, funct, "F");
                   Pthread_create(&p7, NULL, funct, "G");
                   Pthread_create(&p8, NULL, funct, "H");
                   Pthread_create(&p9, NULL, funct, "I");
                   Pthread_create(&p10, NULL, funct, "J");

                   // join waits for the threads to finish
                   Pthread_join(p1, NULL); 
                   Pthread_join(p2, NULL);
                   Pthread_join(p3, NULL);
                   Pthread_join(p4, NULL);
                   Pthread_join(p5, NULL);
                   Pthread_join(p6, NULL);
                   Pthread_join(p7, NULL);
                   Pthread_join(p8, NULL);
                   Pthread_join(p9, NULL);
                   Pthread_join(p10, NULL);
                   end = clock();

                   printf("main: done\n [counter: %d]\n [should: %d]\n", counter, max);

                   cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

                   tot += cpu_time_used;
                }

                printf( "%lf\n", tot/50 );              
                break;   
    } 

    return 0;
}