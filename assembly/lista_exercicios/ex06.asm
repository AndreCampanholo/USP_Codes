		.data
		.align 2
		.text
		.globl main
main:
		li a7, 5
		ecall
		mv t1, a0
		
		li a7, 5
		ecall
		mv t2, a0
		
		bge t1, t2, num1
		li a7, 1
		mv a0, t2
		ecall	
		j end			
num1:		li a7, 1
		mv a0, t1
		ecall
end:		li a7, 10
		ecall