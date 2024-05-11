# make it easy :)

CC=gcc
FLAGS=-Wall -Wextra
DEBUGFLAGS=-Wall -Wextra -g

# {{{

.PRECIOUS: bin/%
bin/%: %.c
	$(CC) $(FLAGS) $< -o $@

.PHONY: %
%: bin/%
	$<

.PHONY: dbg%
dbg%: bin/%.debug
	gdb $<

bin/%.debug: %.c
	$(CC) $(DEBUGFLAGS) -g $< -o $@

.PRECIOUS: bin/%.gen
bin/%.gen: test/%.gen.c
	$(CC) $(FLAGS) $< -o $@

in/%: bin/%.gen
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
