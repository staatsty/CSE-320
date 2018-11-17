/*
 *support for the mainfile 
 * implements machine language into human readable form
 */

#include <stdio.h>
#include <stdbool.h> 
#include <string.h>

unsigned int first_six(unsigned int num){ //this checks first six bits for acceptable form
    unsigned int num2 = num>>26;
    return num2;
}

unsigned int find_rn(unsigned int num){ //this finds the first source
    num = (num<<12)>> 28;
    return num;
}


unsigned int find_rd(unsigned int num){ //this finds the destination register
    num = (num<<16)>>28;
    return num;
}


unsigned int find_rm(unsigned int num, bool has_i){ //this finds the second source register
    
    if(has_i){
      num = (num<<24)>>24;
    }
    
    else{
       num = (num<<28)>>28;
    }
    return num;
    
}


void opt_code(unsigned int num, bool s_bit, char array[]){ //this stores the opt code into the ch array first
    char* const_array[] = {"and","eor","sub","rsb","add","adc","sbc","rsc","tst","teq","cmp","cmn","orr","mov","bic","mvn",'\0'};
    num = (num <<7)>>28;
    
    
    if(s_bit & num !=8 & num !=9 & num !=10 &num != 11){ //checks if the opt code needs an s added to it
        char s_string[10];
        strcpy(s_string, const_array[num]);
        strcat(s_string,"s");
        sprintf(array,s_string); //store opt code
    }
    
    else{   //if not just store the opt code
        
        sprintf(array, const_array[num]);
    }
    

    
}



bool find_i_bit(unsigned int num){ //checks if an i bit exist or not
    num = (num<<6)>>31;
    if(num == 0){
        return false;
    }
    if(num == 1){
        return true;
    }
}



bool find_s_bit(unsigned int num){ //checks if the s bit exsist or not
    num = (num<<11)>>31;
    if(num == 0){
        return false;
    }
    if(num == 1){
        return true;
    }
}





void decode( unsigned int num, char array[] ){ //decode stores the value in a readable form
    bool s_bit = find_s_bit(num); 
    bool i_bit = find_i_bit(num); 
    
    unsigned int rn = find_rn(num);
    unsigned int rd = find_rd(num);      //function calls to gather all needed parts
    unsigned int rm = find_rm(num,i_bit);
    unsigned int error = first_six(num);
    
    
    
    
    
    opt_code(num,s_bit,array);
    
    if(error!=56){ //checks for a valid instruction 
       sprintf(array, "Error Not a Valid Instruction" ); 
    }
    
    
    else if (array[0] == 'c' | array[0] == 't'){ //checks if command was a compare/test
        sprintf(array + strlen(array), " r%d, r%d",rn,rm ); //stores only the sources
    }  
        
    
        
    else if (array[0] == 'm'){            //checks if it was a move command
        sprintf(array + strlen(array), " r%d, r%d",rd,rm ); //stores only one source and destination 
        
        
    }
    
    
    
    
    else if (i_bit){
        sprintf(array + strlen(array), " r%d, r%d, #0x%02x",rd,rn,rm ); //if it contains i bit must format the 2nd source
    }
    
    
    else{
        sprintf(array + strlen(array), " r%d, r%d, r%d",rd,rn,rm ); //else just return the destination and both source
    }
    
    
}
