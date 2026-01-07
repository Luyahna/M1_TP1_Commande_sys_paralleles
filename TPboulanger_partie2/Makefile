all : boulanger.o BONUS
	gcc -Wall -g -o boulanger boulanger.o -lpthread

boulanger.o : boulanger.c boulanger.h
	gcc -Wall -c boulanger.c -lm

BONUS : boulangerBonus.o
	gcc -Wall -g -o boulangerBonus boulangerBonus.o -lpthread

boulangerBonus.o : boulangerBonus.c boulangerBonus.h
	gcc -Wall -c boulangerBonus.c -lm
