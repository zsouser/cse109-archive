p6: p6.o /proj/csc109/p5/lex.o  /proj/csc109/p5/word.o /proj/csc109/p5/alu.o /proj/csc109/p5/chip.o /proj/csc109/p5/check.o  /proj/csc109/p5/mem.o progchip.o fullprog.o 
	g++ -o p6 p6.o /proj/csc109/p5/lex.o /proj/csc109/p5/word.o /proj/csc109/p5/alu.o /proj/csc109/p5/chip.o /proj/csc109/p5/check.o  /proj/csc109/p5/mem.o progchip.o fullprog.o 

p6.o: p6.cc fullprog.h 
	g++ -c -g p6.cc

fullprog.o: fullprog.cc fullprog.h progchip.h  
	g++ -c -g fullprog.cc

progchip.o: progchip.cc progchip.h /proj/csc109/p5/table.t /proj/csc109/p5/lex.h /proj/csc109/p5/chip.h
	g++ -c -g progchip.cc

clean: 
	rm *~ *.o p6
