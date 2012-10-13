#Makefile for P3
#Zach Souser
#zrs212
#CSE 109

CC = g++ -c -Wall -Werror

p3 : p3.o /proj/csc109/p3/word.o /proj/csc109/p3/check.o
	g++ -o p3 p3.o /proj/csc109/p3/word.o /proj/csc109/p3/check.o

p3.o : p3.cc table.t rek.t /proj/csc109/p3/word.h /proj/csc109/p3/check.h
	$(CC) p3.cc

clean:
	rm *~ *.o p3
