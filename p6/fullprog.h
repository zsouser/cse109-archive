#ifndef FULLPROG_H
#define FULLPROG_H
#include "progchip.h"
class FullProg : public ProgChip {
public:
  void run(bool verbose);
  void doLine(int line,bool verbose);
  void doExpression(int & tok);
  void doIdentifier(int line, bool verbose);
  void doWrite(int line, bool verbose);
  void doTerm(int & tok);
  void doFactor(int & tok);
  void doIf(int line, bool verbose);
};
#endif
