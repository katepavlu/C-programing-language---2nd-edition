#include <stdio.h>    
#include <ctype.h> //for getch()    

int getch(void);
void ungetch(int);

int getch(void);

int main() {   
    ungetch('T');
    ungetch('U');
    
    
    putchar(getch());
    
}    
#define BUFSIZE 100    
    
char buf;

/* buffered getchar */    
int getch(void) {    
        int ret = buf? buf: getchar();
        buf = 0;
        return ret;
}    
    
/* return char to buffer */    
void ungetch(int c) {    
        if(buf)    
                printf("ungetch: warning - buffer overwritten\n");
        buf = c;    
}   
