#include "progchip.h"
#include <iostream>
#include <fstream>
using namespace std;
// Method load()
//
// Precondition: in is an ifstream with an open file
// Postcondition: sets the variables, labels, and lines of code in the
// class member variables.

void ProgChip::load(ifstream& in) {
  cout << "Loading..." << endl;
  Table<int, Word> lines = readFile(in,numLines);
  int j = 0;
  int i = 0;

  cout << "   Declaring variables" << endl;
  for (i; i < numLines; i++) {
    if (lines[i] == "begin") { i++; break; }
    l.setString(lines[i]);
    if (l.next() == Lex::IDENTIFIER) {
      if (l.atEnd()) {
	if (vars[lines[i]] > 0) { error(i,"Duplicate variable"); exit(0); }
	vars[lines[i]] = 1;
	cout << lines[i] << endl;
      } else { error(i,"Junk at end of line"); exit(0); }
    } 
  }
  // Parse lines of code and assign labels
  
  for (i; i < numLines; i++) {
    code[j] = lines[i];
    cout << j << ": " << code[j] << endl;
    l.setString(code[j]);
    l.next();
    Word wd = l.word();
    if (l.next() == Lex::COLON) {
      labels[wd] = j;
    }
    j++;
  }
  // Set the last line as input
  input.setString(lines[numLines-2]);
  input.reset();
  numLines = j;
  cout << "Program successfully Loaded." << endl;
  cout << "----------------------------" << endl;
}

// Method readFile()
//
// Precondition: the file has been opened, though we don't know if
// it's a real file or not.
// Postcondition: the contents of the file are returned as a table
Table<int, Word> ProgChip::readFile(ifstream& in,int& size) {
  check(!in.fail(),"File not found",__LINE__,__FILE__);
  Table<int, Word> table;
  int i = 0;
  while (!in.eof()) {
    char * str = new char[100];
    in.getline(str,100);
    table[i++] = str;
  }
  size = i;
  return table;
}

// Method run()
// Runs the program
void ProgChip::run(bool verbose) {
  doLine(0,verbose);
}

// Method doLine()
//
// Precondition: the line to be parsed is passed by number, and
// verbose output is made for each iteration if verbose is true
// Postcondition: the next line is run or the program halts

void ProgChip::doLine(int line, bool verbose) {
  if (line < numLines) {
    if (verbose) cout << "[Step:" << step++ << ", Line:" << line << "] " << code[line] << endl;
    l.setString(code[line]);
    switch(l.next()) {
    case Lex::IDENTIFIER :
      doIdentifier();
      doLine(line+1,verbose);
      break;
    case Lex::IF :
      doIf(line,verbose);
      break;
    case Lex::READ :
      doRead(line,verbose);
      break;
    case Lex::WRITE :
      doWrite(line,verbose);
      break;
    case Lex::GOTO :
      l.next();
      doGoto(l.word(),verbose);
      break;
    case Lex::HALT :
      break;
    default:
      doLine(line+1,verbose);
    }
    step++;
  }
}

// Method doIdentifier() - handles identifiers when parsed

void ProgChip::doIdentifier() {
  Word ident = l.word();
  if (l.next() == Lex::SETEQ) {  
    int next = l.next();
    if (next == Lex::NUMBER) {
      vars[ident] = l.word().toInt();
    } else if (next == Lex::IDENTIFIER) {
      vars[ident] = vars[l.word()];
    }
  }
}

// Method doIf() - parses if statements

void ProgChip::doIf(int line,bool verbose) {
  bool good;
  int next = l.next(),val1=0,val2=0;
  if (next == Lex::IDENTIFIER) val1 = vars[l.word()];
  else if (next == Lex::NUMBER) val1 = l.word().toInt();
  int op = l.next();
  next = l.next();
  if (next == Lex::IDENTIFIER) val2 = vars[l.word()];
  else if (next == Lex::NUMBER) val2 = l.word().toInt();

  switch (op) {
  case Lex::GT: good = val1 > val2; break;
  case Lex::GE: good = val1 >= val2; break;
  case Lex::LT: good = val1 < val2; break;
  case Lex::LE: good = val1 <= val2; break;
  case Lex::EQ: good = val1 == val2; break;
  case Lex::NE: good = val1 != val2; break;
  default:
    cout << "Invalid operator" << endl;
    doLine(line+1,verbose);
  }
  if (l.next() == Lex::GOTO) {
    l.next();
    if (good) doGoto(l.word(),verbose);
    else doLine(line+1,verbose);
  }
}

// doGoto() - handles goto statements

void ProgChip::doGoto(Word wd,bool verbose) {
  if (labels[wd] > 0) doLine(labels[wd],verbose);
}

// doRead() - reads a number from the input line and stores it in a variable

void ProgChip::doRead(int line,bool verbose) {
  if (l.next() == Lex::IDENTIFIER) {
    if (!input.atEnd()) {
      int next = input.next();
      if (next == Lex::MINUS) {
	input.next();
	vars[l.word()] = -1 * input.word().toInt();
      } else if (next == Lex::NUMBER) {
	vars[l.word()] = input.word().toInt();
      }
      cout << "INPUT <--- " << vars[l.word()] << endl;
    } else { error(line,"Reached end of input"); exit(0); }
    doLine(line+1,verbose);
  } else error(line,"Invalid variable");
}

// doWrite() - parses a write statement and outputs a number or
// variable value

void ProgChip::doWrite(int line, bool verbose) {
  int next = l.next();
  if (next == Lex::IDENTIFIER) {
    cout << "\tOUTPUT ---> " << vars[l.word()] << endl;
  } else if (next == Lex::NUMBER) {
    cout << "\tOUTPUT ---> " << l.word().toInt() << endl;
  }
  doLine(line+1,verbose);
}

// error() - error message

void ProgChip::error(int line, char * str) {
  cout << endl << "ERROR: Line " << line << " : " << str << endl;
}
