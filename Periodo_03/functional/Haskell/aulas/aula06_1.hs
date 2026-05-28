main :: IO()
main = do
    print d1
    print d2
    print $ map mes $ filter ((<5) . mes) [d1, d2]
    print amir
    print (vendas amir)

-- Definição de uma struct em Haskell. Além dos campos da Struct, essa linha define o construtor da struct.
data Data = NovaData {dia :: Integer, mes :: Integer, ano :: Integer}

instance Show Data where
    show :: Data -> String
    show (NovaData dia mes ano) =
        show dia ++ "/" ++ show mes ++ "/" ++ show ano

-- d1 e d2 criados por meio do construtor da struct Data.
d1 :: Data
d1 = NovaData { dia = 26, mes = 03, ano = 2007}
d2 :: Data
d2 = NovaData { dia = 9, mes = 11, ano = 2001}

-- Equivalente a um typedef em C. Diferente de uma struct e da função 'data' pois não exige um construtor.
type Idade = Integer
-- caso não tivesse a linha de definição de tipo de 'idade', essa variável seria um integer.
idade :: Idade
idade = 19

data Venda = Venda { vendedor :: Vendedor, cliente :: String, valor :: Integer}

data Vendedor = Vendedor {
    nome :: String,
    cpf :: Integer,
    aniversario :: Data,
    vendas :: [Venda]
}

instance Show Vendedor where
    show :: Vendedor -> String
    show (Vendedor nome cpf aniversario vendas) =
        "Vendedor { nome = " ++ show nome ++
        ", cpf = " ++ show cpf ++
        ", aniversario = " ++ show aniversario ++
        ", vendas = " ++ show (length vendas) ++ " venda(s) }"

instance Show Venda where
    show :: Venda -> String
    show (Venda vendedor cliente valor) =
        "Venda { vendedor = " ++ show vendedor ++
        ", cliente = " ++ show cliente ++
        ", valor = " ++ show valor ++ " }"

amir :: Vendedor
amir = Vendedor { nome = "Amir", cpf = 1, aniversario = d2, vendas = [v1]}
v1 :: Venda
v1 = Venda { vendedor = amir, cliente = "Jeff", valor = 4000}