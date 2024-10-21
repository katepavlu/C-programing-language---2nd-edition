#include <stdio.h>

/* squeeze - remove all instances of the individual 
 * characters in str2 from str1 */
void squeeze(char* str1, char* str2) {
    int i,j;
    
    for(i=j=0; str1[i]; i++) {
        int det = 0;
        for(int k=0; str2[k]; k++)
            if(str1[i] == str2[k])
                det = 1;
        if( !det )
            str1[j++] = str1[i];
    }
    str1[j] = '\0';
}

int main()
{
    char str[] = "The quick brown fox jumps over the lazy dog.";
    
    squeeze(str, "aeiyouAEIYOU");
    printf("%s", str);

    return 0;
}
