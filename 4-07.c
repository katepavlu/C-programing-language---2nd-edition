#include <stdio.h>    
#include <ctype.h> //for getch()    
#include <string.h>    

extern int bufp; //buffer pointer - next free position 

void ungets(char*);
int getch(void);

int main() {   
    ungets("This is the sentence!");
    
    while(bufp)
        putchar(getch());
    
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
  
/* return string to buffer */    
/* using ungetch() would be slower than using the array directly */    
void ungets(char *s) {    
        size_t i = strlen(s);
        while( i > 0 && bufp < BUFSIZE)    
                buf[bufp++] = s[--i]; //remove the \0 before reading                                                                                                                                                                                                 
}  
