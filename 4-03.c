#include <stdio.h>
#include <stdlib.h> // for atof()
#include <ctype.h> //for getch()
#include <math.h>

#define MAXOP 100 //max size of operand or operator
#define NUMBER '0' //signal that a number was found

int getop(char[]);
void push(double);
double pop(void);

/* reverse polish calculator
 * now with negative numbers 
 * and floating point modulo support */
int main() {
        int type;
        double op1;
        double op2;
        char s[MAXOP]; //input string

        while( (type = getop(s)) != EOF ) {
                switch( type ) {
                        case NUMBER:
                                push(atof(s));
                                break;
                        case '+':
                                push( pop() + pop() );
                                break;
                        case '*':
                                push( pop() * pop() );
                                break;
                        case '-':
                                op2 = pop();
                                push( pop() - op2 );
                                break;
                        case '/':
                                op2 = pop();
                                if( op2 != 0.0 )
                                        push( pop() / op2 );
                                else
                                        printf("error: zero divisor\n");
                                break;
                        case '%': 
                                op2 = fabs(pop());
                                op1 = pop();
                                
                                double mod  = fabs(op1);
                                while(mod >= op2)
                                        mod -= op2;

                                push( (op1<0)? -mod: mod);
                                break;
                        case '\n':
                                printf("\t%.8g\n", pop());
                                break;
                        default:
                                printf("error: unknown command %s\n", s);
                                break;
                }
        }
        return 0;
}

#define MAXVAL 100 // maximum depth of value stack

int sp = 0; // next free stack position
double val[MAXVAL]; // value stack

/* push f onto value stack */
void push(double f) {
        if( sp < MAXVAL )
                val[sp++] = f;
        else
                printf("error: stack full, can't push %g\n", f);
}

/* pop and return top of value stack */
double pop(void) {
        if( sp > 0 )
                return val[--sp];
        else{
                printf("error: stack empty\n");
                return 0.0;
        }
}

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[]) {
        int i, c;

        while( (s[0] = c = getch()) == ' ' || c == '\t' ); //skip spaces
        
        s[1] = '\0';

        if( !isdigit(c) && c != '.' && c != '-' )
                return c; //not a number

        i = 0;

        if( c == '-' ) {
                if( !isdigit( s[++i] = c = getch() ) ) { //if char after - is not a number, it is a minus operator
                        ungetch(c);                       //else, it is already in the stack from the space skipper loop
                        return '-';
                }
        }
        
        if( isdigit(c) )
                while( isdigit( s[++i] = c = getch() ) ); //collect integer part

        if( c == '.' )
                while( isdigit( s[++i] = c = getch() ) ); //collect fract part

        s[i] = '\0';
        if( c != EOF )
                ungetch(c);
        return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE]; //buffer for (un)getch()
int bufp = 0; //buffer pointer - next free position

/* buffered getchar */
int getch(void) {
        return (bufp>0)? buf[--bufp]: getchar();
}

/* return char to buffer */
void ungetch(int c) {
        if( bufp >= BUFSIZE )
                printf("ungetch: stack full, too many chars\n");
        else
                buf[bufp++] = c;
}
