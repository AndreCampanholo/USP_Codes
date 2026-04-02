		.data
		.text
		.align 2
		.globl main
main:
		addi a7, zero, 5 #ler número de entrada
		ecall
		
		add s0, zero, a0 #salva o valor de entrada no s0
		
		jal fatorial #desvio para o procedimento do cálculo do fatorial
		
		li a7, 1 #syscall para imprimir o fatorial
		add a0, zero, a1 #a0 = resultado do fatorial (armazenado em a1)
		ecall
		
		addi a7, zero 10 #syscall para encerrar o programa
		ecall
		
fatorial:	addi sp, sp, -8 #empilhar 'ra' e 'a0'
		sw ra, 0(sp)
		sw a0, 4(sp)
		
		beq a0, zero, retorna1
		#se a0 não é zero
		addi a0, a0, -1
		
		jal fatorial
		addi a0, a0, 1
		mul a1, a1, a0
		j retorna_fat
		
retorna1:	addi a1, zero, 1 #seta a1 = 1
	
retorna_fat:	#desempilhar
		lw ra, 0(sp)
		lw a0, 4(sp)
		addi sp, sp, 8
		jr ra #retorna