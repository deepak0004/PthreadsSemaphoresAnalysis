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

#include "14036_counter1_nonsafe.c"

int max = 1e9;

clock_t start, end;
double cpu_time_used;
int main()
{                     
    pthread_t p1;
    printf("main: begin [counter = %d] [%x]\n", counter, (unsigned int) &counter);
    
    start = clock();
    Pthread_create(&p1, NULL, funct, "A"); 
   
    Pthread_join(p1, NULL); 
    end = clock();

    printf("main: done\n [counter: %d]\n [should: %d]\n", counter, max);
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf( "%lf\n", cpu_time_used );

    return 0;
}