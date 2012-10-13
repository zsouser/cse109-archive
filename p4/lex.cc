#include "lex.h"

void Lex::setString(Word wd) {
  strlen = wd.length();
  str = new char[wd.length()];
  for (int i = 0; i < wd.length(); i++) {
    str[i] = wd[i];
  }
  reset();
}

void Lex::setString(char * ch) {
  setString(*new Word(ch));
}
  
bool Lex::atEnd() {
  return ptr >= strlen;
}

void Lex::reset(int pos) {
  ptr = pos;
}

void Lex::reset() {
  ptr = 0;
}

Word Lex::word() {
  return token;
}

int Lex::position() {
  return ptr;
}

int Lex::peek() {
  int loc = position();
  int retVal = next();
  reset(loc);
  return retVal;
}

int Lex::next() {
  char * temp = new char[100];
  int i = 0;
  while (str[ptr] == ' ') ptr++;
  while (str[ptr] != ' ') {
    if (str[ptr] == ';') reset(strlen);
    if (i >= 100) break;
    if (ptr >= strlen) return EOLN;
    temp[i] = str[ptr];
    i++; ptr++;
    token = Word(temp);
    if (token == "%") return MODULO;
    if (token == "halt") return HALT;
    if (token == ":") return COLON;
    if (token == "end") return END;
    if (token == "!=") return NE;
    if (token == "==") return EQ;
    if (token == ">=") return GE;
    if (token == "<=") return LE;
    if (token == ">") return GT;
    if (token == "<") return LT;
    if (token == "goto") return GOTO;
    if (token == "=") return SETEQ;
    if (token == "begin") return BEGIN;
    if (token == ")") return RPAR;
    if (token == "(") return LPAR;
    if (token == "]") return RBRACK;
    if (token == "[") return LBRACK;
    if (token == "read") return READ;
    if (token == "write") return WRITE;
    if (token == "if") return IF;
    if (token == "/") return DIVIDE;
    if (token == "*") return TIMES;
    if (token == "-") return MINUS;
    if (token == "+") return PLUS;
    if (token[0] > 'A' && token[0] < 'Z') return JUNK;
  }
  ptr++;
  delete [] temp;
  int isNum = true;
  for (int j = 0; j < token.length(); j++) {
    isNum = isNum && (token[j] > '0' && token[j] < '9');
  }
  if (isNum) return NUMBER;
  return IDENTIFIER;
}


