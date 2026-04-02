main :: IO ()
main = do
  print "HW"
  print(sinal(-42))
  print(baskara (-1) 3 4)
  print(myLen nums2)
  print(mySum nums2)
  print(sumEvenIdx nums)
  print(myFilter (>2) nums)
  print(myMap (+(-2)) nums)
  
sinal x
  | x < 0 = -1
  | x == 0 = 0
  | otherwise = 1

baskara a b c
  | a == 0 = [(-c)/b]
  | delta < 0 = []
  | delta == 0 = [x]
  | otherwise = [x1, x2]
  where
    delta = b^2 - 4 * a * c
    x = (-b) / 2 * a
    x1 = (-b + sqdelta) / 2 * a
    x2 = (-b - sqdelta) / 2 * a
    sqdelta = sqrt(delta)

nums = [3, 4, 2, 6, 2, 7]

nums2 = 3:(4:(2:(6:(2:(7:([]))))))

myLen [] = 0
myLen (x:xs) = 1 + myLen xs

mySum [] = 0
mySum (x:xs) = x + mySum xs

myMap _ [] = []
myMap f (x:xs) = f x : myMap f xs

myFilter _ [] = []
myFilter t (x:xs)
  | t x = x : myFilter t xs
  | otherwise = myFilter t xs

sumEvenIdx [] = 0
sumEvenIdx [x] = x
sumEvenIdx (x:_:xs) = x + sumEvenIdx xs