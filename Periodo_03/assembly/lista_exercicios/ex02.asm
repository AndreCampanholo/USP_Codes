		.data
		.align 2
		.text
		.globl main
main:
		addi a7, zero, 5
		ecall
		
		addi a7, zero, 1
		ecall
		
		addi a7, zero 10
		ecall