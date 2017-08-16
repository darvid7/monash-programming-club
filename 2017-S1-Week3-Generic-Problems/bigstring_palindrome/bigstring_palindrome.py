"""
@author: David Lei
@since: 15/03/2017
@modified:

"""
import sys
max_string_size = sys.maxsize-1

with open('i.txt', 'w') as f:
    f.write(str(max_string_size))

with open('i.txt', 'r') as f:
    x = f.readlines()[0]
    print(x)
    x = int(x)

max_string = 'a'*int(x)

# work out how to deal with this.
