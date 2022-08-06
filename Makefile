all: compile run
compile:
	gcc -o bin/main src/*.c -Iincl -lSDL2main -lSDL2
run:
	bin/main
