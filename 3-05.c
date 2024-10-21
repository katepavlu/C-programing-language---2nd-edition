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

/* itob - integer to char array
 * converts number n to printable string 
 * in base b */
void itob(int n, char s[], int b) {
    int i, sign;
    char digb = 0;
    if( (sign = n) < 0 ) //record sign
        n = -n; // make n positive
        
    i=0;

    if(n < 0) { //if n=-n is still negative, we have INT_MIN
        digb = ( -(n%b) < 10 ) ? '0' : 'a'; 
        s[i++] = -(n%b) + digb; //last digit would be negative

        n /= -b; //the reduced number will be positive
    }
    do{ //generate digits in reverse order
        digb = ( -(n%b) < 10 ) ? '0' : 'a'; 
        s[i++] = n % b + digb; //get next digit
    } while( (n /= b) > 0 ); //delete last digit

    if(sign<0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}


int main()
{
    char str[200] = {};
    
    itob(49, str, 7);
    
    printf("%s\n", str);

    return 0;
}
