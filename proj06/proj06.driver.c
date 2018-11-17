/*
 *main used for testing
 */

/* 
 * File:   proj06.driver.c
 * Author: Tyler Staats
 *
 * Created on October 12, 2018, 5:28 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "/user/cse320/Projects/project06.support.h"
/*
 * 
 */
int main(int argc, char** argv) {
    
    double result;
    
    result = add(8.75 ,.5);
    printf( "sum: %f  Hex integer: %016llx\n", result, result );
    
    result = add(.5 ,8.75);
    printf( "sum: %f  Hex integer: %016llx\n", result, result );
    
    result = add(100 ,2.2);
    printf( "sum: %f  Hex integer: %016llx\n", result, result );
    
    result = add(105 ,6.4532);
    printf( "sum: %f  Hex integer: %016llx\n", result, result );
    
    result = add(-8.75 ,-.5);
    printf( "sum: %f  Hex integer: %016llx\n", result, result );
    
    result = add(-8.75 ,.5);
    printf( "sum: %f  Hex integer: %016llx\n", result, result );
    
    result = add(.5 ,-8.75);
    printf( "sum: %f  Hex integer: %016llx\n", result, result );

    return (EXIT_SUCCESS);
}
