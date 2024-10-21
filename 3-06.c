#include <stdio.h>
#include <string.h>
#include <limits.h>

/* reverse string in place */
void reverse(char s[]) {
    int i,j;
    char tmp = 0;
    for(i=0, j=strlen(s) - 1; i<j; i++, j--) {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}

/* itoa - integer to char array 
 * version with minf - minimal field width */
void itoa(int n, char s[], int minf) {
    int i, sign;
    if( (sign = n) < 0 ) //record sign
        n = -n; // make n positive
        
    i=0;

    if(n < 0) { //if n=-n is still negative, we have INT_MIN
        s[i++] = -(n%10) + '0'; //last digit would be negative
        n /= -10; //the reduced number will be positive
    }
    do{ //generate digits in reverse order
        s[i++] = n % 10 + '0'; //get next digit
    } while( (n /= 10) > 0 ); //delete last digit

    if(sign<0)
        s[i++] = '-';
    while(i < minf) {
        s[i++] = ' ';
    }
    s[i] = '\0';
    reverse(s);
}


int main()
{
    char str[200] = {};
    
    itoa(-2, str, 3);
    
    printf("%s\n", str);

    return 0;
}
