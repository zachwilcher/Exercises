#!/bin/python

import math

# The sum of the squares of the first ten natural numbers is,
# 12 + 22 + ... + 102 = 385
# The square of the sum of the first ten natural numbers is,
# (1 + 2 + ... + 10)2 = 552 = 3025
# Hence the difference between the sum of the squares of the first 
# ten natural numbers and the square of the sum is 3025 − 385 = 2640.
# Find the difference between the sum of the squares of the first one 
# hundred natural numbers and the square of the sum.

square = lambda x: x*x

# if it works it's not wrong right? 
print(square(sum(range(1,101))) - sum(map(square, range(1,101))))


sum_of_squares = lambda n: (1/6) * n * (n + 1) * (2 * n + 1)

my_sum = lambda n: (1 / 2) * n * (n + 1)

difference = lambda n: square(my_sum(n)) - sum_of_squares(n)

print(difference(100))


