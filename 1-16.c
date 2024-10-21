#include <stdio.h>                                                                                                    
#include <ctype.h>    
    
#define MAXLINE 1000    
    
/* print first 1000 charaacters    
 * of longest line of input     
 * and it's length */    
    
size_t getl(char line[], size_t maxline);    
void copy(char to[], char from[]);    
    
int main() {    
        char line[MAXLINE] = {}; //\n will get replaced by \0    
        char longest[MAXLINE] = {};    
        int temp;    
        size_t len, max;     
    
        max = 0;    
        while( (len = getl(line, MAXLINE)) > 0 ) {
                /* if line is too long to copy, just getchar until \n or EOF */
                if( (len >= MAXLINE - 1) && line[MAXLINE - 2] != '\n' ) {    
                        while( (temp = getchar()) != EOF && temp != '\n')    
                                len ++;     
                        if(temp == '\n')    
                                len++;    
                }    
    
                            
                if( len > max ) {    
                        max = len;    
                        copy(longest, line);    
                }    
        }    
        if(max > 0)    
                printf("%ld: %s\n", max, longest );    
        return 0;    
}    
    
/* read a line into s, return length */    
size_t getl(char s[], size_t lim) {    
        int c;    
        size_t i;    
    
        for(i=0; i<lim-1 && (c=getchar()) != EOF && c!='\n'; ++i)    
                s[i] = c;    
        if(c=='\n') {    
                s[i] = c;    
                ++i;    
        }    
        s[i] = '\0';    
        return i;    
} 

/* copy 'from' into 'to', assume 'to' is big enough */
void copy(char to[], char from[]) {
        int i = 0;
        while((to[i] = from[i]) != '\0')
                ++i;
} 
