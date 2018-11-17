/*
 * main driver to test if decode function properly
 * converts machine instruction 
 */

/* 
 * File:   proj07.driver.c
 * Author: Tyler Staats
 *
 * Created on October 23, 2018, 1:41 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "/user/cse320/Projects/project07.support.h"

int main(int argc, char** argv) {
    
    char array[100];
    unsigned int num = 0xe1520003;
    unsigned int num1 = 0xe086a007;
    unsigned int num2 = 0xe096a007;
    unsigned int num3 = 0xe286a007;
    unsigned int num4 = 0xe1a01003;
    unsigned int num5 = 0xe1301003;
    unsigned int num6 = 0xe250114d;
    unsigned int num7 = 0x61a01003;
    
    
    
    printf( "Instruction           Human-readable form\n");   //test cases
    
    decode(num,array);
    printf( "%08x              %s\n", num, array);
    
    decode(num1,array);
    printf( "%08x              %s\n", num1, array);
    
    decode(num2,array);
    printf( "%08x              %s\n", num2, array);
    
    decode(num3,array);
    printf( "%08x              %s\n", num3, array);
    
    decode(num4,array);
    printf( "%08x              %s\n", num4, array);
    
    decode(num5,array);
    printf( "%08x              %s\n", num5, array);
    
    decode(num6,array);
    printf( "%08x              %s\n", num6, array);
    
    decode(num7,array);
    printf( "%08x              %s\n", num7, array);
    

    return (EXIT_SUCCESS);
}

