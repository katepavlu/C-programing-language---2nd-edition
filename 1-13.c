#include <stdio.h>                                                                                                                                                                                                                            
#include <ctype.h>    
#define MAX_LEN 30 //maximum word length = histogram columns    
#define HISTOGRAM_ROWS 15    
    
/* print fixed width and height histogram of word lengths */    
    
int main()    
{    
        int c;    
        int wordLen = 0;    
        int maxWord = 1;    
        int nWords[MAX_LEN+1] = {};    
        enum {INWORD, OUTWORD} loc = OUTWORD;    
        while( ( c = getchar() ) != EOF )    
        {    
                if( isspace(c) )    
                {    
                        if( loc == INWORD )    
                        {    
                                /* if whitespace space found after word end, increase word count for this length */    
                                ++nWords[wordLen];    
                                if(nWords[wordLen] > maxWord)    
                                        maxWord = nWords[wordLen];    
                                /* keep the current maximum occurence number, will be used to normalise the histogram height */    
                                wordLen = 0;    
                        }    
                        loc = OUTWORD;    
                }    
                /* compound-words count as one word    
                 * numbers and non-dash special characters do not count towards word length*/    
                else if( isalpha(c) || c == '-' )    
                {    
                        loc = INWORD;    
                        ++wordLen;    
                }    
                /* limit word length to longest actually used english word    
                 * Pseudopseudohypoparathyroidism (30)     
                 * to prevent buffer overflow */    
                if(wordLen > MAX_LEN)    
                        wordLen = MAX_LEN;    
        }    
        /* normalise histogram height to the number defined in the header */    
        for( int i = 0; i < MAX_LEN+1; ++i )    
                nWords[i] = (nWords[i] * HISTOGRAM_ROWS) / maxWord ;    
            
        printf("\tgraph scale - tallest collumn = %d", maxWord);    
        printf("\n");     

          for( int i = 0; i <= HISTOGRAM_ROWS; ++i )
        {
                printf("\t|"); //left border for the histogram
                for( int j = 1; j < MAX_LEN + 1; ++j )
                {
                        if( i == HISTOGRAM_ROWS ){
                                printf("%2d|", j); //print column numbers at the bottom
                                continue;
                        }
                        char wr = (nWords[j] - HISTOGRAM_ROWS + i + 1> 0 ? '#': ' ' );
                        printf("%c%c|", wr, wr);
                        
               }
                printf("\n");
        }
        
        return 0;
}   
