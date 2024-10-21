#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXLINE 1000

/* reverse string in place
 * line by line
 * line limit 1000 not counting \n\0 */

size_t getl(char line[], size_t maxline);
void copy(char to[], char from[]);
void reverse(char line[]);

int main() {
        char line[MAXLINE] = {}; 
        int temp;
        size_t len; 

        while( (len = getl(line, MAXLINE)) > 0 ) {
                if( (len >= MAXLINE - 1) && line[MAXLINE - 2] != '\n' ) { //skip over rest of line if it can't fit in buffer
                        while( (temp = getchar()) != EOF && temp != '\n');
                        line[MAXLINE - 2] = '\n';
                }
                reverse(line);
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

/* reverse \n\0 terminated string in place */
void reverse(char line[]) {
        size_t i = 0;
        size_t j = strlen(line);
        j -= 2; // do not reverse \n\0
        for( ; i < j ; i++, j-- ) {
                char temp = line[i];
                line[i] = line[j];
                line[j] = temp;
        }
}
