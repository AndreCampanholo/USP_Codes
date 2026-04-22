		.data # dados
		.align 0 # alinha a memória para 1 byte (2^0)

str1:		.asciz "Hello World ++!"
str2:		.asciz "Hello World --!"
	
		.text # código
		.align 2 # alinha a memória para 4 bytes (2^2)
	
		.globl main # começo do código
main:
		addi a7, zero, 5  # essas 2 linhas leem da entrada um número inteiro e armazenam no reg a0
		ecall		 
	
		add s0, a0, zero # copia o valor do reg a0 ao s0
		blt s0, zero, print_neg # se s0 < 0  (blt: branch if less than)
	
		addi a7, zero, 4
		la a0, str1	   # essas 3 linhas imprimem str1
		ecall
	
		j the_end
		
print_neg:	addi a7, zero, 4
		la a0, str2        # branch de impressão da str2
		ecall
		
the_end:	addi a7, zero, 1
		add a0, s0, zero   # imprimir um número digitado pelo usuário
		ecall
		
		li a7, 10
		ecall
