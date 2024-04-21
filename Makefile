# Make it easy :)

CC=gcc
FLAGS=-Wall -Wextra

bin/watermelon: codeforces/watermelon.c
	$(CC) $(FLAGS) codeforces/watermelon.c -o bin/watermelon

bin/waytoolongwords: codeforces/waytoolongwords.c
	$(CC) $(FLAGS) codeforces/waytoolongwords.c -o bin/waytoolongwords

bin/team: codeforces/team.c
	$(CC) $(FLAGS) codeforces/team.c -o bin/team

bin/bitplusplus: codeforces/bitplusplus.c
	$(CC) $(FLAGS) codeforces/bitplusplus.c -o bin/bitplusplus