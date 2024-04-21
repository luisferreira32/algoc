# make it easy :)

CC=gcc
FLAGS=-Wall -Wextra

# {{{

.PRECIOUS: bin/codeforces/%
bin/codeforces/%: codeforces/%.c
	mkdir -p bin/codeforces
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
