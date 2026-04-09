import Distribution.SPDX (LicenseId(LGPL_2_0_only))
-- MONAD
-- Falando sobre funções que podem falhar: uso de "Maybe"
-- Ex: f :: a -> Maybe a
main :: IO()
main = do
    print "HW"
    print $ f 0
    print $ f 100
    print $ f 0.01
    print $ f 0.02
    -- As duas linhas abaixo fazem a mesma coisa
    print $ map dummy nums
    print $ map (\x -> x * x - x + 1) nums
    -- Como ler o que está entre parênteses: "dado um x, fazer x * x - x + 1"
    -- A função dummy somente dá nome ao que está escrito nos parênteses
    print $ g 0.02
    print $ prodPosNeg nums
    print $ prodPosNeg' nums
    print $ prodPosNeg'' nums
    print $ h nums
    x <- a 5 -- Aqui posso usar "<-" pois a é um MONAD
    let y = b 42 -- Aqui sou obrigado a usar "let" e "=" pois g não é MONAD
    print $ show $ x + y
    z <- c 10
    print z

dummy :: Num a => a -> a
dummy x = x * x - x + 1

nums :: [Integer]
nums = [3, 5, 6, 9, -4]

safeInv :: (Fractional a, Eq a) => a -> Maybe a
safeInv 0 = Nothing
safeInv x = Just (1 / x)

safeInc :: (Num a, Eq a) => a -> Maybe a
safeInc 100 = Nothing
safeInc x = Just (x + 1)

f :: (Fractional a, Eq a) => a -> Maybe a
f x = safeInv x >>= safeInc

g :: (Fractional b, Eq b) => b -> Maybe b
g x = safeInv x >>= \y -> safeInc y

encontra :: (a -> Bool) -> [a] -> Maybe a
encontra _ [] = Nothing
encontra t (x:xs)
    | t x = Just x
    | otherwise = encontra t xs

prodPosNeg :: (Num a, Ord a) => [a] -> Maybe a
prodPosNeg lista = case encontra (>0) lista of 
    Nothing -> Nothing
    Just x -> case encontra (<0) lista of
        Nothing -> Nothing
        Just y -> Just (x * y)

-- As funções acima e abaixo fazem a mesma coisa e utilizam do operador ">>=". Este operador serve para composição (de MONADS) de funções que podem ou não retornar valores válidos. Usado após uma função que retorna "Maybe a", ele faz a verificação, dando continuidade caso retorne algo ou retornando Nothing e efetivamente encerrando a função que está sendo composta.

prodPosNeg' :: (Num b, Ord b) => [b] -> Maybe b
prodPosNeg' lista = encontra (>0) lista >>= (\x -> encontra (<0) lista >>= \y -> Just (x * y))

prodPosNeg'' ::(Num a, Ord a) => [a] -> Maybe a
prodPosNeg'' lista = do
    x <- encontra (<0) lista 
    y <- encontra (>0) lista 
    Just (x * y)

h :: (Integral a) => [a] -> Maybe a
h lista = do
    x <- encontra odd lista
    y <- encontra even lista 
    -- z <- x + y -- Essa linha não é sintaxe válida em haskell
    -- O operador de atribuição "<-" só é capaz de atribuir MONADs a uma variável. x e y não são MONADs, são valores inteiros, então deve-se usar outro operador.
    let z = x + y
    encontra (==z) lista

-- Em Haskell, IO também é um MONAD, isto é, se ela retorna algo ou não depende do contexto.
a :: (Num a) => a -> IO a
a x = do
    return (x + 1)

b :: (Num a) => a -> a
b x = x + 1

c :: Integer -> IO Integer
c x = do
    print "Digite um number: "
    ly <- getLine
    let y = read ly 
    return (x + y)