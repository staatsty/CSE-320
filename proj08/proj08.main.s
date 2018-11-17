
/********************************************************************
proj 08
output char counts from a input file
uses ARM assembly language 
********************************************************************/

        .global main

        .text
main:   push    {lr}

		
		mov     r4, #0      @ Initialize decimal char count 
        mov     r5, #0      @ Initialize whitespace count
        mov     r6, #0      @ Initialize char count
		mov     r8, #0		@ Initialize hexadecimal char count
		mov     r9, #0		@ Initialize letter count
		mov		r10, #0		@ Intilize newline count
		
loop:   bl      getchar     @ Read one character (returned in r0)
        
        cmp     r0, #-1     @ Checks for EOF
        beq		end			@ Ends loop if thats the case
        
        
        bl		putchar		@ Put char is used to display input

if0:	cmp     r0, #0x00   @ this if block checks if its a valid ASCII char
		blt		endif0		@ If not it skips the char
		cmp     r0, #0x7F
		bgt     endif0


then0:	add     r6, r6, #1  @ Increment character count

endif0: 




        
        
if1:	cmp     r0, #'0'	@ This if block finds the number of decimal chars
		blt		endif1
		cmp     r0, #'9'
		bgt     endif1


then1:	add 	r4, r4, #1  @ r4 is incremented if char is between 0-9

endif1:


if2:	cmp		r0, #'0'	@ This if block finds the number of octal chars
		blt		endif2
		cmp		r0,	#'7'
		bgt		endif2

then2:	add		r7, r7, #1	@ r7 is incremented if char is between 0-7

endif2:



if3:	cmp		r0, #'0'	@ This if block find number of hex chars
		blt		endif3
		cmp		r0,	#'F'
		bgt		endif3

then3:	add		r8, r8, #1	@ r8 is incremented if char is between 0-F

endif3:




if4:	cmp		r0, #'a'	@ This if block finds number of hex chars(lower)
		blt		endif4
		cmp		r0,	#'f'
		bgt		endif4

then4:	add		r8, r8, #1  @ r8 is incremented if char is between a-f

endif4:


if5:	cmp		r0, #'a'	@ This if block finds letters(lower)
		blt		endif5
		cmp		r0,	#'z'
		bgt		endif5

then5:	add		r9, r9, #1  @ r9 is incremented if char is between a-z

endif5:


if6:	cmp		r0, #'A'	@ This if block finds letters(upper)
		blt		endif6
		cmp		r0,	#'Z'
		bgt		endif6

then6:	add		r9, r9, #1	@ r9 is incremented if char is between A-Z
		

endif6:


if7:	cmp     r0, #0x0a  @ This if block finds whitespace
		bne     endif7

then7:	add		r10, r10, #1 @ r10 is incremented if char is newline
		add		r5, r5, #1   @ r5 is as well

endif7:




if8:	cmp     r0, #0x09	@ This if block finds whitespace
		bne     endif8

then8:	add		r5, r5, #1	@ r5 is incremented if char is tab

endif8:




							@this block is similar to example18
if:     cmp     r0, #0x20   @ Compare return value to blank
        bne     endif       @ If blank not found, skip increment

then:   add     r5, r5, #1  @ Increment blank count




endif:  cmp     r0, #0x0a   @ Compare return value to newline
		
        b       loop        @ Branch to top of loop

end:    ldr     r0, =fmt1   @ First arg  -- address of format string
        mov     r1, r6    	@ Second arg -- character count
        bl      printf      @displays result
        
        ldr		r0,=fmt2    @this is just repeated for all outputs
        mov 	r1, r10
        bl 		printf
        
        ldr		r0,=fmt3
        mov 	r1, r5
        bl 		printf
        
        ldr		r0,=fmt4
        mov 	r1, r7
        bl 		printf
        
        ldr		r0,=fmt5
        mov 	r1, r4
        bl 		printf
        
        ldr		r0,=fmt6
        mov 	r1, r8
        bl 		printf
        
        ldr		r0,=fmt7
        mov 	r1, r9
        bl 		printf

        pop     {lr}
        bx      lr


fmt1:   .asciz  "\nTotal number of chars: %d\n"
fmt2:   .asciz  "\nTotal number of newlines: %d\n"
fmt3:   .asciz  "\nTotal number of whitespace: %d\n"
fmt4:   .asciz  "\nTotal number of Octal digits: %d\n"
fmt5:   .asciz  "\nTotal number of Decimal digits: %d\n"
fmt6:   .asciz  "\nTotal number of Hexadecimal digits: %d\n"
fmt7:   .asciz  "\nTotal number of letters: %d\n"


