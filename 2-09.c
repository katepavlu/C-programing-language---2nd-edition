#include <stdio.h>

/* count bits in x that are set to 1 */
unsigned int bitcount(int x) {
    unsigned int i=0;
    while(x) {
        i++;
        x&=(x-1);
    }
    return i;
}

int main() {
    printf("%d\n", bitcount(0xffffffff));

    return 0;
}
