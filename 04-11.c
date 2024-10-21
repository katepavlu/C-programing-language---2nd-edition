int getop(char s[]) {
        int i, c, ret;
        static int buf = 0;
        
        if(buf) {
            c = buf;
            buf = 0;
        }
        else
            c = getch();

        while( (s[0] = c) == ' ' || c == '\t'  )
            c = getch();
        
        s[1] = '\0';

        if( c == '>' ) {
                if( !isupper(s[0] = c = getch()) ) {
                        printf("Unknown variable: %c\n", s[0]);
                        buf = c;
                        return 0;
                }
                return SAVE;
        }

        if( isupper(c) )
                return VAR;
 
        if( !isdigit(c) && c != '.' && c != '-' && c != '&')
                return c; //not a number

        i = 0;

        if( c == '-' ) {
                if( !isdigit( s[++i] = c = getch() ) ) { //if char after - is not a number, it is a minus operator
                        buf = c;                         //else, it is already in the stack from the space skipper loop
                        return '-';
                }
        }
       
        if( isdigit(c) ){
                ret = NUMBER;
                while( isdigit( s[++i] = c = getch() ) ); //collect integer part
        
                if( c == '.' )
                        while( isdigit( s[++i] = c = getch() ) ); //collect fract part
       
                s[i] = '\0';
        }

        if( c == '&' ) {
                ret = FUNCTION;
                while ( islower(c = getch()) )
                        s[++i] = c;
                s[++i] = '\0';
        }
        if( c != EOF )
                buf = c;
        return ret;
}
