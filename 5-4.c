#include <stdio.h>

/* strend - return 1 if string end 
   occurs at the end of string str */
int strend(char* str, char* end) {
    int i,j;
    i=j=0;
    /* find the end of str */
    while(str[i++]);
   
    /* find the end of end */
    while(end[j++]);
    
    /* go back until char mismatch */
    while(str[i--] == end[j--] && i>=0 && j>=0);

    if( j == -1 )
        return 1;

    return 0;
}

int main () {
    printf("%d ", strend("Hello", "lo"));
    printf("%d ", strend("qwertyuiopasdfghjklzxcvbnm"\
           , "cvbnm"));
    printf("%d ", strend("Yes", "no"));
}