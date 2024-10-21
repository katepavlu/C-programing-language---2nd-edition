#include <stdio.h>

/* htoi: convert string in hex to decimal int
 * 0x is ignored, non-digits get skipped
 * conversion stops at \0 */

int htoi(char* s)
{
    int ret = 0;
    char next = 0;
    int i = 0;

    while ( next = s[i++] )
    {
        if(next == '0' && (s[i] == 'x' || s[i] == 'X'))
        {
            i++;
            continue;

        }
            
        else if(next >= '0' && next <= '9')
            ret = ret * 16 + next - '0';
            
        else if(next >= 'a' && next <= 'f')
            ret = ret * 16 + next - 'a' + 10;
            
        else if(next >= 'A' && next <= 'F')
            ret = ret * 16 + next - 'A' + 10;

    }
    
    return ret;
}

int main()
{
    char str[] = "0xdeadbeef"; 
    printf("\tstring: %s\n\tint:    0x%x", str, htoi(str));

    return 0;
}
