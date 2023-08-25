#!/bin/python


#If we list all the natural numbers below 10 that are multiples 
#of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

#Find the sum of all the multiples of 3 or 5 below 1000.

#possible solutions

#sol 1
#let sum = 0
#for every x in [1, 1000]
#if x is a multiple of 3 or 5
#sum += x

#sol 2
#only iterate x by 3 and 5


solution = 0

#linear solution
for x in range(1, 1000):

    if x % 3 == 0 or x % 5 == 0:
        solution += x


print(f"solution1: {solution}")


#1, 3, 6, 9, ... 996, 999
#1, 5, 10, 15, ... 900, 995

#sum of following sequences in range of [1, 1000)
#3n + 1 
#5n + 1
#subtract duplicates
#15n + 1

#faster linear solution

a1 = lambda n: 3*n 
a2 = lambda n: 5*n 
a3 = lambda n: 15*n

i1 = (999) // 3
i2 = (999) // 5
i3 = (999) // 15

sum1 = (a1(i1) + a1(1)) * (i1) / 2 
sum2 = (a2(i2) + a2(1)) * (i2) / 2
sum3 = (a3(i3) + a3(1)) * (i3) / 2

solution = sum1 + sum2 - sum3

print(f"solution2: {solution}")
