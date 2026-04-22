		.data
		.align 0
str_src:	.asciz "teste"
		.align 2
p_str_dst:	.word 
		.text
		.align 2
		.globl main
main:
		#calcula tamanho
		#lê string
		#t0 = endereço da string
		#s0 = bytes da string str_src
		#t3 = contador
		la t0, str_src
		addi t3, zero, 0
loop_tam:	lb s0, 0(t0)
		addi t0, t0, 1
		addi t3, t3, 1
		bne s0, zero, loop_tam
		#alocar t3 bytes na heap (a7 = 9)
		li a7, 9 
		add a0, zero, t3 #(a0 = t3 bytes)
		ecall #a0 recebe endereço do primeiro byte alocado
		#armazenar a0 em p_str_dst
		#t1 = endereço de p_str_dst
		la t1, p_str_dst
		sw a0, 0(t1)
		#loop para copiar da str_src para a0
		#t0 = endereço da str_src
		#t1 = endereço destino
		la t0, str_src
		la t1, p_str_dst
		lw t2, 0(t1)
loop_cpy:	lb s0, 0(t0)
		sb s0, 0(t2)
		addi t0, t0, 1
		addi t2, t2, 1
		bne s0, zero, loop_cpy
		
		addi a7, zero, 4
		la t1, p_str_dst
		lw a0, 0(t1)
		ecall
		
		li a7, 10
		ecall
		
		
		
		