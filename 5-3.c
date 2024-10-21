#include <stdio.h>

/* strcat- copy string src
   to the end of string dest */
char* strcat(char* dest, char* src) {
    /* save destination for return */
    char* ret = dest;
    /* go to end of dest string */
    while( *dest )
        dest++;
    
    /* copy char from src to dest
       until src is at \0 */
    while( *dest = *src ){
        dest++;
        src++;
    }
    
    return ret;
}

int main() {
    char a[] = "foo";
    char b[] = "bar";
    
    printf("%s\n", strcat(a,b));
}