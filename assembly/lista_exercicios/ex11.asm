		.data
		.align 0
isPrime:	.asciz "PRIME"
notPrime:	.asciz "NOT PRIME"
str_is:		.asciz " is "
		.align 2
		.text
		.globl main
main:
		li a7, 5
		ecall
		mv s0, a0
		
		addi t0, zero, 2
		div s1, s0, t0
		addi t1, zero, 1
		
		beq s0, t1, not_prime
loop:		bgt t0, s1, prime
		rem t1, s0, t0
		beq t1, zero, not_prime
		addi t0, t0, 1
		j loop
prime:		li a7, 1
		ecall
		li a7, 4
		la a0, str_is
		ecall
		li a7, 4
		la a0, isPrime
		ecall
		j fim_loop
not_prime:	li a7, 1
		ecall
		li a7, 4
		la a0, str_is
		ecall
		li a7, 4
		la a0, notPrime
		ecall
fim_loop:	li a7, 10
		ecall
		