#include <stdio.h>    
#include <ctype.h>    
    
#define TABGRID 8    
/* entab - replace string of spaces with the    
 * minimum number of tabs and spaces to achieve the set width    
 * tab width controlled by TABGRID */    
int main()    
{    
        char c = 0;    
        long numsp = 0;    
        char lineindx = 0;    
    
        while((c=getchar()) != EOF)    
        {    
                if( c == ' ' )    
                        numsp++;    
                   
                else{    
                        while( (lineindx % TABGRID + numsp) / TABGRID ) { //while tabs can be placed    
                                numsp -= ( TABGRID - lineindx % TABGRID ); //substract spaces until next tab break
                                lineindx = 0;  //no need to count whole line length, jhust to nearest tab break    
                                putchar('\t');    
                        }    
                        while( numsp > 0 ) {    
                                putchar(' '); //fill the rest with spaces    
                                numsp--;    
                        }    
                        if( isspace(c) )
                                lineindx++; // for the new nonspace character                                         
    
                        if(c == '\n')    
                                lineindx = 0;    
                        putchar(c);    
                }    
       }    
        return 0;    
} 
