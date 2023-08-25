data FailableDouble = Failure
                    | OK Double
  deriving Show
ex01 = Failure
ex02 = OK 3.4

safeDiv _ 0 = Failure
safeDiv x y = OK (x / y)
