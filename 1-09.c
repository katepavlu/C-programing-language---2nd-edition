#include <stdio.h>    
#include <ctype.h>    

/* truncate whitespace to first character in continuous block */
int main()    
{    
    register char c;      
    
    while( (c = getc(stdin) ) != EOF )    
    {    
        if( isspace(c) )    
        {    
            putchar(c);     
            /* print first whitespace character */    
            while( isspace( c = getc(stdin) ) );    
            /* skip until first non-whitespace character */    
        }    
             
        putchar(c);                                                                                                                                                                                                                           
    }    
    return(0);    
} 
