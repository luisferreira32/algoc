# make it easy :)

CC=gcc
FLAGS=-Wall -Wextra

# {{{

.PRECIOUS: bin/codeforces/%
bin/codeforces/%: codeforces/%.c
	$(CC) $(FLAGS) $< -o $@

.PHONY: %
codeforces/%: bin/codeforces/%
	$<

# }}}

# {{{

.PHONY: clean
clean:
	rm -r bin/*

# }}}
