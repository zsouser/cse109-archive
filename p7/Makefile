p7: p7.o hash.o /proj/csc109/p5/lex.o /proj/csc109/p5/word.o /proj/csc109/p5/check.o
	g++ -o  p7 p7.o hash.o /proj/csc109/p5/lex.o /proj/csc109/p5/word.o /proj/csc109/p5/check.o

p7.o: p7.cc hash.h
	g++ -c -g p7.cc

hash.o: hash.cc hash.h /proj/csc109/p5/lex.h /proj/csc109/p5/table.t /proj/csc109/p5/word.h
	g++ -c -g hash.cc

clean:
	rm *~ *.o p7
