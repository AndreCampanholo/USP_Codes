		.data
		.align 0
str_src: 	.asciz "gui_pego"
		.align 2
str_dst:	.word

		.text
		.globl main
main:		
		la t0, str_src # t0 = endereço do primeiro byte de 'str_src'
		
		addi t3, zero, 0 # seta o contador t3 para 0		
loop_size:	lb s0, 0(t0) # s0 = byte da posícao t0 da string 'str_src'
		addi t3, t3, 1 # incrementa o contador
		addi t0, t0, 1 # incrementa o t0, posicionando-o no byte seguinte
		bne s0, zero, loop_size # termina o loop quando s0 alcança o terminador nulo
		
		addi a7, zero, 9 # syscall de alocação dinâmica de memória
		add a0, zero, t3 # a0 = quantidade de bytes a serem alocados
		ecall
		
		la t1, str_dst # t1 = endereço do primeiro byte de 'str_dst'
		sw a0, 0(t1) # salva a0 (endereço do primeiro byte alocado) em 'str_dst' == str_dst aponta para a0, primeiro byte alocado
		
		la t0, str_src # t0 = endereço do primeiro byte de 'str_src'
loop_copy:	lb s0, 0(t0) # carrega o byte atualmente apontado por t0 no reg s0 
		sb s0, 0(t1) # armazena o byte do reg s0 no endereço atual do reg t1
		addi t0, t0, 1 # incrementa t0
		addi t1, t1, 1 # incrementa t1
		bne s0, zero, loop_copy # quando encontra o terminador nulo encerra o loop
		
		addi a7, zero, 4 # syscall de imprimir string
		la a0, str_dst # seta 'str_dst' no reg a0 para ser printado
		ecall
		
		addi a7, zero, 10 # syscall de encerrar o programa
		ecall
		
