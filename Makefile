# make it easy :)

CC=gcc
FLAGS=-Wall -Wextra
DEBUGFLAGS=-Wall -Wextra -g

# {{{

libjury.so: test/internal/
	$(CC) $(FLAGS) -fPIC -Wl,-rpath,$$ORIGIN -shared -o libjury.so test/internal/jury.c

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

%.jury.bin: test/%.jury.c libjury.so
	$(CC) $(FLAGS) $< -L. -ljury -o $@

.PHONY: t%
t%: %.jury.bin %.bin
	LD_LIBRARY_PATH=. ./$*.jury.bin $*.bin

# }}}

# {{{


.PHONY: clean
clean:
	rm *.bin *.so

# }}}
