"""
Create target string S that only has lowercase English letters.

Start with empty string.

Operations:
- Add any single lowercase letter to end of stirng.
- Copy and substring of your string.
    - Copies on to clipboard
    - Overwrites what was in clipboard
    - Clipboard starts of empty
- Add entire contents of clipboard to end of your string (doesn't mutate contents of clipboard)

What is the smallest num of operations to create target stirng.

    0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22
s = v n s d m v n s n s  d  m  k  v  d  m  k  v  n  s  d  m k
"""

T = int(input())

for t in range(T):
    s = input()
    if len(s) == 6:
        ans = 6
        if s[0:3] == s[3:]:
            ans = 5
        elif s[0:2] == s[2:4] == s[4:]:
            ans = 5
    else:
        ans = len(s)
    print("Case #{0}: {1}".format(t + 1, ans))
    # seen_substrings = set()
    # seen_substrings.add(s[0:2])
    # for i in range(2, len(s)):
