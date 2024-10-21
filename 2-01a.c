#include <stdio.h>
#include <float.h>

/* get float ranges from libary 
 * 
 * I decided not to calculate the values, since 
 * that would require knowing the mantissa and exponent
 * lengths, and if you get that from float.h, why wouldn't
 * you get the limits as well. */

int main()
{
    printf("Float range - min: %g max finite: %g\n",
    FLT_MIN, FLT_MAX);
    
    printf("Double range - min: %g max finite: %g\n",
    DBL_MIN, DBL_MAX);
    
    printf("Long double range - min: %Lg max finite: %Lg\n",
    LDBL_MIN, LDBL_MAX);
}
