#include <stdio.h>

/* write equivalent of first loop
 * without using && || */
int main()
{
    for(i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i) {
        /* code goes here */
    }
    
    for(i=0; i<lim-1; ++i) {
        if( (c=getchar()) == '\n')
            break;
        else if( c == EOF )
            break;
        else {
            /* code goes here */
        }
    }
}
