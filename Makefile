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

%.jury.bin: test/%.jury.c
	$(CC) $(FLAGS) $< -o $@

.PHONY: t%
t%: %.jury.bin %.bin
	./$*.jury.bin $*.bin

# }}}

# {{{

in:
	mkdir -p in

bin:
	mkdir -p bin

.PHONY: setup
setup: bin in

.PHONY: clean
clean:
	rm -rf in/*
	rm *.bin

# }}}
