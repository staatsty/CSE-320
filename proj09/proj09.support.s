        .global add
        .global sub
        .global negate
        .global absolute
        .global divide
        .global mul
        .global power
        .global factorial

        .text
add:
        push    {r4,r5,r7,lr} @ add is simmilar to example21.s 

        mov     r4, r0      @ Save first argument
        mov     r5, r1      @ Save 2nd argument

        adds    r7, r4, r5  @ Add the operands

        

        bvs     overflow    @ Check for overflow
valid:
        mov     r0, r7      @ Return value (valid)
        b        done
overflow:
        mov     r0, #0x80000000	      @ Return error (not valid)
done:
        pop     {r4,r5,r7,lr}
        bx      lr
        
        
        
        
        
sub:
        push    {r4,r5,r7,lr} @ simillar to the add function above

        mov     r4, r0      @ Save first argument
        mov     r5, r1      @ Save 2nd argument
        subs    r7, r4, r5  
        bvs     overflow1    @ Check for overflow
valid1:
        
        mov     r0, r7     @ Return value (valid)
        b        done1
overflow1:
        
        mov     r0, #0x80000000	      @ Return error (not valid)
done1:
        pop     {r4,r5,r7,lr}
        bx      lr       


        

negate:
        push    {r4,r7,lr}

        mov     r4, r0      @ Save first argument
        cmp		r4, #0x80000000 @ error check against smalllest number
		beq  	error3
		
        neg     r7, r4      @ negates num
        mov 	r0, r7		@ stores and returns value
		pop     {r4,r7,lr}
        bx      lr 
           
error3:
		mov		r0, #0x80000000	@ returns error
        pop     {r4,r7,lr}
        bx      lr 
        
        
        
        
        
absolute:
		push	{r4,r5,lr}
		
		mov		r4,	r0		@ saves first argument
		
		cmp		r4, #0x80000000		@ error check against smalllest number
		beq  	error4
		
		cmp		r4, #0
		bgt		done3		@ if value is already positive store and return
		
		neg 	r5, r4		@ otherwise negate and return value
		mov 	r0, r5

done3:       
		mov		r0,	r4
		pop		{r4,r5,lr}
		bx      lr
error4:
		mov		r0, #0x80000000	@ stores error value
		pop		{r4,r5,lr}
		bx      lr
		
		
		
		
divide:
		push	{r4,r5,r6,lr}
		
		mov		r4,	r0		@ stores arguments
		mov		r5, r1		
		cmp		r5, #0		@ checks for divison  by 0 and returns error if true
		beq		error1
		sdiv	r6, r4,r5	@ perfroms division	
        mov     r0, r6      @ Return value 
        b        done4
error1:
		mov		r0, #0x80000000
		
done4:
        pop     {r4,r5,r6,lr}
        bx      lr




mul:
		push	{r4,r5,r6,r7,lr}
		
		mov		r4,	r0		@ store arguments
		mov		r5, r1
		smull	r6, r7, r4,r5	@ use smull to multyply numbers and check for overflow
		cmp 	r6, #0		@ compares rlo to see if its greater or less then 0
		blt  	check1
		cmp 	r6, #0
		bgt  	check2
		
			
check1:     
		cmp		r7, #0xffffffff  @ check for overflow
		bne		overflow3
		b		valid3

check2: 
		cmp		r7, #0x00000000  @ check for overflow
		bne		overflow3
		b		valid3
valid3:
        mov     r0, r6      @ Return value (valid)
        b        done5
overflow3:
        mov     r0, #0x80000000      @ Return error (not valid)

done5:
        pop     {r4,r5,r6,r7,lr}
        bx      lr




power:
		push	{r4,r5,r6,r7,r8,lr}
		
		mov		r4,	r0
		mov		r5, r1
		mov		r6, #0		@ store arguments
		mov		r7, #1
		cmp		r5, #0		@ if power is negative return error
		blt 	error5
loop:
		cmp 	r5,r6
		ble     endloop
		smull   r7, r8, r4, r7	@ use smull to multyply numbers and check for overflow
		cmp 	r7, #0		@ very simillar to the multiply function
		blt  	check3
		cmp 	r7, #0		@ performs same checks
		bgt  	check4
		add		r6, r6, #1
		b		loop
check3:     
		cmp		r8, #0xffffffff		@ check for overflow
		bne		error5
		add		r6, r6, #1
		b		loop


check4: 
		cmp		r8, #0x00000000		@ check for overflow
		bne		error5
		add		r6, r6, #1
		b		loop
endloop:
		mov		r0, r7
        pop     {r4,r5,r6,r7,r8,lr}	@ Return value (valid)
        bx      lr
error5:
		mov		r0, #0x80000000		@ Return error (not valid)
		pop     {r4,r5,r6,r7,r8,lr}
        bx      lr
        
        


factorial:
		push	{r4,r6,r7,lr}
		
		mov		r4,	r0		@ store arguments
		mov		r6, #0
		mov		r7, #1
		
		cmp		r4, #-1
		ble		error2		@ over flow values would be less then 0 or greater then 12
		
		cmp		r4, #12
		bgt     error2
loop1:
		cmp 	r4,r6
		ble     endloop1	@ within safe range performs the factorial
		mul     r7, r4, r7
		sub		r4, r4, #1
		b		loop1

endloop1:
		mov		r0, r7		@ return value
        pop     {r4,r6,r7,lr}
        bx      lr
error2:
		mov		r0, #0x80000000 @ else return error value
		pop     {r4,r6,r7,lr}
        bx      lr



