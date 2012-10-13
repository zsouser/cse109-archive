p5: p5.o /proj/csc109/p5/lex.o  /proj/csc109/p5/word.o /proj/csc109/p5/alu.o /proj/csc109/p5/chip.o /proj/csc109/p5/check.o  /proj/csc109/p5/mem.o progchip.o
	g++ -o p5 p5.o /proj/csc109/p5/lex.o /proj/csc109/p5/word.o /proj/csc109/p5/alu.o /proj/csc109/p5/chip.o /proj/csc109/p5/check.o  /proj/csc109/p5/mem.o progchip.o

p5.o: p5.cc progchip.h
	g++ -c -g p5.cc

progchip.o: progchip.cc progchip.h /proj/csc109/p5/table.t /proj/csc109/p5/lex.h /proj/csc109/p5/chip.h
	g++ -c -g progchip.cc

clean: 
	rm *~ *.o p5
