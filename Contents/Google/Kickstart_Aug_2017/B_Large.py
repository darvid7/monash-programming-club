T = int(input())

for t in range(T):
    no_sticks = input()
    sticks = [int(x) for x in input().split()]
    sticks.sort()

    freq = {}

    

"""
ans = 0
map<int, int> freq
loop over index, x (backwards):
  ans += freq[x]
  freq[x]++
  suffix_sum[index] = ans
"""
