#include <stdio.h>

/* convert to lowercase, ignore anything 
 * that is not an uppercase character */
char lower(char c) {
    return (c <= 'Z' && c >= 'A')? c-'A'+'a': c;
}

int main() {
    char str[] = "AbCdEfGhIjKlMnOpQrStUvWxYz1234567890\n";
    
    for(int i=0; str[i]; i++)
        putchar( lower(str[i]) );

    return 0;
}
