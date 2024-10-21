#include <stdio.h>
#include <stdint.h>
/* count spaces, tabs and newlines in a file */
int main()
{
    register char c;
    size_t cnt = 0;

    while( (c = getchar() ) != EOF )
        switch(c){
            case ' ':
            case '\t':
            case '\n':
                cnt++;
                break;
        }

    printf("%ld\n", cnt);
	return(0);
}
