#!/bin/python


# 2520 is the smallest number that can be divided by each 
# of the numbers from 1 to 10 without any remainder.
# What is the smallest positive number that is evenly divisible by all 
# of the numbers from 1 to 20?

# 20 = 2*2*5
# 19 = prime
# 18 = 2*3*3
# 17 = prime
# 16 = 2*2*2*2
# 15 = 3*5
# 14 = 2*7
# 13 = prime
# 12 = 2*2*3
# 11 = prime
# 10 = 2*5
# 9 = 3*3
# 8 = 2*2*2
# 7 = prime
# 6 = 2*3
# 5 = prime
# 4 = 2*2
# 3 = prime
# 2 = prime


def check(num):

    for i in range(1, 20 + 1):
        if num % i != 0:
            return False

    return True

# lazy
val = 20
while not check(val):
    val += 20


print(val)
