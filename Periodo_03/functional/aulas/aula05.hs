-- Continuando o estudo de MONADs

main :: IO()
main = do 
    print $ safeDiv 4 3
    print $ safeInv 0
    print $ safeInv 5   
    print g
    print [Bom, Bom, Ruim, MaisOuMenos]
    print $ filter (==Fahrenheit 50) [Celsius 10, Fahrenheit 6]

data Talvez a = Nada | Apenas a
data Temperatura = Celsius Float | Fahrenheit Float
    deriving (Show)

instance Eq Temperatura where
    (==) :: Temperatura -> Temperatura -> Bool
    Celsius c1 == Celsius c2 = c1 == c2
    t1 == t2 = toCelsius t1 == toCelsius t2


toCelsius :: Temperatura -> Temperatura
toCelsius (Celsius c) = Celsius c
toCelsius (Fahrenheit f) = Celsius ((f - 32) * 5 / 9)

-- instance Show Temperatura where
--     show :: Temperatura -> String
--     show (Celsius c) = show c ++ "°C"
--     show (Fahrenheit f) = show f ++ "°F"

data Clima = Bom | MaisOuMenos | Ruim
    deriving (Eq)

instance Show Clima where
    show :: Clima -> String
    show Ruim = "Vamos assistir Netflix"
    show MaisOuMenos = "Vamos para o parque"
    show Bom = "Talvez um churrasquinho"

data Arvore a = Folha | No a (Arvore a) (Arvore a)
    deriving (Show, Eq)

-- As duas funções safeDiv abaixo foram implementadas com MONADs

-- safeDiv :: Integer -> Integer -> Maybe Integer
-- safeDiv _ 0 = Nothing
-- safeDiv x y = Just(x `div` y)

safeDiv :: Integer -> Integer -> Either String Integer
safeDiv _ 0 = Left "Div por zero"
safeDiv x y = Right (x `div` y)

-- MONAD "Either" faz o que diz: resultado é um ou outro

safeInv :: (Fractional a, Eq a) => a -> Either String a
safeInv 0 = Left "Inverso de zero"
safeInv x = Right (1 / x)

baskara :: (Ord a, Floating a) => a -> a -> a -> [a]
baskara a b c
    | a == 0 = [(-c)/b]
    | delta < 0 = []
    | delta == 0 = [x]
    | otherwise = [x1, x2]
    where
        delta = b * b - 4 * a * c
        x = (-b) / 2 * a
        x1 = ((-b) + sqrt delta) / (2 * a)
        x2 = (b + sqrt delta) / (2 * a)

g :: (Ord a, Floating a) => [a]
g = do
    x <- baskara 3 4 (-5)
    y <- baskara (-2) (-5) 6
    let z = x + y
    baskara z 3 5

h :: (Num a, Enum a) => [a]
h = do
    x <- [1..3]
    y <- [1..3]
    let z = x * y
    w <- [-z, z]
    return (w + 1)