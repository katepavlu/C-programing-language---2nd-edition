  1 #include <stdio.h>                                                                                                                                                                                                                        
  2 #include <ctype.h>
  3 /* replace tabs in input by \t, backspaces by \b, \ by \\ */
  4 int main()
  5 {
  6         register char c;
  7 
  8         while( (c = getc(stdin) ) != EOF )
  9                 switch(c){
 10                         case '\t':
 11                         printf("\\t");
 12                         break;
 13                 case '\b':
 14                         printf("\\b");
 15                         break;
 16                 case '\\':
 17                         printf("\\\\");
 18                         break;
 19                 default:
 20                         putchar(c);
 21                         break;
 22                 }
 23     
 24         return(0);
 25 }
