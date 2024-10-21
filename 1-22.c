#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define LONGLINE 80
/* fold - fold lines longer than LONGLINE
 * fold at last whitespace before the limit
 * if there is no whitespace before the limit, */

void printbuf( char *buf, size_t bufend ) {
        for( size_t i = 0; i<=bufend; i++ )
                putchar(buf[i]);
}

void popbuf( char *buf, size_t bufnum, size_t bufsize, size_t* indx ) {
        memmove( buf, &buf[bufnum+1], (bufsize - bufnum - 1)* sizeof(char) );
        *indx = bufsize - bufnum - 1;
}

int main()
{
        char buffer[LONGLINE] = {};
        size_t i = 0;
        size_t blankpos = 0;
        char c = 0;

        while( (c = getchar()) != EOF ) {
                buffer[i] = c;
                
                if( isspace(c) )
                        blankpos = i;
                if( c == '\n' ) {
                        printbuf(buffer, i);
                        i=0;
                        blankpos=0;
                        continue;
                }
                if( i == LONGLINE - 1 ) {
                        if( blankpos == 0 ) {
                                printbuf( buffer, i-2 );
                                popbuf( buffer, i-2, LONGLINE, &i);
                                putchar( '-' );
                                putchar( '\n' );
                        }
                        else{
                                buffer[blankpos] = '\n';
                                printbuf( buffer, blankpos );
                                popbuf( buffer, blankpos, LONGLINE, &i);
                                blankpos = 0;
                        }
                        continue;
                }
                i++;
        }

        return 0;
}
