#include <stdio.h>

/* any - return position of first occurence 
 * of any character from str2 in str1.
 * return -1 if no characters from str2 
 * are present in str1 */
int any(char* str1, char* str2) {
    int i,j;
    
    for(i=j=0; str1[i]; i++) {
        int det = 0;
        for(int k=0; str2[k]; k++)
            if(str1[i] == str2[k])
                det = 1;
        if( det )
            return i+1;
    }
    return -1;
}

int main()
{
    char str[] = "The quick brown fox jumps over the lazy dog.";
    
    printf("%s : %d\n", str, any(str, "\t"));

    return 0;
}
