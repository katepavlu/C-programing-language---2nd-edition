#include <stdio.h>
#include <string.h>

void reverse(char *str, int depth, const int len) {
    char tmp = str[depth];
    str[depth] = str[len - 1 - depth];
    str[len - 1 - depth] = tmp;
    if(depth < len - 1 - depth)
        reverse(str, ++depth, len);
}

int main() {
    char str[] = "The ultimate showdown of ultimate destiny\n";

    reverse(str, 0, strlen(str));
    printf("%s", str);

    return 0;
}
