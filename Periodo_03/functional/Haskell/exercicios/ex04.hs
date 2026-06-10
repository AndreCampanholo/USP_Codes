import Data.Maybe (mapMaybe)
import Text.Read (readMaybe)
import Data.List (sortBy)

main :: IO()
main = do
    line <- getLine -- Lê a linha de entrada
    let xs = map read (words line) :: [Int] -- Divide a entrada nos espaços
    let [n1, n2, n3, n4] = xs -- Atribui cada valor inteiro a uma variável

    indicadores <- lerArquivoCsv "dados.csv" -- Lê o arquivo csv e armazena uma lista de structs "Indicadores"
    print $ clausula1 indicadores n1 -- Imprime a soma resultante da cláusula 1
    print $ clausula2 indicadores n2 n3 -- Imprime a soma resultante da cláusula 2
    mapM_ putStrLn (clausula3 indicadores n4) -- Imprime os nomes do países retornados pela cláusula 3

-- Definição da struct Indicadores que contém campos para cada coluna do arquivo csv
data Indicadores = Indicadores {
    country :: String,
    confirmed :: Int,
    deaths :: Int,
    recovery :: Int,
    active :: Int
}

-- Implementação da cláusula 1
clausula1 :: [Indicadores] -> Int -> Int
clausula1 indicadores n1 = sum (map active (filter (\paises -> confirmed paises >= n1) indicadores))

-- Implementação da cláusula 2
clausula2 :: [Indicadores] -> Int -> Int -> Int
clausula2 indicadores n2 n3 =
        sum (map deaths (take n3 (sortBy (\a b -> compare (confirmed a) (confirmed b)) selecionados)))
    where
        selecionados = take n2 (sortBy (\a b -> compare (active b) (active a)) indicadores)

-- Implementação da cláusula 3
clausula3 :: [Indicadores] -> Int -> [String]
clausula3 indicadores n4 =
        map country (sortBy (\a b -> compare (country a) (country b)) ordenados)
    where
        ordenados = take n4 (sortBy (\a b -> compare (confirmed b) (confirmed a)) indicadores)

-- Função que realiza a leitura do arquivo csv: armazena cada uma das linhas do csv e chama a função de parse
lerArquivoCsv :: FilePath -> IO [Indicadores]
lerArquivoCsv nomeArquivo = do
    conteudo <- readFile nomeArquivo
    let linhas = lines conteudo
    return (mapMaybe parseIndicadores linhas)

-- Função que cria Indicadores a partir das linhas do csv
parseIndicadores :: String -> Maybe Indicadores
parseIndicadores linha =
    case splitVirgulas linha of -- Chama a função que elimina as vírgulas de cada linha do arquivo csv
        [pais, confirmados, obitos, recuperados, ativos] -> do
            confirmedValor <- readMaybe confirmados -- Usa readMaybe para salvar os valores antes textuais (String) como inteiros
            deathsValor <- readMaybe obitos
            recoveryValor <- readMaybe recuperados
            activeValor <- readMaybe ativos
            return Indicadores -- Cria de fato a struct com os valores
                { country = pais,
                confirmed = confirmedValor,
                deaths = deathsValor,
                recovery = recoveryValor,
                active = activeValor
                }
        _ -> Nothing -- Caso algum dos campos esteja faltando ou haja alguma falha no arquivo csv retorna Nothing

-- Função que elimina as vírgulas em cada linha retirada do arquivo csv
splitVirgulas :: String -> [String]
splitVirgulas [] = [""]
splitVirgulas (c:cs)
  | c == ','  = "" : splitVirgulas cs
  | otherwise = (c : head resto) : tail resto
  where
    resto = splitVirgulas cs

