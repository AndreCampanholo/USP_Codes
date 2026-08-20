		.data
		.align 2
vetor:		.word
		.text
		.globl main
main:
		addi a7, zero, 5
		ecall
		
		add s0, zero, a0 # s0 = n (qtd de números do vetor)
		addi t1, zero, 0
		
		addi t2, zero, 4
		mul t2, s0, t2
		
		addi a7, zero, 9
		mv a0, t2
		ecall
		mv s1, a0 # s1 = ponteiro para primeiro byte do vetor
		
loop_leitura: 
		beq t1, s0, fim_leitura
		addi a7, zero, 5
		ecall
		
		addi t2, zero, 4
		mul t2, t1, t2
		
		add t2, s1, t2
		sw a0, 0(t2)
		
		addi t1, t1, 1	
		
		j loop_leitura
fim_leitura:
		addi t1, zero, 0
		jal imprimir_vetor
		
		li a7, 10
		ecall
		
imprimir_vetor:
		# alocar memoria para o ra e para t1
		addi sp, sp, -8
		sw ra, 0(sp)
		sw t1, 4(sp)
		
		beq t1, s0, caso_base
		
		addi t2, zero, 4
		mul t2, t1, t2
		
		add t2, s1, t2
		lw t3, 0(t2)  
		
		li a7, 1
		mv a0, t3
		ecall
		
		li a7, 11
		addi a0, zero, 32
		ecall
		
		addi t1, t1, 1
		
		jal imprimir_vetor
caso_base:
		lw ra, 0(sp)
		addi sp, sp, 8
		jr ra