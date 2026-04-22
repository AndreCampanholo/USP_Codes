		.data
		.align 2
		.text
		.globl main
main:
		li a7, 5
		ecall
		
		add t0, zero, a0
		addi s0, zero, 1
loop:		beq t0, zero, fim_loop
		li a7, 1
		mv a0, t0
		ecall
		sub t0, t0, s0
		li a7, 11
		li a0, 32
		ecall
		j loop
fim_loop:	li a7, 10
		ecall