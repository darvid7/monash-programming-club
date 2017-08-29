import math
import itertools

T = int(input())

def calc_height(hypoth, leg):
    # #print("for hypoth: {0}, leg: {1}".format(hypoth, leg))
    h_sq = hypoth**2 - leg**2
    if h_sq <= 0:
        #print("EXIT 1 ")
        #print("     for hypoth: {0}, leg: {1} h_sq = {2}".format(hypoth, leg, h_sq))
        return False
    height = math.sqrt(h_sq)
    # #print("height is " + str(height))
    # if (height == 0):
    #     #print("EXIT 2")
    #     #print("      height is 0 for hypoth: {0}, leg: {1}".format(hypoth, leg))
    return height != 0

def check_can_form_isosceles_trapezoid(candidate_sticks):
    d = {}
    for s in candidate_sticks:
        if s not in d:
            d[s] = 1
        else:
            d[s] += 1
    if len(d) == 4:  # No sticks can form side angles.
        # #print("EXIT 3")
        # #print("     sticks: " + str(candidate_sticks))
        return False
    if len(d) == 1:  # Only can form rectangles/squares.

        return False

    # 1. Get the two equal side values.

    # Have 3 items in dict, one with cout 2, rest with count 1.
    # Or have 2 items in dict, one with count 3, another with count 1.

    # Max 4 items so this is constant right :P.
    sticks = list(d.items())
    sticks.sort(key=lambda t:t[1])
    # max item is at the end.
    dup_stick = sticks[-1][0]

    # Len is 3 or 2.
    if len(d) == 2:
        if sticks[-1][1] != 3:
            # # last item of sticks has 2 things, meaning so does the first so can only form squares.
            # #print("EXIT 4")
            # #print("     Sticks form rect: " + str(sticks))
            return False
    if sticks[-1][1] == 3:
        base2 = dup_stick
    else:
        base2 = sticks[1][0]
    base1 = sticks[0][0]
    # 2. Get base values.

    # a and b are equal and form the angled sides.
    # c and d form the top and base.
    left_over_base = abs(base1 - base2)/2
    # #print("left over base: " + str(left_over_base))
    if left_over_base == 0:
        #print("EXIT 5")
        #print("     left over base exit, sticks: " + str(sticks))
        return False

    # 3. Check height is non zero.

    return calc_height(dup_stick, left_over_base)



for t in range(T):
    no_sticks = int(input())
    sticks = [int(x) for x in input().split()]
    # Complexity bottle neck.
    combs = itertools.combinations(sticks, 4)
    count = 0
    for p in combs:
        x = check_can_form_isosceles_trapezoid(p)
        if x:
            count += 1
        print("valid {0} combination: {1}".format(x, p))
    print("Case #{0}: {1}".format(t + 1, count))
    # #print(list(perms))
