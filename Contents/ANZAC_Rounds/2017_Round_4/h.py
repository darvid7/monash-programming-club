T = int(input())

teams = {}

for i in range(T):
	team_name = str(input())
	games, wins, draws, losses, goals_for, goals_against, points = [int(x) for x in input().split()]
	teams[team_name] = [games, wins, draws, losses, goals_for, goals_against, points]
	# 			0,     1,    2,      3,         4,             5,      6

G = int(input())

for _ in range(G):
	home_team_name = str(input())
	home_team_score = int(input())
	away_team_name = str(input())
	away_team_score = int(input())
	
	if away_team_score > home_team_score:  # away team won.
		teams[away_team_name][0] += 1
		teams[away_team_name][1] += 1
		teams[away_team_name][4] += away_team_score
		teams[away_team_name][5] += home_team_score
		teams[away_team_name][6] += 3

		teams[home_team_name][0] += 1
		teams[home_team_name][3] += 1
		teams[home_team_name][4] += home_team_score
		teams[home_team_name][5] += away_team_score
	elif home_team_score > away_team_score:  # home team won.
		teams[home_team_name][0] += 1
		teams[home_team_name][1] += 1
		teams[home_team_name][4] += home_team_score
		teams[home_team_name][5] += away_team_score
		teams[home_team_name][6] += 3

		teams[away_team_name][0] += 1
		teams[away_team_name][3] += 1
		teams[away_team_name][4] += away_team_score
		teams[away_team_name][5] += home_team_score
	else: # Draw.
		teams[away_team_name][0] += 1
		teams[away_team_name][2] += 1
		teams[away_team_name][4] += away_team_score
		teams[away_team_name][5] += home_team_score
		teams[away_team_name][6] += 1

		teams[home_team_name][0] += 1
		teams[home_team_name][2] += 1
		teams[home_team_name][4] += home_team_score
		teams[home_team_name][5] += away_team_score
		teams[home_team_name][6] += 1

team_list = list(teams.items())
team_list.sort(key=lambda t: t[0].upper())
team_list.sort(key=lambda t: (t[1][6], t[1][4] - t[1][5], t[1][4]), reverse=True)

# team_list.sort(key=lambda t: (t[1][6], t[1][4] - t[1][5], t[1][4], t[0].upper()))
#team_list.sort(key=lambda t: (t[0], t[1][6], t[1][4] - t[1][5], t[1][4]))
for team in team_list:
	print("%s %s %s %s %s %s %s %s" % (team[0], team[1][0], team[1][1], team[1][2], team[1][3], team[1][4], team[1][5], team[1][6]))

