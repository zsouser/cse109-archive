#ifndef LEX_H
#define LEX_H
#include "/proj/csc109/p4/table.t"
#include "/proj/csc109/p4/word.h"

class Lex {
public:
  Lex() : str(),token(),ptr(0),strlen(0) {}
  static const int
   JUNK = -1,    NUMBER = 0,    IDENTIFIER = 1,    PLUS = 2,    MINUS = 3,    TIMES = 4,    DIVIDE = 5,    IF = 6,    WRITE = 7,    READ = 8,   LBRACK = 9,    RBRACK = 10,    LPAR = 11,    RPAR = 12,    BEGIN = 13,    SETEQ = 14,    GOTO = 15,    LT = 16,    GT = 17,    LE = 18,    GE = 19,    EQ = 20,    NE = 21,    EOLN = 22,    END = 23,    COLON = 24,    HALT = 25,    MODULO = 26;
  char * str;
  Word token;
  int ptr;
  int strlen;
  void setString(Word wd);
  void setString(char * ch);
  bool atEnd();
  void reset(int pos);
  void reset();
  Word word();
  int position();
  int peek();
  int next();
};

#endif
