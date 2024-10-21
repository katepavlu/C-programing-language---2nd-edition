#include <stdio.h>

/* return x rotated right by n position */
unsigned int rightrot(unsigned int x, unsigned int n) {
    while( n / (sizeof(x) * 8) )
        n -= sizeof(x) * 8; //remove loops
    
    return (x >> n) | (x << ( sizeof(x)*8 - n ));
}

int main()
{
    unsigned int x = 0x12345678;
    
    for(unsigned int i=0; i<8; i++)
        printf("%x\n", rightrot(x, 4*i) );

    return 0;
}
