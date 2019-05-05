CC=gcc
SOURCE=src/main.c src/overflow.c
FLAGS=-Wall

default:
	$(CC) -o main $(SOURCE) $(FLAGS)
