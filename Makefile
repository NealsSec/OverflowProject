CC=gcc
SOURCE=src/main.c src/overflow.c src/usage.c src/arguments.c
FLAGS=-Wall

default:
	$(CC) -o main $(SOURCE) $(FLAGS)
