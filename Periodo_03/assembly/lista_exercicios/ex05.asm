		.data		
		.align 0
str_even:	.asciz "EVEN."
str_odd:	.asciz "ODD."
str_is:		.asciz " is "
		.align 2
		.text
		.globl main
main:
		li a7, 5
		ecall
		
		li a7, 1
		ecall
		
		mv t1, a0
		
		li a7, 4
		la a0, str_is
		ecall
		
		addi t0, zero, 2
		rem a0, t1, t0
		
		beq a0, zero, even
		j odd
even:		li a7, 4
		la a0, str_even
		ecall
		j end
odd:		li a7, 4
		la a0, str_odd
		ecall
	
end:		li a7, 10
		ecall