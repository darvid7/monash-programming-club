number_of_cells, target_cell = [int(x) for x in input().split()]
start_cell = 1
# The ith portal connects cell i and cell i + a[i], 1 <= i <= n-1
# Can't use portals backwards.
# Note: this question uses 1 based indexing, probably easier to use an array with 1 extra space
# rather than handle 1 based indexing with -1 all the time.

# Eg:

# input1.
# idx:  0 1 2 3 4 5 6
# arr:  1 2 1 2 1 2 1
# 1st protal, index 0 connects cell 1 and cell 2.
# 2nd portal, index 1 connects cell 2 and cell 4.
# 3rd portal, index 2 connects cell 3 and cell 4.
# 4th portal, index 3 connects cell 4 and cell 5.
# 5th portal, index 4 connects cell 5 and cell 6.
# 6th portal, index 5 connects cell 6 and cell 8.
# 7th portal, index 6 connects cell 7 and 8.

# input 2.
# idx:  0 1 2 3 4 5 6
# arr:  1 2 1 2 1 1 1
# 1st protal, index 0 connects cell 1 and cell 2.
# 2nd portal, index 1 connects cell 2 and cell 4.
# 3rd portal, index 2 connects cell 3 and cell 4.
# 4th portal, index 3 connects cell 4 and cell 6.
# 5th portal, index 4 connects cell 5 and cell 6.
# 6th portal, index 5 connects cell 6 and cell 7.
# 7th portal, index 6 connects cell 7 and 8.

# Start always at cell 1.
portal_numbers = [int(x) for x in input().split()]

adjacency_list = [[] for _ in range(number_of_cells + 1)]
seen = [0 for _ in range(number_of_cells + 1)]

for i in range(len(portal_numbers)):
    source = i + 1
    dest = source + portal_numbers[i]
    adjacency_list[source].append(dest)  # One way.

def get_adjacent_edges(node):
    return adjacency_list[node]

def dfs(node):
    if node == target_cell:  # Return early.
        seen[node] = 1
        return True
    if seen[node] == 1:  # Already explored down this route.
        return False
    seen[node] = 1
    for adjacent_node in get_adjacent_edges(node):
        if seen[adjacent_node] != 1:
            if dfs(adjacent_node):
                return True
    return False
dfs(start_cell)
print("YES" if seen[target_cell] == 1 else "NO")
