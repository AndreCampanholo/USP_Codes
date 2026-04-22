	.data
		.align 2
		.text
		.globl main
main:		
		li a7, 5
		ecall
		mv s0, a0
		
		addi t0, zero, 1
		addi t1, zero, 0
loop:		bgt t0, s0, fim_loop
		add t1, t1, t0
		addi t0, t0, 1
		j loop
fim_loop:	li a7, 1
		mv a0, t1
		ecall
		li a7, 10
		ecall
