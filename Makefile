# make it easy :)

CC=gcc
FLAGS=-Wall -Wextra

# {{{

.PRECIOUS: bin/%
bin/%: %.c
	$(CC) $(FLAGS) $< -o $@

.PHONY: %
%: bin/%
	$<

.PRECIOUS: bin/%_gen
bin/%_gen: test/%_gen.c
	$(CC) $(FLAGS) $< -o $@

in/%: bin/%_gen
	$< $@

out/%: in/%
	./_runner.sh $< $@

# }}}

# {{{

in:
	mkdir -p in

bin:
	mkdir -p bin

out:
	mkdir -p out

.PHONY: setup
setup: bin out in

.PHONY: clean
clean:
	rm -rf bin/*
	rm -rf out/*
	rm -rf in/*

# }}}
