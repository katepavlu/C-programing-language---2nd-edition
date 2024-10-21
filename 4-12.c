#include <stdio.h>
#include <limits.h>

void itoa(int n, char* arr, int* indx) {
    if( n < 0 ) {
        arr[(*indx)++] = '-';
        n = -n;
    }
    if( n / 10 > 0 )
        itoa( n/10, arr, indx);
    else if( n / 10 < 0)
        itoa( n/-10, arr, indx); //INT_MIN
    arr[(*indx)++] = ( (n%10>0? n%10: -(n%10)) + '0');
}

int main()
{
    char str[100] = {};
    
    int i = 0;
    itoa(INT_MAX, str, &i);
    printf("%s", str);

    return 0;
}
