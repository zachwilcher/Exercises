import math

#The prime factors of 13195 are 5, 7, 13 and 29.
#
#What is the largest prime factor of the number 600851475143 ?

num = 600851475143

num = 10
# 5 * 2 = 10
# no other primes multiply to this number
# fundemental law of arthimetic


# if primes 2 up to sqrt(possible_prime) aren't factors of possible_prime
# possible_prime is prime

# we don't have to check for prime numbers greater than
# sqrt(num) to see if num is prime

# to find biggest prime we should set biggest to largest factor of num

# I set it to sqrt(num) and by luck the largest prime was less than that
# I don't really understand a better way to do this
# beyond optimizing prime_check and checking if each element of
# the sorted list (greatest to least) of num's
# factors are prime

# Like sqrt(10) = 3.something
# yet it's largest prime factor is greater than this

# check primes less than sqrt(num)
# return largest factor 



biggest = int(math.sqrt(num))


# lazy prime check
def is_prime(num):
    
    biggest = int(math.sqrt(num))
    
    # should loop over primes from 2 to sqrt(num)
    for i in range(2, biggest + 1):
        
        if num % i == 0:
            return False


    return True


while True:
    
    while num % biggest != 0:
        biggest -= 1
    
    #print multiple of num (tests if is_prime is slow)
    print(biggest)
   
    #only stop loop if number is prime or 1
    if is_prime(biggest) or biggest == 1:
        print(f"biggest prime: {biggest}")
        break
    
    else:
        biggest -= 1




