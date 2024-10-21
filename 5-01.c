#include <stdio.h>
#include <string.h>

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getint:  get next integer from input into *pn */
int getint(int *pn)
{
    int c, sign;

    while (isspace(c = getch())); /* skip white space */
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);    /* it′s not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    if(!isdigit(c)) {
        ungetch(c);
        return 0;
    }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

int main() {
    int in = 10;
    
    getint(&in);
    
    printf("%d", in);

    return 0;
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
        else if(c != EOF) //do not put EOF back - prevent terminating other processes that use the buffer
                buf[bufp++] = c;    
}
