#include <stdio.h>

/* strncpy - copy n chars from ct to s
   pad with zeros if ct is too short,
   terminatewith zero */
char* strncpy(char* s, char* ct, unsigned int n) {
    for(int i=0; i<n; i++)
        s[i] = ct[i]? ct[i]: 0;
    s[n] = 0;
    return s;
}

/* strncat - copy at most nchars from ct
   to the end of s, terminate with zero */
char* strncat(char* s, char* ct, unsigned int n) {
    char* ret = s;
    while(*s)
        s++;
    
    for(unsigned int i=0; i<n; i++)
        s[i] = ct[i]? ct[i]: '\0';
    
    s[n] = '\0';
    return ret;
}

/* strncmp - compare first character that is different
   in cs, ct as 8-bit ints */
int strncmp(char* cs, char* ct, unsigned int n) {
    unsigned int i;
    for(i = 0; i<n && cs[i] && ct[i]; i++)
        if(cs[i] != ct[i])
            break;

    if(i==n)
        return 0;

    return cs[i]>ct[i]? 1: -1;
}

int main() {
    char buf[20] = {};
    char txt[] = "Helvetin perkele";
    
    printf("%s\n", strncpy(buf, txt, 5));
    printf("%s\n", strncat(buf, txt, 5));
    
    printf("%d\n", strncmp("123455", "123456", 5));
    printf("%d\n", strncmp("123455", "123456", 6));
    printf("%d\n", strncmp("123457", "123456", 6));
}