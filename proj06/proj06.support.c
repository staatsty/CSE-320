/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include "/user/cse320/Projects/project06.support.h"









unsigned long long int make_significand_neg( unsigned long long int num){
    
                unsigned long long int negate, result; //this function just makes 
                negate = ~(((num>>8)>>48)<<48); //a significand negative
                negate = ((negate>>48)<<48);
                result = ((num<<8)>>16)|negate;
                return result;
}



double add( double first_num, double second_num ){
    union double_precision num;
    union double_precision num_1;
    union double_precision result;
    unsigned long long int negate,shifted, const2, field_num1, large_expo, test,test1, field_num2,expo_num2, expo_num1,sign_num1,sign_num2,const1 ,sum;
    signed true_exp_num1, true_exp_num2, shift;
    
    const1 = 0x1000000000000000; //bunch of variables 
    const2 = 0x0010000000000000;
    num.drep =first_num ;
    
    true_exp_num1 = ((num.irep >> 52) & 0x7ff) - 0x3ff;
    
    
    
    num_1.drep = second_num;
    
    true_exp_num2 = ((num_1.irep >> 52) & 0x7ff) - 0x3ff;
    
    
    if(true_exp_num1 >= true_exp_num2){
        shift = true_exp_num1 - true_exp_num2;
    }
    if(true_exp_num1 < true_exp_num2){
        shift = true_exp_num2 - true_exp_num1;
    }
    
    field_num1 = (num.irep <<12)>>4|const1;
    field_num2 = (num_1.irep <<12)>>4|const1;
     expo_num1 = ((num.irep >> 52)<<52); //unpack number to perform addition
     expo_num2 = ((num_1.irep >> 52)<<52);
     sign_num1 = (num.irep >> 63);
     sign_num2 = (num_1.irep >> 63);
     
     if (num_1.irep == 0x7ff0000000000000 | num.irep == 0x7ff0000000000000){
         return INFINITY; //checks for infinity
     } 
     
     if ((num_1.irep >= 0x7ff0000000000001 & num_1.irep <= 0x7ff1111111111111) | (num.irep>=0x7ff0000000000001 & num.irep<=0x7ff1111111111111)){
         return NAN;  //checks for not a number
     }
    
     
     int negative_a = 0;
     int negative_b = 0;
     int need = 0;
     if (true_exp_num1 >= true_exp_num2  ){
         
         if(sign_num1 == 0x0000000000000001){ //checks which num is negative
             expo_num1 = (expo_num1<<1)>>1;
                negate = ~(((field_num1>>8)>>48)<<48);
                negate = ((negate>>48)<<48);
                field_num1 = ((field_num1<<8)>>16)|negate;
                negative_a = 1;
         }
         
         if(sign_num2 == 0x0000000000000001){
             expo_num2 = (expo_num2<<1)>>1;
              
                field_num2 = make_significand_neg(field_num2);
                negative_b=1;
               
         }
       
     if(negative_b &! negative_a){ //after that preform shift and addition
         if(field_num2< field_num1){ //based on which exponent needs to be shifted
         shifted = (field_num2>>shift*3);
         }
         if(field_num1< field_num2){
         shifted = (field_num1>>shift*3); 
         }
         

         sum = shifted + field_num2;
         negate = ~(sum>>48)<<48;
         sum =negate | (sum<<16)>>16;
         sum = sum << 8 ;

     }
     
     if(negative_a &! negative_b){
         
         shifted = (field_num2>>shift*3);
         sum = shifted + field_num1;
         negate = ~((sum>>48)<<48);
         negate = (negate >> 48)<<48;
         sum =negate | (sum<<16)>>16;
          sum = sum << 8 ;
         need = 1;
     }
         
      
     if(negative_a & negative_b){
            
         
         sum = field_num1+ field_num2;
         negate = ~(sum>>48)<<48;
         negate = (negate >> 48)<<48;
         sum =negate | (sum<<16)>>16;
         sum = sum << 8 ;
         need = 1;
     }    
     
         if(need ==0 ){
         
         shifted = (field_num2>>shift);
        sum = shifted + field_num1;
         }
     
     
     large_expo = expo_num1; // after shift is completed 
     int done = 0;          // and addition shift the sum
     while(!done & need == 0){ //till its normalized
        if (((sum>>60)<<60)==const1){
             done = 1;
         }
         else{
           sum = sum>>1;
           large_expo += const2;
             
         }
    }
     
     
     }
     
     if (true_exp_num1 < true_exp_num2){// this next if statement is just like the previous
         need = 0;                 //everything is just flipped, i should have implemented differently
         if(sign_num2 == 0x0000000000000001){ //however no time
             expo_num2 = (expo_num2<<1)>>1;
                negate = ~(((field_num2>>8)>>48)<<48);
                negate = ((negate>>48)<<48);
                field_num2 = ((field_num2<<8)>>16)|negate;
                negative_a = 1;
         }
         
         if(sign_num1 == 0x0000000000000001){ //makes nums neg if needed
             expo_num1 = (expo_num1<<1)>>1;
              
                field_num1 = make_significand_neg(field_num1);
                negative_b=1;
         }
     
      if(negative_a &! negative_b){
         shifted = (field_num1>>shift*3);
         sum = shifted + field_num2;
         negate = ~(sum>>48)<<48;
         sum =negate | (sum<<16)>>16;
         sum = sum << 8 ;
         need =1 ;
     }
         
      if(negative_b &! negative_a){ //performs shift if needed
         shifted = (field_num2>>shift*3);
         sum = shifted + field_num1;
         negate = ~(sum>>48)<<48;
         sum =negate | (sum<<16)>>16;
         sum = sum << 8 ;
         need = 1;
     }
         
        if(negative_a & negative_b){
         
         sum = field_num1+ field_num2;
         negate = ~(sum>>48)<<48;
         negate = (negate >> 48)<<48;
         sum =negate | (sum<<16)>>16;
         sum = sum << 8 ;
         need = 1;
     }    
       
     
     if(need ==0 ){
         
         shifted = (field_num1>>shift);
        sum = shifted + field_num2;
         }   
         
         
         
     large_expo = expo_num2; //after addition needs to normalize the sum
     int done = 0;
     while(!done & need == 0){
         if (((sum>>60)<<60)==const1){
             done = 1;
         }
         else{
            sum = sum>>1;
            large_expo += const2;
             
         }
     }
     }
     
     
     if(negative_a){ //formats if num is neagative
       test = ((((large_expo<<1)>>4)|const1)<<3);
       result.irep = ((sum<<4)>>12)| test;
       
       return result.drep;
     }
     else{ //returns the sum
     result.irep = ((sum<<4)>>12)| large_expo;
     return result.drep;
     
     }
}
