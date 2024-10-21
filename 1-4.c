#include <stdio.h> 
/* print Celsius-Fahrenheit table for celsius = -20, -10, ..., 300; floating-point version */ 
int main() { 
    float fahr, celsius; 
    int lower, upper, step; 
    lower = -20; /* lower limit of temperature table */ 
    upper = 150; /* upper limit */ 
    step = 10; /* step size */ 
    
    celsius = lower; 

    printf(" C   F\n");
    printf("----------\n");
    
    while (celsius <= upper) { 
        
        fahr = (9.0/ 5.0) * (celsius) + 32;
        printf("%3.0f %5.1f\n", celsius, fahr);
        celsius = celsius + step;
    } 
}