#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000

/* remove trailing whitespace from lines
 * remove empty lines
 * line length limited to MAXLINE */

size_t getl(char line[], size_t maxline);
void copy(char to[], char from[]);
long lastnspc(char line[]);

int main() {
        char line[MAXLINE] = {}; 
        int temp;
        size_t len; 

        while( (len = getl(line, MAXLINE)) > 0 ) {
                if( (len >= MAXLINE - 1) && line[MAXLINE - 2] != '\n' ) { //skip over rest of line if it can't fit in buffer
                        while( (temp = getchar()) != EOF && temp != '\n');
                        line[MAXLINE - 2] = '\n';
                }
                

                if( lastnspc(line) > -1 )

                        printf("%s",line);
        }
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

/* replace trailing space with \n\0
 * return last nonspace character index
 * return -1 if line is whitespace only */
long lastnspc(char line[]) {
        size_t i = 0;
        long ret = -1;
        while( line[i] ) { // read until \0
                 if( !isspace( line[i] ) )
                         ret = i;
                 i++;
        }
        if(ret != -1) {
                line[ret+1] = '\n';
                line[ret+2] = '\0';
        }
        return ret;
}
