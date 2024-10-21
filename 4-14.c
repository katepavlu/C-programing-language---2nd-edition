#include <stdio.h>
#include <string.h>

#define swap(t, x, y)  t temp = x; x = y; y = temp

int main() {
    int x = 0;
    int y = 1;

    swap(int, x, y);
    
    printf("%d", x);

    return 0;
}
