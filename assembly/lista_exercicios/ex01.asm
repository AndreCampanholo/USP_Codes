		.data
		.align 0
str:		.word
		.text
		.globl main
main:		
		addi a7, zero, 8
		la a0, str
		addi a1, zero, 10
		ecall

		addi a7, zero, 4
		la a0, str
		ecall
		
		addi a7, zero, 10
		ecall