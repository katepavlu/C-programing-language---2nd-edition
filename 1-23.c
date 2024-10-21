#include <stdio.h>

/* pp - the beginning of a C preprocessor
 * removes comments from a C program */
int main() {
        enum {REGULAR, LINECOMMENT, MULCOMMENT, STRING, CHAR} status = REGULAR;
        char c = 0;
        char prev = 0; // for //  /* */ detection
        enum {ON, OFF} escaped = OFF;

        for( ; (c=getchar()) != EOF ; prev = c ) {
                switch(status) {
                        case REGULAR:
                                switch(c) {
                                        case '*':
                                                if(prev == '/')
                                                        status = MULCOMMENT;
                                                continue; //do not putchar() comment start
                                        case '/': 
                                                if(prev == '/')
                                                        status = LINECOMMENT;
                                                continue; //do not putchar() comment start
                                        case '\'':
                                                status = CHAR;
                                                break;
                                        case '\"':
                                                status = STRING;
                                                break;
                                }
                                putchar(c);
                                break;

                        case LINECOMMENT:
                                if(c == '\n') {
                                        status = REGULAR;
                                        putchar(c);
                                }
                                break;

                        case MULCOMMENT:
                                if(c == '/' && prev == '*')
                                        status = REGULAR;
                                break;

                        case STRING:
                                //putchar('S'); //debug
                                putchar(c); //always print strings
                                if(escaped == OFF) {
                                        if(c == '\"') //do not end on escaped \"
                                                status = REGULAR;
                                        else if(c == '\\')
                                                escaped = ON;
                                }
                                else if(escaped == ON) {
                                        escaped = OFF;
                                }
                                break;

                        case CHAR:
                                //putchar('C'); //debug
                                putchar(c); //no length checking yet
                                if(escaped == OFF) {
                                        if(c == '\'') //do not end on escaped \'
                                                status = REGULAR;
                                        else if(c == '\\')
                                                escaped = ON;
                                }
                                else if(escaped == ON) {
                                        escaped = OFF;
                                }
                                break;
                }
        }
}
