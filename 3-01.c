#include <stdio.h>
#include <time.h>
#define TESTLEN 200000

/* return how long the sorting algo took */
double spedometer(long func())
{
    unsigned long vect[TESTLEN] = {};
    for(unsigned long i = 0; i<TESTLEN; i++)
            vect[i]=i;
    unsigned long tim = clock();
    func( 1, vect, TESTLEN);
    return (double)(clock() - tim)/(double)CLOCKS_PER_SEC;
    
}

/* binary search - single test lin loop
 * returns position of x in v[n]
 * if x is not present, returns -1 */
long bsrch( unsigned long x, unsigned long v[], unsigned long n)
{
    unsigned int low, mid, hi;
    
    low = 0;
    hi = n - 1;
    while( low <= hi )
    {
        mid = ( low + hi ) / 2;
        if( x < v[mid])
            hi = mid - 1;
        else
            low = mid + 1;
    }
    return (mid == x)? (long)mid: -1;
}

/* binary search - two tests in loop
 * returns position of x in v[n]
 * if x is not present, returns -1 */
long binsearch( unsigned long x, unsigned long v[], unsigned long n)
{
    unsigned int low, mid, hi;
    
    low = 0;
    hi = n - 1;
    while( low <= hi )
    {
        mid = ( low + hi ) / 2;
        if( x < v[mid])
            hi = mid - 1;
        else if( x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

/* compare the two searches */
int main()
{
    printf("1 test: %g, 2 tests: %g\n", spedometer(bsrch), spedometer(binsearch));

    return 0;
}
