#Makefile for P4
#Zach Souser
#zrs212
#CSE 109

CC = g++ -g -c -Wall -Werror

p4 : p4.o lex.o /proj/csc109/p4/word.o check.o
	g++ -o p4 p4.o lex.o /proj/csc109/p4/word.o check.o

p4.o : p4.cc lex.h /proj/csc109/p4/word.h /proj/csc109/p4/check.h
	$(CC) p4.cc

lex.o : lex.cc lex.h /proj/csc109/p4/table.t /proj/csc109/p4/rek.t /proj/csc109/p4/word.h /proj/csc109/p4/check.h 
	$(CC) lex.cc

check.o : /proj/csc109/p4/check.cc /proj/csc109/p4/check.h
	$(CC) /proj/csc109/p4/check.cc

clean:
	rm *~ *.o p4
