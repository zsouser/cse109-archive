#include "fullprog.h"

void FullProg::run(bool verbose) {
  FullProg::doLine(0,verbose);
}

// Override doLine function to implement FullProg functions

void FullProg::doLine(int line, bool verbose) {
  if (line < numLines) {
    if (verbose) cout << "[Step:" << step++ << ", Line:" << line << "] " << code[line] << endl;
    l.setString(code[line]);
    switch(l.next()) {
    case Lex::IDENTIFIER :
      FullProg::doIdentifier(line,verbose);
      if (l.atEnd())
      break;
    case Lex::IF :
      FullProg::doIf(line,verbose);
      break;
    case Lex::READ :
      doRead(line,verbose);
      break;
    case Lex::WRITE :
      FullProg::doWrite(line,verbose);
      break;
    case Lex::GOTO :
      l.next();
      doGoto(l.word(),verbose);
      break;
    case Lex::HALT :
      break;
    case Lex::EOLN:
      FullProg::doLine(line+1,verbose);
    }
    step++;
  }
}

// Override doIdentifier 

void FullProg::doIdentifier(int line,bool verbose) {
  Word ident = l.word();
  int next = l.next();
  if (next == Lex::SETEQ) { 
    next = l.next();
    doExpression(next); pop(-1);
    vars[ident] = get1();
    doLine(line+1,verbose);
  } else if (next == Lex::COLON) {
    l.next();
  }
}

// Override doIf to implement FullProg's doExpression

void FullProg::doIf(int line,bool verbose) {
  bool good;
  int next = l.next();
  doExpression(next);
  int val1 = pop(-2).get2();
  int op = next;
  next = l.next();
  doExpression(next);
  int val2 = pop(-2).get2();
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
  l.next(); 
  if (good) doLine(labels[l.word()],verbose);
  else doLine(line+1,verbose);
  
}

// Override doWrite to implement FullProg's doExpression

void FullProg::doWrite(int line, bool verbose) {
  int tok = l.next();
  doExpression(tok); pop(-1);
  cout << "\tOUTPUT ---> " << get1() << endl;
  doLine(line+1,verbose);
}


// Recursive descent parser on expressions (adding and subtracting)

void FullProg::doExpression(int & tok) {
 if (tok == Lex::RPAR) {
 	tok = l.next();
 }
 doTerm(tok);
 while (tok == Lex::PLUS || tok == Lex::MINUS) {
   check (!	l.atEnd(),"Reached end of line while parsing.",__LINE__,__FILE__);
   int oper = tok;
   tok = l.next();
   doTerm(tok);
   pop(-2).pop(-1);
   switch (oper) {
   case Lex::PLUS:
     op(ALU::ADD);
     break;
   case Lex::MINUS:
     op(ALU::SUB);
     break;
   }
   push();
 }
}

// Interpreter for terms (multiplicative arithmetic)

void FullProg::doTerm(int & tok) {
 doFactor(tok); 
  while (tok == Lex::TIMES || tok == Lex::DIVIDE || tok == Lex::MODULO) {
   check (!l.atEnd(),"Reached end of line while parsing.",__LINE__,__FILE__);
   int oper = tok;
   tok = l.next();
   doFactor(tok);
   pop(-2).pop(-1);
   switch (oper) {
   case Lex::TIMES:
     op(ALU::MUL);
     break;
   case Lex::DIVIDE:
     op(ALU::DIV);
     break;
   case Lex::MODULO:
     op(ALU::MOD);
     break;
   }
   push();
 }
}

// Interpret a factor (expression,number, or identifier)

void FullProg::doFactor(int & tok) {
  bool doCalc = true;
  switch (tok) {
  case Lex::NUMBER: set1(l.word().toInt()); break;
  case Lex::IDENTIFIER: set1(vars[l.word()]); break;
  case Lex::LPAR: 
    tok = l.next();
    doExpression(tok);
    doCalc = false;
    break;
  } if (doCalc) {
  	set2(0);
  	op(ALU::ADD);
  	push();
  }
  tok = l.next();
}
