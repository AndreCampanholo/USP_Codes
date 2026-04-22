		.data
		.align 2
		.text
		.globl main
main:
		addi a7, zero, 5
		ecall
		
		mv t0, a0
		
		addi a7, zero, 5
		ecall
		
		mv t1, a0
		
		add a0, t0, t1
		
		addi a7, zero, 1
		ecall
		
		addi a7, zero, 10
		ecall