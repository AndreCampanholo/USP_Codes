		.data
		.align 0
str_oi:		.asciz "Entre com um número maior ou igual a zero: "
str_resp1:	.asciz "O fatorial de "
str_resp2:	.asciz " é "
str_erro:	.asciz "O número deve ser maior ou igual a zero!"
		.align 2
		.text
		.globl main
main:
loop_oi:	addi a7, zero, 4
		la a0, str_oi
		ecall
		li a7, 5
		ecall
		bge a0, zero, continue
		li a7, 4
		la a0, str_erro
		ecall
		li a7, 11
		li a0, 10
		ecall
		j loop_oi
continue:	#a0 = número a ser calculado
		#a1 = retorno
		add s0, zero, a0
		jal fatorial #chamada da função fatorial
		#impressão da resposta
		li a7, 4
		la a0, str_resp1
		ecall
		li a7, 1
		mv a0, s0
		ecall
		li a7, 4
		la a0, str_resp2
		ecall
		addi a7, zero, 1
		mv a0, a1
		ecall
		
		addi a7, zero, 10
		ecall
		
fatorial:	add t0, zero, s0
		addi a1, zero, 1
loop_fat:	mul a1, t0, a1
		addi t0, t0, -1
		bne t0, zero, loop_fat
		jr ra #voltar para onde a função foi chamada
		
		
		
		
		
