#include <stdio.h>

/* return x with n bits beginning at position p inverted 
 * if n starting at p cannot fit inside x, the behaviour is undefined */
unsigned int invert(unsigned int x, unsigned int p, unsigned int n) {
    unsigned int mask = 0;
    
    for(int i = 0; i<n; i++) {
        mask += 1L<<i;
    }
    mask = mask << (sizeof(x)*8 - p - n); 
    
    unsigned int tmp = x & mask;
    
    x = x & ~mask; //first zero out the region
    return x | (~tmp & mask);
}

int main()
{
    unsigned int x = 2;
    printf("Hello World%u\n", invert(x, 29, 3));

    return 0;
}
