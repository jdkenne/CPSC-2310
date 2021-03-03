/**************************
 *Kevin Mody                                
 *CPSC2310 Fall 2020 Sec 001            
 *UserName: kmody                               
 *Instructor:  Dr. Yvon Feaster  
*************************/
/************************
 * This file contains a function
 * that returns the absolute value of all numbers
 * in an array 
 ************************/

.global absVal

/****************
 * function name: absVal
 * inputs:
	r0: array address
	r1: array size
 * return value:
	r0: absolute value of all ints int the array added together
 * register usage:
	r0 and r1: inputs
	r2: loop variable (i)
	r3: 4 times the loop variable (4i)
  		*r0 + r3 would then be the address of the current int*
	r4: current array value (arr[i])
	r5: total
***************/

absVal:
	push	{r3, r4, r5, lr}
	
	mov	r2, #0		@initializing loop variable
	mov r3, #0			@initialize remaining variables
	mov r4, #0
	mov r5, #0

loop:
	cmp 	r2, r1
	bge 	done
	lsl 	r3, r2, #2	@ r3 = 4i
	ldr 	r4, [r0, r3]	@ r4 = arr[i]
	cmp		r4, #0		@compare arr[i] and 0
	bl		add			@branch to add or subtract
	bge		subtract			@branch to add or subtract
add:
	add		r5,r5,r4			@update total
	bal			increment			@branch to appropriate location

subtract:
	sub		r5,r5,r4			@update total
	bal			increment			@branch to appropriate location

increment:
	add 	r2, r2, #1	@i++
	bal 	loop
done:
	mov	r0, r5		@setting return value
	pop	{r3, r4, r5, pc}
