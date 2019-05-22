CC=gcc
SOURCE=src/main.c src/overflow.c src/usage.c src/arguments.c
FLAGS=-Wall
OUT=overflow

$(OUT):
	$(CC) -o $@ $(SOURCE) $(FLAGS)

clean:
	rm $(OUT)
