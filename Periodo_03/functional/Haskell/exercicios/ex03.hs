main :: IO ()
main = do
    loop []
    putStr "Encerrando."

-- Laço principal de execução
loop :: [(String, String)] -> IO ()
loop contatos = do
    line <- getLine
    case parseComando line of
        Sair -> return ()
        comando -> do
            novosContatos <- executaComando comando contatos
            loop novosContatos

-- Retorna um true se nome está na lista, false caso contrário
nomeEstaNaLista :: Eq nome => nome -> [(nome, tel)] -> Bool
nomeEstaNaLista _ [] = False
nomeEstaNaLista nome ((x, _):xs)
    | nome /= x = nomeEstaNaLista nome xs
    | otherwise = True

-- Percorre a lista de contatos até o nome buscado e recupera o telefone, imprimindo "nome - telefone" ou mensagem de erro caso não encontre o contato
buscarTelefonePorNome :: String -> [(String, String)] -> IO ()
buscarTelefonePorNome _ [] = putStrLn "Contato nao encontrado."
buscarTelefonePorNome nome ((x, tel):xs)
    | nome == x = putStrLn (x ++ " - " ++ tel)
    | otherwise = buscarTelefonePorNome nome xs

-- Adiciona um contato na lista de contatos
addNomeTelefone :: String -> String -> [(String, String)] -> [(String, String)]
addNomeTelefone nome telefone contatos = (nome, telefone) : filter (\(n, _) -> n /= nome) contatos
-- Caso o nome já existam, exclui o antigo contato e insere o contato com o telefone atualizado no início da lista

-- Chama a funcionalidade de buscar por nome. Retorna a lista de contatos
buscarNome :: String -> [(String, String)] -> IO [(String, String)]
buscarNome nome contatos = do
    buscarTelefonePorNome nome contatos
    return contatos

-- Percorre a lista de contatos inteira imprimindo cada contato
listarContatos :: [(String, String)] -> IO [(String, String)]
listarContatos [] = return []
listarContatos ((nome, tel):xs) = do
    putStrLn (nome ++ " - " ++ tel)
    resto <- listarContatos xs
    return ((nome, tel) : resto)

-- Auxiliar na funcionalidade de remoção que imprime mensagem de confirmação ou erro.
encontrouRemover :: Eq t => t -> [(t, b)] -> IO ()
encontrouRemover _ [] = putStrLn "Contato nao encontrado."
encontrouRemover nome ((n, _):xs)
    | nome == n = putStrLn "Contato removido."
    | otherwise = encontrouRemover nome xs

-- Função que de fato remove um contato da lista de acordo com o nome informado
removerPorNome :: String -> [(String, String)] -> IO [(String, String)]
removerPorNome nome contatos = do
    encontrouRemover nome contatos
    return (filter (\(n, _) -> n /= nome) contatos)

-- Executa o comando passado pela função parseComando
executaComando :: Comando -> [(String, String)] -> IO [(String, String)]
executaComando comando contatos =
    case comando of
        Adicionar nome telefone -> return (addNomeTelefone nome telefone contatos)
        Buscar nome -> buscarNome nome contatos
        Remover nome -> removerPorNome nome contatos
        Listar -> listarContatos contatos
        Sair -> return contatos
        Invalido -> do -- Tratamento de entradas inválidas
            putStrLn "Comando invalido"
            return contatos

-- Define o tipo de dado "Comando", devido à maneiro como as operações são escritas na entrada
data Comando
  = Adicionar String String
  | Buscar String
  | Remover String
  | Listar
  | Sair
  | Invalido

-- De acordo com a entrada, atribui o nome e o telefone informados a variáveis e determina qual comando deve ser executada
parseComando :: String -> Comando
parseComando linha =
  case words linha of
    ["adicionar", nome, telefone] -> Adicionar nome telefone
    ["buscar", nome]              -> Buscar nome
    ["remover", nome]             -> Remover nome
    ["listar"]                    -> Listar
    ["sair"]                      -> Sair
    _                             -> Invalido