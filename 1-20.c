#include <stdio.h>
#define TABGRID 4

/* detab - replace tabs with spaces on a TABGRID grid */
int main()
{
        char c = 0;
        unsigned int lineChars = 0;

        while((c=getchar()) != EOF)
        {
                if( c == '\t' ){
                        putchar(' ');
                        ++lineChars;
                        for( ; lineChars % TABGRID; ++lineChars)
                                putchar(' ');
                }
                else
                {
                        ++lineChars;
                        if( c == '\n' )
                                lineChars = 0;
                        putchar(c);
                }
        }
        return 0;
}
