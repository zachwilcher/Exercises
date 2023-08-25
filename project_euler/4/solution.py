#!/bin/python

from itertools import product

# A palindromic number reads the same both ways. The largest 
# palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
# Find the largest palindrome made from the product of two 3-digit numbers.

# three digit numbers exist in range
# from 100 to 999

# is_palindrome()
# check product of numbers going down from largest three digit number
# n^2 assuming is_palindrome is constant time
# n^3 if is_palindrome is linear? idk big o.


def is_palindrome(num):
    """Takes an integer and returns True if it's a palindrome number""" 
    
    if not isinstance(num, str):
        num = str(num)
    
    if len(num) < 2:
        return True
    
    front = num[0]
    back = num[-1]
    
    if front == back:
        num = num[1:len(num) - 1]
        return is_palindrome(num)

    else:
        return False



#what values of i * j are palindromes
#idk lets check all those values

palindromes = [] 

for i in reversed(range(100, 1000)):
    for j in reversed(range(i, 1000)):
        if is_palindrome(i * j): 
            palindromes.append(i * j)

print(max(palindromes))

# we can reduce the possible i and j values

# we can also check all palindromes to see if
# two three digit ints create it



