#include <stdio.h>
#include <stdlib.h> // for atof()
#include <ctype.h> //for getch()
#include <math.h>
#include <string.h>

#define MAXOP 100 //max size of operand or operator
#define NUMBER '0' //signal that a number was found
#define FUNCTION '&' //function found
#define VAR 'A' //variable found
#define SAVE '>' //save to variable

int getop(char[]);
void push(double);
double pop(void);
void mt(void);
void func(char*);

/* reverse polish calculator
 * supports: floating point, negative numbers
 * operators: + - * / %
 * commands:
 *      # -> duplicate top element
 *         -> #\n prints the top of the stack without popping
 *      _ -> swap top 2 stack elements
 *      $ -> clear the stack
 *      & -> function follows
 * functions:
 *      &cos (x)
 *      &sin (x)
 *      &exp (x)
 *      &log (x)
 *      &pow (x)
 *      &sqrt (x)
 * variables:
 *      A - Z
 *      access by using the name normally
 *      save by >X
 *      @ = ANS (last printed var)
 * */
int main() {
        int type;
        double op1;
        double op2;
        char s[MAXOP]; //input string
        double var['Z' - 'A' + 1] = {}; //variables
        double ans = 0;

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
                        case '#':
                                op2 = pop();
                                push( op2 );
                                push( op2 );
                                break;
                        case '_':
                                op2 = pop();
                                op1 = pop();
                                push(op2);
                                push(op1);
                                break;
                        case '$':
                                mt();
                                break;
                        case '@':
                                push( ans );
                                break;
                        case FUNCTION:
                                func(s);
                                break;
                        case VAR:
                                push( var[ s[0] - 'A'] );
                                break;
                        case SAVE:
                                op2 = pop();
                                push(op2);
                                var[ s[0] - 'A' ] = op2;
                                break;
                        case '\n':
                                printf("\t%.8g\n", ans = pop());
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

/* empty the stack */
void mt(void) {
        sp = 0;
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
        int i, c, ret;

        while( (s[0] = c = getch()) == ' ' || c == '\t' ); //skip spaces
        
        s[1] = '\0';

        if( c == '>' ) {
                if( !isupper(s[0] = c = getch()) ) {
                        printf("Unknown variable: %c\n", s[0]);
                        ungetch(c);
                        return 0;
                }
                return SAVE;
        }

        if( isupper(c) )
                return VAR;
 
        if( !isdigit(c) && c != '.' && c != '-' && c != '&')
                return c; //not a number

        i = 0;

        if( c == '-' ) {
                if( !isdigit( s[++i] = c = getch() ) ) { //if char after - is not a number, it is a minus operator
                        ungetch(c);                       //else, it is already in the stack from the space skipper loop
                        return '-';
                }
        }
       
        if( isdigit(c) ){
                ret = NUMBER;
                while( isdigit( s[++i] = c = getch() ) ); //collect integer part
        
                if( c == '.' )
                        while( isdigit( s[++i] = c = getch() ) ); //collect fract part
       
                s[i] = '\0';
        }

        if( c == '&' ) {
                ret = FUNCTION;
                while ( islower(c = getch()) )
                        s[++i] = c;
                s[++i] = '\0';
        }
        if( c != EOF )
                ungetch(c);
        return ret;
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

/* execute math function indicated by string in str */
void func(char *str) {
        if(!strcmp(str, "&cos"))
                push( cos( pop() ) );
        else if(!strcmp(str, "&sin"))
                push( sin( pop() ) );
        else if(!strcmp(str, "&exp"))
                push( exp( pop() ) );
        else if(!strcmp(str, "&log"))
                push( log( pop() ) );
        else if(!strcmp(str, "&pow")) {
                double op2 = pop();
                push( pow( pop(), op2 ) );
        }
        else if(!strcmp(str, "&sqrt"))
                push( sqrt( pop() ) );
        else
                printf("error: unknown function: %s\n", str);
}
