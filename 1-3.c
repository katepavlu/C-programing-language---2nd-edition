/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h> 
/* print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300; floating-point version */ 
int main() { 
    float fahr, celsius; 
    int lower, upper, step; 
    lower = 0; /* lower limit of temperature table */ 
    upper = 300; /* upper limit */ 
    step = 20; /* step size */ 
    
    fahr = lower; 

    printf("  F    C\n");
    printf("----------\n");
    
    while (fahr <= upper) { 
        
        celsius = (5.0/ 9.0) * (fahr - 32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    } 
}