main :: IO ()
main = do
    num <- readLn :: IO Int
    print (num + 1)
-- Não vale nota