# Make it easy :)

CC=gcc
FLAGS=-Wall -Wextra

bin/%: codeforces/%.c
	$(CC) $(FLAGS) $< -o $@

%: bin/%
	$<