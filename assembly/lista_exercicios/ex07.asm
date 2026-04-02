		.data
		.align 2
		.text
		.globl main
main:
		li a7, 5
		ecall
		mv s0, a0
		
		addi t0, zero, 1
loop:		beq t0, s0, fim_loop
		li a7, 1
		mv a0, t0
		ecall
		addi t0, t0, 1
		li a7, 11
		li a0, 32
		ecall
		j loop
fim_loop:	li a7, 1
		mv a0, s0
		ecall
		
		li a7, 10
		ecall