# make it easy :)

CC=gcc
FLAGS=-Wall -Wextra
DEBUGFLAGS=-Wall -Wextra -g

# {{{

.SECONDARY:

%.bin: %.c
	$(CC) $(FLAGS) $< -o $@

.PHONY: r%
r%: %.bin
	./$<

%.debug.bin: %.c
	$(CC) $(DEBUGFLAGS) -g $< -o $@

.PHONY: d%
d%: %.debug.bin
	gdb $<

%.gen.bin: test/%.gen.c
	$(CC) $(FLAGS) $< -o $@

in/%: %.gen.bin
	./$< $@

.PHONY: t%
t%: in/% %.bin
	./_runner.sh "$*.bin" "in/$*" "out/$*"

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
