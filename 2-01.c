#include <stdio.h>
#include <limits.h>

/* find ranges of integer types, check against library values */
int main()
{
    
    char maxc = 0;
    for(int i=0; i<sizeof(maxc)*8-1; i++)
        maxc += 1<<i;
    printf("signed char range - library: %d -> %d, calculated: %d -> %d\n",
        SCHAR_MIN, SCHAR_MAX, -maxc-1, maxc);
    
    short maxs = 0;
    for(int i=0; i<sizeof(maxs)*8-1; i++)
        maxs += 1<<i;
    printf("signed short range - library: %d -> %d, calculated: %d -> %d\n",
        SHRT_MIN, SHRT_MAX, -maxs-1, maxs);
    
    int maxi = 0;
    for(int i=0; i<sizeof(maxi)*8-1; i++)
        maxi += 1<<i;
    printf("signed int range - library: %d -> %d, calculated: %d -> %d\n",
        INT_MIN, INT_MAX, -maxi-1, maxi);
    
    long maxl = 0;
    for(int i=0; i<sizeof(maxl)*8-1; i++)
        maxl += 1L<<i;
    printf("signed long range - library: %ld -> %ld, calculated: %ld -> %ld\n",
        LONG_MIN, LONG_MAX, -maxl-1, maxl);
    
    long long maxll = 0;
    for(int i=0; i<sizeof(maxll)*8-1; i++)
        maxll += 1LL<<i;
    printf("signed long long range - library: %lld -> %lld, calculated: %lld -> %lld\n",
        LLONG_MIN, LLONG_MAX, -maxll-1, maxll);
    
    putchar('\n');
    
    unsigned char umaxc = 0;
    for(int i=0; i<sizeof(umaxc)*8; i++)
        umaxc += 1<<i;
    printf("unsigned char range - library: 0 -> %u, calculated: 0 -> %u\n",
        UCHAR_MAX, umaxc);

    unsigned short umaxs = 0;
    for(int i=0; i<sizeof(umaxs)*8; i++)
        umaxs += 1<<i;
    printf("unsigned short range - library: 0 -> %u, calculated: 0 -> %u\n",
        USHRT_MAX, umaxs);
    
    unsigned int umaxi = 0;
    for(int i=0; i<sizeof(umaxi)*8; i++)
        umaxi += 1<<i;
    printf("unsigned int range - library: 0 -> %u, calculated: 0 -> %u\n",
        UINT_MAX, umaxi);
    
    unsigned long umaxl = 0;
    for(int i=0; i<sizeof(umaxl)*8; i++)
        umaxl += 1UL<<i;
    printf("unsigned long range - library: 0 -> %lu, calculated: 0 -> %lu\n",
        ULONG_MAX, umaxl);
    
    unsigned long long umaxll = 0;
    for(int i=0; i<sizeof(umaxll)*8; i++)
        umaxll += 1ULL<<i;
    printf("unsigned long long range - library: 0 -> %llu, calculated: 0 -> %llu\n",
        ULLONG_MAX, umaxll);
    return 0;
}
