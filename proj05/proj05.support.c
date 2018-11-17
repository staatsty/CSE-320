/*
 Proj05
 * Make a function that represents a substring of characters based on specific base
 * Tyler Staats
 * PID: A51390344
 */

#include <stdio.h>
#include <math.h> 




int convert( const char phrase[] , int base, int* stored){
    
    int length = 0;
    int size = 0;
    int neg = 0;
    int exp = -1; //data storage
    int exp_2 = -1;
    int accept = 0;
    
    while (phrase[size] != '\0'){ //loops to find size of substring

    if( phrase[size] == ' '){
                size++;
                continue;
            }
    
    if( phrase[size] == '-'){ //conditionals for what chars to accept
        
        
                if (accept==0){
                    neg = 1;
                    size++;
                    continue;
                }
                else{
                    break;
                }
            }
    
    if( phrase[size] == '+'){
                if (accept==0){
                    size++;
                    continue;
                }
                else{
                    break;
                }
            }
    if( phrase[size]>= '0' &&  phrase[size]<= '9'){ //valid char
        if(base>= phrase[size]){
            break;
        }
        accept = 1;
        exp+=1;
        exp_2+=1;     //increments size and exponenets for decimal conversion
       size++;
       continue;
    }
    
    if( phrase[size]>= 'A' && phrase[size] <= 'Z'){ //valid char
        
                int value = (phrase[size]- 'A') +10;
                if(value > base -1){
                    break;
                }
                else{
                    exp_2+=1;
                    size++;
                    continue;
                }
    
    }
    
    if( phrase[size]>= 'a' && phrase[size] <= 'z'){ //valid chars
        
                int value = (phrase[size]- 'a') +10;
                if(value > base -1){
                    break;
                }
                else{
                    exp_2+=1;
                    size++;
                    continue;
                }
    
    }
    size++;
    }
    

    
    if( base>= 2 && base<= 10){ //first if handles bases between 2-10 since they 
        
        for(int i = 0; i<size; i++){ //dont worry about alpha chars
            
            if( phrase[i] == ' '){
                continue;
            }
            if( phrase[i]>= '0' && phrase[i] <= '9'){
                int num = phrase[i] - '0';
                length += num * round(pow(base,exp)); //changes the value to decimal
                exp -= 1;
                
                
                        continue;
            }
            
        }
        if(neg == 1){
            length = length *-1;
        }
        if (length == 0){
            *stored = 0;
            return 0;
        }
        
        
        *stored = length;
        return 1;
       

    }
    
    
    
    if( base>10 && base<= 36){ //base 10-36 accounts for alpha chars
        for(int i = 0; i<size; i++){
            if( phrase[i] == ' '){
                continue;
            }
            if( phrase[i]>= 'A' && phrase[i] <= 'Z'){
                int value = (phrase[i]- 'A') +10; //changes value to base 10 to be stored
                if(value > base -1){
                    break;
                }
                length += value * round(pow(base,exp_2));
                exp_2 -=1;
            }
            
            if( phrase[i]>= 'a' && phrase[i] <= 'z'){
                int value = (phrase[i]- 'a') +10;
                if(value > base -1){
                    break;
                }
                length += value * round(pow(base,exp_2));
                exp_2 -=1;
            }
            
            if( phrase[i]>= '0' && phrase[i] <= '9'){
               int num = phrase[i] - '0';
               length += num * round(pow(base,exp_2));
                exp_2 -=1;
            }
            
            
        }
        if(neg == 1){
            length = length *-1; //negates if needed
        }
        if (length == 0){
            *stored = 0;
            return 0;
        }
        *stored = length;
        return 1;
        
    }
    else{
        *stored = 0;
        return 0;
    }

    
}
