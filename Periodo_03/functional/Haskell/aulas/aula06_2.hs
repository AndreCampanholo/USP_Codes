import Data.List
import Data.Maybe
import Data.Ord
import System.IO

data Data = Data {ano :: Integer, mes :: Integer, dia :: Integer}
  deriving (Show, Read)

d1 = Data {ano = 2026, mes = 5, dia = 21}

d2 = Data {ano = 2019, mes = 3, dia = 12}

d3 = Data {ano = 2016, mes = 7, dia = 9}

-- d4 = Data {ano = 2011} => é possível criar a struct sem todos os campos completos, mas não é recomendável (warning)

-- Type tipo é igual ao typedef em C => sinônimo
type Idade = Integer

type Venda = Integer

-- Definição da struct, em que o construtor é a string Vendedor (em azul)
data Vendedor = Vendedor
  { nome :: [Char],
    cpf :: [Char],
    uf :: [Char],
    aniversario :: Data,
    dependente :: [Idade],
    vendas :: [Venda]
  }
  deriving (Show, Read)

processaVendedores :: [Char] -> [Vendedor]
processaVendedores l = map read $ lines l

-- A função lines divide a string de entrada (arquivo completo) em linhas individuais
-- map read aplica read a cada linha, convertendo cada string no formato da struct Vendedor

main :: IO ()
main = do
  print d1
  print $ map ano [d1, d2, d3] -- Retorna os anos de todas as datas
  print $ filter ((< 5) . mes) [d1, d2, d3] -- Retorna todas as datas anteriores ao mês 05 (maio)
  -- print $ d4 {mes = 1, dia = 1} => Se a struct for incompleta, é possível completá-la na main

  -- Como Haskell usa Lazy Computation, o arquivo só é lido quando o programa precisa das informações contidas nele.
  -- Assim, o comando Close deve estar depois de todos os processamentos desejados (passos: abertura, processamento, fechamento)
  h <- openFile "vendedores.txt" ReadMode
  l <- hGetContents h
  let vendedores = processaVendedores l
  print vendedores
  hClose h -- Como o programa já processou os vendedores uma vez, é possível fechar o arquivo antes das outras impressões
  
  print $ sort $ map nome vendedores -- Imprime os nomes dos vendedores em ordem alfabética
  print $ sort $ map nome $ filter ((== "SP") . uf) $ vendedores
  print $ sort $ map nome $ take 3 $ sortBy (comparing (length . dependente)) $ vendedores
  print $ sum $ map (sum . vendas) $ filter ((== "RJ") . uf) $ vendedores -- Soma de todas as vendas
  print $ nome $ last $ sortBy (comparing (sum . vendas)) $ vendedores -- Retorna o nome do vendedor com o maior número de vendas
  print $ map nome $ take 2 $ sortBy (flip (comparing (sum . vendas))) $ vendedores -- flip inverte a ordenação da lista (reverse é uma opção também, mas ele deve estar entre $ $ antes do sortBy)
  print $ map nome $ filter ((> 0) . length . (filter (< 18)) . dependente) $ vendedores -- Retorna todos os vendedores com dependentes menores de idade