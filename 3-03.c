#include <stdio.h>
#include <ctype.h>

/* expand shorthand like a-z into entire list;
 * assume the expanded list fits in s2 
 * s2 is assumed to be initialised to 0*/
void expand(char* s1, char* s2) {
    int i,j;

    for(i=j=0; s1[i]; i++) {
        if(
            s1[i] == '-' && (
            islower(s1[i-1]) && islower(s1[i+1]) ||
            isupper(s1[i-1]) && isupper(s1[i+1]) ||
            isdigit(s1[i-1]) && isdigit(s1[i+1]) )
            && s1[i-1] < s1[i+1]
            )
            for(char k = s1[i-1]+1; k<s1[i+1]; k++)
                s2[j++] = k;
        else
            s2[j++] = s1[i];
    }
}

int main()
{
    char str1[] = "-a-d-x-z-X-0-9-";
    
    char str2[200] = {};
    
    expand(str1, str2);
    
    printf("%s\n%s\n", str1, str2);

    return 0;
}
