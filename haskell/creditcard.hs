toDigitsRev :: Integer -> [Integer]
toDigitsRev n 
  | n > 0 = n `mod` 10 : toDigitsRev (n `div` 10)
  | otherwise = []

toDigits :: Integer -> [Integer]
toDigits n = reverse(toDigitsRev( n))


doubleEveryOtherl :: [Integer] -> [Integer]

doubleEveryOtherl [] = []
doubleEveryOtherl [n] = [n]
doubleEveryOtherl (a:b:ns) = [a, b * 2] ++ doubleEveryOtherl(ns)


doubleEveryOther :: [Integer] -> [Integer]

doubleEveryOther ns = reverse(doubleEveryOtherl(reverse(ns)))

toDigitsList :: [Integer] -> [Integer]
toDigitsList [] = []
toDigitsList (n:ns) = toDigits n ++ toDigitsList(ns)

sumDigits :: [Integer] -> Integer
sumDigits ns = sum(toDigitsList ns)


validate :: Integer -> Bool

validate n = sumDigits(doubleEveryOther(toDigits(n))) `mod` 10 == 0
