# make it easy :)

CC=gcc
FLAGS=-Wall -Wextra

.PRECIOUS: bin/%
bin/%: codeforces/%.c
	$(CC) $(FLAGS) $< -o $@

.PHONY: %
%: bin/%
	$<

.PHONY: clean
clean:
	rm bin/*
