#Makefile
#zrs212
#Zach Souser
#Program 2

CC = g++ -Wall -Werror

p2: p2.o word.o
	$(CC) -o p2 p2.o word.o

p2.o: p2.cc word.cc
	$(CC) -c p2.cc word.cc

clean:
	rm -f *.o *~ p2
