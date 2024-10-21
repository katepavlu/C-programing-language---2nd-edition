#include <stdio.h>                                                                                                    
#include <ctype.h>    
#define NUM_CHARS 26    
#define HISTOGRAM_ROWS 15    
    
/* print a histogram of letter frequencies */    
int main()    
{    
        int c = 0;    
        int maxChars = 0;    
        int nChars[NUM_CHARS] = {};    
        while( ( c = getchar() ) != EOF )    
        {    
                c = toupper(c); /* we want ot be case insensitive */    
    
                if( isalpha(c) )    
                {    
                        if(++nChars[c-'A'] > maxChars)    
                                maxChars = nChars[c-'A'];
                }    
        }    
    
        for( int i = 0; i < NUM_CHARS; ++i ) /* normalise to graph height */    
                nChars[i] = (nChars[i] * HISTOGRAM_ROWS) / maxChars ;    
            
        printf("\tgraph scale - tallest collumn = %d", maxChars);    
        printf("\n");    
            
        for( int i = 0; i <= HISTOGRAM_ROWS; ++i )    
        {    
                printf("\t|"); //left border    
                for( int j = 0; j < NUM_CHARS; ++j )    
                {    
                        if( i == HISTOGRAM_ROWS ){  /* last row, print legend */   
                                printf("%c|", j+'A');    
                                continue;    
                        }    
                        char wr = (nChars[j] - HISTOGRAM_ROWS + i + 1> 0 ? '#': ' ' );    
                        printf("%c|", wr);    
                            
               }    
                printf("\n");    
        }    
            
        return 0;    
}  
