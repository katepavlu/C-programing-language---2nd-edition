#include <stdio.h>
#include <stdlib.h>
/* cc - check a c program for unbalanced braces
 * prints out position of first encountered
 * brace that does not have a pair
 * ignores braces in comments and strings and chars */

typedef struct node{
        char br;
        size_t line;
        size_t chr;
        struct node* prev;
} node_t;

node_t* pushnode(char br, size_t line, size_t chr, node_t* head) {
        node_t* new = (node_t*)malloc(sizeof(node_t));

        new->br = br;
        new->line = line;
        new->chr = chr;
        new->prev = head;

        return new;
}

node_t* popnode(node_t* head) {
        node_t* ret = NULL;
        if(head) {
                head->br = 0;
                head->line = 0;
                head->chr = 0;
        
                ret = head->prev;
        
                head->prev = 0;
                if(head)
                        free(head);
        }
        return ret;
}

void end(node_t* head, char c, size_t line, size_t chr) {
        if( c || head)
                printf("Unbalanced brace: %c on line %ld, character %ld\n", 
                        head? head->br: c, 
                        head? head->line: line, 
                        head? head->chr: chr
                );
        while(popnode(head));
        exit(0);
}
        
int main() {
        node_t* head = NULL; //empty stack
        
        enum {REGULAR, LINECOMMENT, MULCOMMENT, STRING, CHAR} status = REGULAR;
        char c = 0;
        char prev = 0; // for //  /* */ detection
        enum {ON, OFF} escaped = OFF;

        size_t line = 1;
        size_t charn = 1; 

        for( ; (c=getchar()) != EOF ; prev = c, charn++ ) {

                if(c == '\n') {
                        line++;
                        charn = 0; //next charn will be 1, as in first on line
                }

                switch(status) {
                        case REGULAR:
                                switch(c) {
                                        case '*':
                                                if(prev == '/')
                                                        status = MULCOMMENT;
                                                continue; //do not care about comments
                                        case '/': 
                                                if(prev == '/')
                                                        status = LINECOMMENT;
                                                continue; //do not care about comments
                                        case '\'':
                                                status = CHAR;
                                                continue; //or about chars
                                        case '\"':
                                                status = STRING;
                                                continue; //or about strings
                                        
                                        case '(':
                                        case '[':
                                        case '{':
                                                head = pushnode(c, line, charn, head);
                                                break;
                                        case ')':
                                                if( !head ); //prevent null derefencing
                                                else if( head->br == '(') {
                                                        head = popnode(head);
                                                        break;
                                                }
                                                end(head, c, line, charn);
                                                break;
                                        case ']':
                                                if( !head ); //prevent null dereferencing
                                                else if( head->br == '[') {
                                                        head = popnode(head);
                                                        break;
                                                }
                                                end(head, c, line, charn);
                                                break;
                                        case '}':
                                                if( !head ); //prevent null dereferencing
                                                else if( head->br == '{') {
                                                        head = popnode(head);
                                                        break;
                                                }                                        
                                                end(head, c, line, charn);
                                                break;

                                }

                                break;

                        case LINECOMMENT:
                                if(c == '\n') {
                                        status = REGULAR;
                                }
                                break;

                        case MULCOMMENT:
                                if(c == '/' && prev == '*')
                                        status = REGULAR;
                                break;

                        case STRING:
                                if(escaped == OFF) {
                                        if(c == '\"') //do not end on escaped \"
                                                status = REGULAR;
                                        else if(c == '\\')
                                                escaped = ON;
                                }
                                else if(escaped == ON) {
                                        escaped = OFF;
                                }
                                break;

                        case CHAR:
                                if(escaped == OFF) {
                                        if(c == '\'') //do not end on escaped \'
                                                status = REGULAR;
                                        else if(c == '\\')
                                                escaped = ON;
                                }
                                else if(escaped == ON) {
                                        escaped = OFF;
                                }
                                break;
                }
        }

        while(head){
                c = head->br;
                line = head->line;
                charn = head->chr;
                head = popnode(head);
        }
                end(head, c != -1? c: 0, line, charn);
}
