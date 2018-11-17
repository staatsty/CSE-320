/* 
 * File:   proj05.driver.c
 * Author: Tyler Staats
 *
 * Created on October 3, 2018, 9:59 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "/user/cse320/Projects/project05.support.h"

/*
 * 
 */
int main(int argc, char** argv) {
    
  int return_base_10, stored_value, return_base_2, return_base_4,return_base_16,return_base_24,return_base_36;
  const char C[] = "125";
  
  //general test
  return_base_2 = convert("10011", 2, &stored_value);
  printf("Return: %d  Stored: %d In Hex:(%08x)\n", return_base_2, stored_value, stored_value);
  
  return_base_4 = convert("10210", 4, &stored_value);
  printf("Return: %d  Stored: %d In Hex:(%08x)\n", return_base_4, stored_value, stored_value);
  
  
  return_base_10 = convert("125", 10, &stored_value);
  printf("Return: %d  Stored: %d In Hex:(%08x)\n", return_base_10, stored_value, stored_value);
  
  
  return_base_16 = convert("  142AD", 16, &stored_value);
  printf("Return: %d  Stored: %d In Hex:(%08x)\n", return_base_16, stored_value, stored_value);
  
  
  return_base_24 = convert("  189AhF", 24, &stored_value);
  printf("Return: %d  Stored: %d In Hex:(%08x)\n", return_base_24, stored_value, stored_value);
  
  return_base_36 = convert(" 313ZDF", 36, &stored_value);
  printf("Return: %d  Stored: %d In Hex:(%08x)\n", return_base_36, stored_value, stored_value);
  
  
  // error testing
  return_base_10 = convert("-125", 10, &stored_value);
  printf("Return: %d  Stored: %d In Hex:(%08x)\n", return_base_10, stored_value, stored_value);
  
  return_base_10 = convert("12-5", 10, &stored_value);
  printf("Return: %d  Stored: %d In Hex:(%08x)\n", return_base_10, stored_value, stored_value);
  
  return_base_10 = convert("zzzz", 10, &stored_value);
  printf("Return: %d  Stored: %d In Hex:(%08x)\n", return_base_10, stored_value, stored_value);
  
  return_base_10 = convert("1+25", 10, &stored_value);
  printf("Return: %d  Stored: %d In Hex:(%08x)\n", return_base_10, stored_value, stored_value);
  
  return_base_10 = convert("-125", 50, &stored_value);
  printf("Return: %d  Stored: %d In Hex:(%08x)\n", return_base_10, stored_value, stored_value);
  
  return_base_10 = convert("-125", 0, &stored_value);
  printf("Return: %d  Stored: %d In Hex:(%08x)\n", return_base_10, stored_value, stored_value);
  
  return_base_10 = convert("-125af", 10, &stored_value);
  printf("Return: %d  Stored: %d In Hex:(%08x)\n", return_base_10, stored_value, stored_value);
  
  return_base_16 = convert("-125AbCDX", 16, &stored_value);
  printf("Return: %d  Stored: %d In Hex:(%08x)\n", return_base_10, stored_value, stored_value);
  
  
  
  
  
    return (EXIT_SUCCESS);
}

