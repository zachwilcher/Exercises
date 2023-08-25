
# Two suppliers a and b deliver n shipments of goods
# each shipment has a number of goods gone bad (spoiled)
#
# Each supplier compares their performance by two measures
# 1. n per product spoilage rate (ratio of products gone bad 
# to number of products delivered)
# 2. overall spoilage rate (ratio of total goods gone bad to
# total goods delivered)
#
# find numbers m such that:
# measure 1 is greater for b than a by a factor m and
# measure 2 is greater for a than b by a factor m


n = input()

#n^3 input solution eksdee
a = list(map(int, input().split()))
b = list(map(int, input().split()))

# generate possible spoilage sequences a_s and b_s
# the product of all elements in a or b
# is the number of possible sequences for a_s or b_s

# m must satisfy n + 1 cases now with
# our generated sequences for a and b

# can't have more spoiled goods than total goods
# if m is to satisfy all n + 1 cases
# m must satisfy the case where it is needed to
# be smallest.
# "solving" for m in our inequalities shows what
# m's largest and smallest values are

# those inequalities vary based on our choice
# of m and spoilage sequences

# they all must hold true
# the smallest elements in our sequences
# restrict m the most therefore 
# the largest value of m is 
# a_s[i] * b[i] / b_s[i] * a[i]
# where i represents the index of
# the smallest elements in a or a_s and b or b_s
# also m therefore only needs to satisfy 2 cases

# similarly for the minimum value of m
# m >= sum(a_s) * sum(b) / sum(b_s) * sum(a)

# all goods could spoil or no goods could spoil
# these give us our theoretical maxs and mins
# TODO


# fuck this problem is hard




if __name__ == "__main__":
    pass
