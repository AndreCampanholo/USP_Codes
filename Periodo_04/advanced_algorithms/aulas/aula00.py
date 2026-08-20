# temos que colocar 8 rainhas sem que elas possam se matar
# tabuleiro 8x8, com a primeira rainha escolhida por nós

# entrada caso de teste
primeira_rainha = [1, 1]

# estrutura auxiliar
# índice indica linha, valor coluna
idx_linhas_v_colunas = [-1]*8

def check_diagonal(i, j):
	for linha, coluna in enumerate(idx_linhas_v_colunas):
		if coluna != -1:
			continue
		if abs(i - linha) == abs(j - coluna):
			return False
	return True

def coloca_rainha():
	global idx_linhas_v_colunas

	# condição de parada: acabamos
	if -1 not in idx_linhas_v_colunas:
		return True

	for i in range(8):

		# já preenchida
		if idx_linhas_v_colunas[i] != -1:
			continue

		# checamos então todas as possibilidades
		for j in range(8):
			# checa se posição foi usada
			if j in idx_linhas_v_colunas:
				continue

			# checa se pode na diagonal
			if not check_diagonal(i, j):
				continue

			idx_linhas_v_colunas[i] = j

			# se continuação deu certo acabou
			# senão tiramos a rainha desse lugar
			if coloca_rainha():
				return True
			else:
				idx_linhas_v_colunas[i] = -1

	return False


def main():
	global idx_linhas_v_colunas
	idx_linhas_v_colunas[primeira_rainha[0]] = primeira_rainha[1]

	coloca_rainha()
	print(idx_linhas_v_colunas)


if __name__ == '__main__':
    main()