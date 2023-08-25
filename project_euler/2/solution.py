#!/bin/python

#Each new term in the Fibonacci sequence is generated 
#by adding the previous two terms. By starting with 1 and 2, the first 
#10 terms will be:
#1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
#
#By considering the terms in the Fibonacci sequence whose values do 
#not exceed four million, find the sum of the even-valued terms.


def fib():

    a1 = 1
    a2 = 1

    while True:

        an = a1 + a2
        
        a2 = a1
        a1 = an

        yield an


fib_gen = fib()

solution = 0
while True:

    x = next(fib_gen)
    
    if x > 4_000_000:
        print(solution)
        break

    solution += x if x % 2 == 0 else 0



