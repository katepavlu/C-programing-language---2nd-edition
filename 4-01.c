#include <stdio.h>
#include <string.h>

/* return index of rightmost occurence of chrs in str */
int strrindex( char* str, char* chrs ) {
    int i,j,k;
    for(i=strlen(str); i>0 ; i--) {
        for(j=i, k=0; chrs[k] != '\0' && str[j]==chrs[k]; j++, k++);
        if(k > 0 && chrs[k] == '\0')
            return i;
    }
    return -1;
}

int main()
{
    return strrindex( "The quick brown dog jumps over the lazy dog", "dog");
}
