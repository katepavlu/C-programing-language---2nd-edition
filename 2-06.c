#include <stdio.h>

/* return x with n bits beginning at position p set at the rightmost n bits of y */
unsigned int setbits(unsigned int x, unsigned int p, unsigned int n, unsigned int y) {
    unsigned int mask = 0;
    
    for(int i = 0; i<n; i++) {
        mask += 1<<i;
    }
    
    x = x & ~(mask << ( sizeof(x)*8 - n - p) ); //first zero out the region
    return x | ( (y & mask) << ( sizeof(x)*8 - n - p) );
}

int main()
{
    unsigned int x = 0;
    printf("Hello World%u\n", setbits(x, 29, 3, 0xfa));

    return 0;
}
