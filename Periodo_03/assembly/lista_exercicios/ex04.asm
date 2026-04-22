		.data
		.align 2
		.text
		.globl main
main:
		addi a7, zero, 5
		ecall
		
		mv t0, a0
		
		addi t1, zero, 2
		
		mul a0, t0, t1
		
		li a7, 1
		ecall
		
		li a0, 10
		li a7, 11
		ecall
		
		addi t1, zero, 3
		
		mul a0, t0, t1
		
		addi a7, zero, 1
		ecall
		
		addi a7, zero, 10
		ecall