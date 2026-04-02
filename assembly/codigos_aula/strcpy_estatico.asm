		# strcpy estático
		.data
		.align 0
str_src:	.asciz "ponciano"
str_dst:	.space 9

		.text
		.align 2
		.globl main
main:		la t0, str_src # t0 = endereço do primeiro byte de 'str_src'
		la t1, str_dst # t1 = endereço do primeiro byte de 'str_dst'
		
loop_copy:	lb s0, 0(t0) # lê o conteúdo da mem(t0 + 0) e escreve em s0
		sb s0, 0(t1) # escreve o conteúdo de s0 em mem(t1 + 0)
		
		addi t0, t0, 1
		addi t1, t1, 1
		
		bne s0, zero, loop_copy # compara s0 com zero (verifica se chegou no terminador nulo)
		
		addi a7, zero, 4
		la a0, str_dst 	
		ecall # ecall de print de string
		
		addi a7, zero, 10
		ecall # ecall para encerrar o programa
		
		
		

	