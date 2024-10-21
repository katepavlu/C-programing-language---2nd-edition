#include <stdio.h>                                                                                                                                                                                                                            
#include <ctype.h>    
/* print input one word per line    
 * any block of non-space characters counts as a word */    
int main() {    
        register char c;    
        enum {INFILE, OUTFILE} ind = OUTFILE;    
    
        while( (c = getc(stdin) ) != EOF ) {    
                    
                if( isspace( c ) ) {    
                        if ( ind == INFILE )    
                                putchar('\n');    
                        ind = OUTFILE;    
                        continue;    
                }    
    
                if( ind == OUTFILE )    
                        ind = INFILE;    
                putchar( c );    
        }    
        return(0);    
}
