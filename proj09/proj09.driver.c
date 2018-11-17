//test file to support file
//test mostly math functions in assembly language 
//11/8/2018


#include <stdio.h>

int add( int, int );
int sub( int, int);
int negate( int);
int absolute( int);
int divide(int,int);
int mul(int,int);
int power(int,int);
int factorial(int);


int main()

{
  int A = 10, B = 7;
  int C = 0x7fffffff, D = -3;
  int R;
  
  
  
  R = add(A,B);
  printf( "%d + %d is %d:\n",A,B, R);
  R = add(D,A);
  printf( "%d + %d is %d:\n",D,A, R);
  R = add(C,A);
  printf( "%d + %d is %d:\n",C,A, R);
  
  
  
  R = sub(A,B);
  printf( "%d - %d is %d:\n",A,B, R);
  R = sub(D,A);
  printf( "%d - %d is %d:\n",D,A, R);
  R = sub(C,A);
  printf( "%d - %d is %d:\n",C,A, R);
  
  
  
  R = negate(A);
  printf( "%d negated is %d:\n",A, R);
  R = negate(D);
  printf( "%d negated is %d:\n",D, R);
  R = negate(0x80000000);
  printf( "0x80000000 negated is %d:\n",R);
  
  
  
  R = absolute(A);
  printf( "%d absolute is %d:\n",A, R);
  R = absolute(D);
  printf( "%d absolute is %d:\n",D, R);
  R = absolute(0x80000000);
  printf( "0x80000000 absolute is %d:\n",R);
  
  R = divide(A,B);
  printf( "%d / %d is %d:\n",A,B, R);
  R = divide(D,A);
  printf( "%d / %d is %d:\n",D,A, R);
  R = divide(A,0);
  printf( "%d / 0 is %d:\n",A, R);
  
  R = mul(A,B);
  printf( "%d * %d is %d:\n",A,B, R);
  R = mul(A,D);
  printf( "%d * %d is %d:\n",D,A, R);
  R = mul(C,A);
  printf( "%d * %d is %d:\n",C,A, R);
  
  R = power(B,D);
  printf( "%d to the power of %d is %d:\n",B,D, R);
  R = power(A,B);
  printf( "%d to the power of %d is %d:\n",A,B, R);
  R = power(C,B);
  printf( "%d to the power of %d is %d:\n",C,B, R);

  R = factorial(5);
  printf( "5 factorial is %d\n", R);
  R = factorial(13);
  printf( "13 factorial is %d\n", R);
 

  return 0;
}

