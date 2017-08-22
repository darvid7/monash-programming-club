

alpha_map = {
	"A": 0,
	"B": 0,
	"C": 0,
	"D": 0,
	"E": 0,
	"F": 0,
	"G": 0,
	"H": 0,
	"I": 0,
	"J": 0,
	"K": 0,
	"L": 0,
	"M": 0,
	"N": 0,
	"O": 0,
	"P": 0,
	"Q": 0,
	"R": 0,
	"S": 0,
	"T": 0,
	"U": 0,
	"V": 0,
	"W": 0,
	"X": 0,
	"Y": 0,
	"Z": 0
}

string = input()

for char in string:
	if char.upper() in alpha_map:
		alpha_map[char.upper()] += 1
alpha = list(alpha_map.keys())
alpha.sort()
for char in alpha:
	print(char + " | ", end="")
	times = alpha_map[char] 
	print("*"*times)
