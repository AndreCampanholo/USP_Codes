import object_oriented.Python.JogoTabuleiro.tabuleiro as tab

# Leitura das strings de entrada
config_inicial_com_espacos = input().strip()
if " " in config_inicial_com_espacos:
	config_inicial = config_inicial_com_espacos.split()
else:
	config_inicial = config_inicial_com_espacos
movimentos = input()

# Criação do tabuleiro
meu_tabuleiro = tab.tabuleiro(config_inicial)

# Aplicação dos movimentos
meu_tabuleiro.applyMoves(movimentos)