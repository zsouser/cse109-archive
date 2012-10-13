#ifndef PROGCHIP_H
#define PROGCHIP_H

#include "/proj/csc109/p5/chip.h"
#include "/proj/csc109/p5/table.t"
#include "/proj/csc109/p5/lex.h"
#include "/proj/csc109/p5/word.h"

class ProgChip : public Chip {
public:
  ProgChip() : halted(false),step(0) { }
  void load(ifstream& in);
  void run(bool verbose);
  Table<int, Word> readFile(ifstream& in,int& size);
  void doLine(int line, bool verbose);
  void doIdentifier();
  void doIf(int line,bool verbose);
  void doGoto(Word wd, bool verbose);
  void doRead(int line, bool verbose);
  void doWrite(int line, bool verbose);
  void error(int line, char * str);
protected:
  int numLines;
  int step;
  bool halted;
  Lex input;
  Table<int, Word> code;
  Table<Word, int> labels;
  Table<Word, int> vars;
  Lex l;
};

#endif
