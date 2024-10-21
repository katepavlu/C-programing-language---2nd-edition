#include <stdio.h>
#include <ctype.h>
/* print input one word per line
 * any block of non-space characters counts as a word */

float ctof(float celsius);

int main() {
        float celsius; 
        int lower, upper, step; 
        lower = -20; /* lower limit of temperature table */ 
        upper = 150; /* upper limit */ 
        step = 10; /* step size */ 
        
        celsius = lower; 

        printf("  C   F\n");                                                                                      
        printf("----------\n");
    
        while (celsius <= upper) { 
                printf("%3.0f %5.1f\n", celsius, ctof(celsius));
                celsius = celsius + step;
        } 
}

float ctof(float celsius) {
        return celsius * 9.0 / 5.0 + 32.0;
}
