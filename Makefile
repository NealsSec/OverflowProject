CC=gcc
SOURCE=src/main.c src/overflow.c src/usage.c src/arguments.c
FLAGS=-Wall
OUT=overflow

default:
	$(CC) -o $(OUT) $(SOURCE) $(FLAGS)

clean:
	rm $(OUT)
