		.data
		.align 0
mult_sym:	.asciz " x "
eq_sym:		.asciz " = "
		.align 2
		.text
		.globl main
main:
		li a7, 5
		ecall
		add s0, zero, a0
		addi t1, zero, 10
		
		addi t0, zero, 1
loop:		bgt t0, t1, fim_loop
		li a7, 1
		mv a0, s0
		ecall
		li a7, 4
		la a0, mult_sym
		ecall
		li a7, 1
		mv a0, t0
		ecall
		li a7, 4
		la a0, eq_sym
		ecall
		mul a0, s0, t0
		li a7, 1
		ecall
		li a7, 11
		li a0, 10
		ecall
		addi t0, t0, 1
		j loop
fim_loop:	li a7, 10
		ecall	