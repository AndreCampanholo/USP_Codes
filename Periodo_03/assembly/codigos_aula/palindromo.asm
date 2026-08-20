		.data
		.align 0
str_sim:	.asciz "SIM\n"
str_nao:	.asciz "NAO\n"
		.align 2
p_str:		.word
		.text
		.globl main
main:	
		li a7, 8
		la a0, p_str
		addi a1, zero, 100
		ecall
		
		la s0, p_str # so = ponteiro para a string
		
		jal ehPalindromo
		
		li a7, 10
		ecall
		
ehPalindromo:
		addi t1, zero, 0
		lb t2, 0(s0)
		addi t3, zero, 10
loop_tamanho:		
		beq t2, t3, fim_tamanho
		addi t1, t1, 1
		add t4, zero, t1
		add t4, s0, t4
		lb t2, 0(t4)
		j loop_tamanho
fim_tamanho:
		addi s1, t1, 0 # s1 = tamanho válido da string digitada
		beq s1, zero, nao
		
		addi t1, zero, 0
		addi t2, s1, -1
verificar_par:	
		add t3, s0, t1
		lb t3, 0(t3)
		add t4, s0, t2
		lb t4, 0(t4)
		
		addi t1, t1, 1
		addi t2, t2, -1
		
		beq t3, t4, continua_ou_nao
		bne t3, t4, nao
		j verificar_par
continua_ou_nao:
		blt t2, t1, sim
		j verificar_par
sim:
		li a7, 4
		la a0, str_sim
		ecall
		
		jr ra
nao:
		li a7, 4
		la a0, str_nao
		ecall
		
		jr ra