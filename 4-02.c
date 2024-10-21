#include <stdio.h>
#include <ctype.h>

/* atof - convert string to double
 * now with scientific notation support
 * (exponent must be an integer) */
double atof( char s[] ) {
        double val, power;
        int i, sign, esign, exp;
        
        for( i=0; isspace(s[i]); i++ ); //skip whitespace
        
        sign = ( s[i] == '-' )? -1: 1; //record sign

        if( s[i] == '+' || s[i] == '-' )
                i++; //skip sign

        for (val = 0.0; isdigit(s[i]); i++) //record whole part
                val = 10.0 * val + (s[i] - '0');

        if( s[i] == '.' ) //skip decimal period
                i++;

        for (power = 1.0; isdigit(s[i]); i++) { //record fractional part
                val = 10.0 * val + (s[i] - '0');
                power *= 10.0;
        }

        if( s[i] == 'e' || s[i] == 'E') { //skip e/E
                i++;

                esign = ( s[i] == '-' )? -1: 1; //record sign

                if( s[i] == '+' || s[i] == '-' )
                        i++; //skip sign
        
                for (exp = 0; isdigit(s[i]); i++) //record exponent
                        exp = 10 * exp + (s[i] - '0');

                for ( ; exp > 0; exp-- )
                        val = (esign == -1)? val/10.0: val*10.0; //apply exponent
        }

        return sign * val / power;
}

int main() {
        char str[] = "3.1415E-3";
        printf("%f\n", atof(str));
        return 0;
}
