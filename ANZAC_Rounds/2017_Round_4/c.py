index_map = {
    8: 0,
    1: 1,
    2: 2,
    3: 3,
    4: 4,
    5: 5,
    6: 6,
    7: 7
}
# Station to index map.

stations = [8, 1, 2, 3, 4, 5, 6, 7]

start_station = int(input())
cur_idx = index_map[start_station]
s = set()
s.add(start_station)
l = [start_station]
reject = False
while (True):
    next = str(input().strip())
    if next == "#":
        break
    direction = next[0]
    stops = int(next[1])
    if direction == "A":
        cur_idx = (cur_idx - stops) % 8
    else:
        cur_idx = (cur_idx + stops) % 8
    if stations[cur_idx] in s:
        reject = True
    s.add(stations[cur_idx])
    l.append(stations[cur_idx])

r = list(s)
if len(r) < 5:
    reject = True
for i in range(len(l)):
    if i == len(l) -1:
        print(l[i], end="")
    else:
        print(l[i], end=" ")
        
if reject:
    print(" reject")
