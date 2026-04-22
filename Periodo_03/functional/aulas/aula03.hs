main :: IO()
main = do
    print $ 5 +++++ 7 --uso do operador infix
    print $ (+++++) 5 7 --uso de um operador infix como prefix -> uso de ()
    print $ (+) 5 7 --idem acima
    print $ mod 12 5 --uso de operador prefix
    print $ 12 `mod` 5 --uso de operador prefix como infix -> uso de ``
    print $ 4 `pertence` [2, 3, 4, 10, 1]
    print $ pertence 4 [5, 1, 7, 3] --nesse caso () não é necessário pois o nome da função não é só símbolos
    print $ "Ades" `pertence` ["Adenilso", "da", "Silva", "Simão"]
    print $ fat 10
    print $ encontra (>100) [1, 10, -2, 3]
    print $ encontra (<0) [1, 10, -2, 5, -3]
    -- print $ divide 4 0 
    print $ safeDivide 4 0
    print $ div 3 2

-- Função PREFIX: o nome da função é definido antes dos parâmetros
x' :: Num a => a -> a
x' x = x + 1

-- Função INFIX: o nome da função é declarado entre os parâmetros.
x +++++ y = 2*x + 3*y

-- declaração de uma função infix cujo nome não é composto somente de símbolos: preciso usar ``
_ `pertence` [] = False
e `pertence` (x:xs)
    | e == x = True
    | otherwise = e `pertence` xs
    
{-TIPAGEM DE FUNÇÕES: é uma boa prática tipar as funções criadas no seu código, para melhor legibilidade e entendibilidade. No entanto, deve-se buscar a tipagem mais geral possível (menos restritiva), que permite que aquela função seja na maior variedade de casos. Vejamos um exemplo de uma tipagem restritiva:-}
f1' :: Int -> Int
f1' x = x + 2
{-Essa função não aceita um x = 7.2, isto é, um número float ou double. É demasiadamente restritiva a tipagem atribuída à função. Poderíamos, então, atribuir o tipo double... há uma solução mais geral que essa:-}
f2' :: Num a => a -> a
f2' x = x * 2
{-TYPECLASS: usamos uma typeclass, a 'Num'. Ela permite que essa função receba todo tipo de dado numérico (Int, Float, Double, Integer).-}

fat :: (Eq a, Integral a) => a -> a --Deve ser posível ver se n == 0, fazer operações aritméticas com n e, ainda, não permitir que n seja decimal, logo, fat deve ser das typeclasses 'Eq' e 'Integral'.
fat 0 = 1
fat n = n * fat (n - 1)

{- Tipagem da função pertence, para que possa aceitar Int, String, Bool, Integer, deve ser da typeclass 'Eq', que abriga todos esses tipos de variáveis. Esta typeclass abriga tipos de variáveis que é possível verificar se são iguais.
pertence :: (Eq a) => a -> [a] -> Bool 
_ `pertence` [] = False
e `pertence` (x:xs)
    | e == x = True
    | otherwise = e `pertence` xs-}

g :: (Num a, Ord a) => a -> a
g x
    | x > 0 = x
    | otherwise = -x

qs :: Ord a => [a] -> [a]
qs [] = []
qs [x] = [x]
-- qs (x:xs) qs 

encontra :: (a -> Bool) -> [a] -> Maybe a
encontra f [] = Nothing
encontra f (x:xs)
    | f x = Just x
    | otherwise = encontra f xs

divide :: (Integral a) => a -> a -> a
divide x y = x `div` y 

safeDivide :: (Integral a) => a -> a -> Maybe a
safeDivide _ 0 = Nothing
safeDivide x y = Just $ x `div` y