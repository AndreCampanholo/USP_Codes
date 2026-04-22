		.text
		.align 2 #alinha memória para entrada de número inteiro
		.globl main #instancia a main
main:		addi a7, zero, 5 #diretiva para leitura de entrada de usuário
		ecall #lê entrada do usuário
		add s0, a0, zero #s0 armazena o valor informado pelo usuário
		add t0, zero, s0 #t0 armazena valor a ser decrementado
		addi t1, zero, 1 #valor de retorno
loop:		beqz t0, fim_loop #se t0 == 0, vai p/ fim_loop
		mul t1, t0, t1 #multiplica o valor de t0 com o de t1 e armazena em t1
		addi t0, t0, -1 #decrementa o t0
		j loop #retorna ao começo do loop
fim_loop:	addi a7, zero, 1 #diretiva para imprimir o resultado armazenado no a0
		add a0, t1, zero #seta o valor que estava no t1 no a0
		ecall #chama a impressão do a0
		addi a7, zero, 10 #diretiva para finalizar o programa
		ecall #finaliza, de fato, o programa
		
		