#Makefile for p1.cc
#Zach Souser
#CSE 109
#Spring 2010

p1: p1.o chip.o memory.o /home/zrs212/cse109.101/p0/alu.o
	g++ -o p1   p1.o chip.o memory.o /home/zrs212/cse109.101/p0/alu.o
	
p1.o: p1.cc chip.cc memory.cc /home/zrs212/cse109.101/p0/alu.cc
	g++ -c -Wall -Werror p1.cc chip.cc memory.cc /home/zrs212/cse109.101/p0/alu.cc

clean:
	rm -f *~ *.o p1

