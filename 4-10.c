#include <stdio.h>
#include <stdlib.h> // for atof()
#include <ctype.h> //for getch()
#include <math.h>
#include <string.h>

#define MAXOP 100 //max size of operand or operator
#define NUMBER '0' //signal that a number was found
#define FUNCTION '&' //function found
#define VAR 'A'
#define SAVE '>'

int getop(char*, char*, int*, int);
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
 *      &pow (x, y)
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

        int j = 0;
        size_t buflen = 0;
        char *line = 0;
        int len = 0;
        len = getline( &line, (size_t*)&buflen, stdin);

        while( (type = getop(s, line, &j, buflen)) != EOF && len != -1) {
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
                                len = getline ((char**)&line, (size_t*)&buflen, stdin);
                                j=0;
                                break;
                        default:
                                printf("error: unknown command %s\n", s);
                                break;
                }
        }
        free(line);
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


/* getop: get next operator or numeric operand */
int getop(char s[], char line[], int* j, int end) {
        int i, c, ret;
        
        while( (s[0] = c = line[(*j)++]) == ' ' || c == '\t' ); //skip spaces
        
        s[1] = '\0';

        if( c == '>' ) {
                if( !isupper(s[0] = c = line[(*j)++]) ) {
                        printf("Unknown variable: %c\n", s[0]);
                        (*j)--;
                        return 0;
                }
                return SAVE;
        }

        if( isupper(c) )
                return VAR;
 
        if( !isdigit(c) && c != '.' && c != '-' && c != '&' && *j < end)
                return c; //not a number

        i = 0;

        if( c == '-' ) {
                if( !isdigit( s[++i] = c = line[(*j)++] ) ) { //if char after - is not a number, it is a minus operator
                        (*j)--;                       //else, it is already in the stack from the space skipper loop
                        return '-';
                }
        }
       
        if( isdigit(c) ){
                ret = NUMBER;
                while( isdigit( s[++i] = c = line[(*j)++] ) ); //collect integer part
        
                if( c == '.' )
                        while( isdigit( s[++i] = c = line[(*j)++] ) ); //collect fract part
       
                s[i] = '\0';
        }

        if( c == '&' ) {
                ret = FUNCTION;
                while ( islower(c = line[(*j)++]) )
                        s[++i] = c;
                (*j)--;
                s[++i] = '\0';
        }

        
        if( *j >= end )
                ret = EOF;
        return ret;
}

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
