#include <stdio.h>
#include <string.h>

/* escape - convert escape sequences in a string
 * into the actual characters (\t,\n,\v,\a,\",\',\\) */
void escape(char in[], char out[])
{
    unsigned int in_i, out_i;
    for(in_i = out_i = 0; in[in_i]; )
    {
        if( in[in_i] == '\\')
        {
            switch( in[++in_i] )
            {
                case 'a':
                    out[out_i] = '\a';
                    break;
                case 'v':
                    out[out_i] = '\v';
                    break;
                case 't':
                    out[out_i] = '\t';
                    break;
                case 'n':
                    out[out_i] = '\n';
                    break;
                case '"':
                    out[out_i] = '\"';
                    break;
                case '\'':
                    out[out_i] = '\'';
                    break;
                case '\\':
                    out[out_i] = '\\';
                    break;
                default:
                    printf("Unknown escape sequence\n");
            }
        }
        else 
            out[out_i] = in[in_i];
        in_i++;
        out_i++;
    }
}

/* helper function for capture */
static inline void esc(char arr[], int *indx){
    arr[(*indx)++] = '\\';
}

/* capture - convert nonprintable characters into
 * escape sequences */
void capture(char in[], char out[])
{
    unsigned int in_i, out_i;
    for(in_i = out_i = 0; in[in_i]; )
    {
        switch( in[in_i] )
        {
            case '\a':
                esc(out, &out_i);
                out[out_i] = 'a';
                break;
            case '\v':
                esc(out, &out_i);
                out[out_i] = 'v';
                break;
            case '\t':
                esc(out, &out_i);
                out[out_i] = 't';
                break;
            case '\n':
                esc(out, &out_i);
                out[out_i] = 'n';
                break;
            case '\"':
                esc(out, &out_i);
                out[out_i] = '\"';
                break;
            case '\'':
                esc(out, &out_i);
                out[out_i] = '\'';
                break;
            case '\\':
                esc(out, &out_i);
                out[out_i] = '\\';
                break;
            default:
                out[out_i] = in[in_i];
        }
        in_i++;
        out_i++;
    }
}

/* convert a string into printable readable escaped version and back */
int main(){
    char input[] = "a\nk\tkl\a\vstr  \\re \"rw \'re \n";
    char output[strlen(input)*2];
    char out2[strlen(input)*2];
    capture(input, output);
    escape(output, out2);
    
    printf("input: %s\noutput: %s\nout2: %s\n", input, output, out2);
}
