bin:
	mkdir -p bin

bin/watermelon: bin
	gcc codeforces/watermelon.c -o bin/watermelon
