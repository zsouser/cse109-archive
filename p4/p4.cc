

#include "lex.h"

void testLex();
void testLexReset();
void preliminaryTest();

int main(){
  preliminaryTest();
  testLex();
  testLexReset();
}

void preliminaryTest(){
  Lex x;
  const char *temp;
  x.setString("  read here ");
  cout<<"---------Start testPrelimnaryTest()---------------------------\n";
  cout<<"Returning tokens for 'read'(8), identifier(1), and '\\n'(22)\n"
      <<"expected output is '8 1 1 read 1 22 22'\n";
  cout<<x.next();
  cout<<" "<<x.peek();
  cout<<" "<<x.peek()<<" ";
  cout<<x.word();
  cout<<" "<<x.next();
  cout<<" "<<x.next();
  cout<<" "<<x.next()<<endl;
  cout<<"Expect 'hello': ";
  temp=Word("hello").toString();
  cout<<temp<<endl;
}

void testLexReset(){
  Lex x;
  int pos,tok;
  cout<<"---------Start testLexReset()---------------------------\n";
  x.setString("enter a ski goto contest");
  tok=x.next();
  cout<<"Expect 'enter' 1: '"<<x.word()<<"' "<<tok<<"\n";
  x.next();
  x.next();
  x.reset();
  tok=x.next();
  cout<<"Again, expect 'enter' 1: '"<<x.word()<<"' "<<tok<<"\n";
  x.next();
  x.next();
  pos=x.position();
  x.next();  //should have 'goto'
  x.next();
  cout<<"Should have 'contest': '"<<x.word()<<"'\n";
  x.reset(pos);
  tok=x.next();
  cout<<"Should have 'goto' 15: '"<<x.word()<<"' "<<tok<<endl;
}

void testLex(){
  Lex x;
  int tok;
  cout<<"---------Start testLex()---------------------------\n";

  /*The identifiers in labels[] have been stored in an order that
  corresponds to the value of the given token,  NUMBER=0,
  IDENTIFIER=1, etc.
  */

  char *labels[]={"NUMBER","IDENTIFIER","PLUS", "MINUS", "TIMES", "DIVIDE",
		    "IF", 
		    "WRITE", "READ","LBRACK", "RBRACK",
		     "LPAR", "RPAR", "BEGIN",
		    "SETEQ", "GOTO", "LT", "GT", "LE",
		    "GE", "EQ", "NE","EOLN","END","COLON","HALT","MODULO"};
    /*Here are lines of text to be parsed */
  Word lines[]={"if write read stack goto",
		 "adent64 64stack == !=) <",
		 "[]()=-/ *addTo enter",
		 "clear 0 getscreen %)  ><",
		 "; test the comment halt",
		 "end End  ; and then comment",
		 "a number 209 -204halt",
                 "+<=>=="};
  for(int lin=0;lin<8;lin++){//for each line, return the tokens
                             //on the line
    cout<< lines[lin]<<endl;
    x.setString(lines[lin]);  //wants every line to ends with '$'
                              //if a line does not, append it
    tok=x.next();
    while(tok!=Lex::EOLN){
      cout<<"->";
      cout<<"['"<<x.word()<<"', ";
      if(tok==x.JUNK)
	cout<<"JUNK";
      else
	cout<<labels[tok];
      if(tok==x.NUMBER)
	cout<<", "<<x.word().toInt();
      cout<<"]";
      tok=x.next();
      //      cin.get();
    }
    cout<<"\n\n";
  }
  x.next();
  x.next(); //should have no effect because at end of line
  //  cerr<<"Leaving main\n";
}

#define OUTPUT
#ifndef OUTPUT
---------Start testPrelimnaryTest()---------------------------
Returning tokens for 'read'(8), identifier(1), and '\n'(22)
expected output is '8 1 1 read 1 22 22'
8 1 1 read 1 22 22
Expect 'hello': hello
---------Start testLex()---------------------------
if write read stack goto
->['if', IF]->['write', WRITE]->['read', READ]->['stack', IDENTIFIER]->['goto', GOTO]

adent64 64stack == !=) <
->['adent64', IDENTIFIER]->['64', NUMBER, 64]->['stack', IDENTIFIER]->['==', EQ]->['!=', NE]->[')', RPAR]->['<', LT]

[]()=-/ *addTo enter
->['[', LBRACK]->[']', RBRACK]->['(', LPAR]->[')', RPAR]->['=', SETEQ]->['-', MINUS]->['/', DIVIDE]->['*', TIMES]->['add', IDENTIFIER]->['T', JUNK]->['o', IDENTIFIER]->['enter', IDENTIFIER]

clear 0 getscreen %)  ><
->['clear', IDENTIFIER]->['0', NUMBER, 0]->['getscreen', IDENTIFIER]->['%', MODULO]->[')', RPAR]->['>', GT]->['<', LT]

; test the comment halt


end End  ; and then comment
->['end', END]->['E', JUNK]->['nd', IDENTIFIER]

a number 209 -204halt
->['a', IDENTIFIER]->['number', IDENTIFIER]->['209', NUMBER, 209]->['-', MINUS]->['204', NUMBER, 204]->['halt', HALT]

+<=>==
->['+', PLUS]->['<=', LE]->['>=', GE]->['=', SETEQ]

---------Start testLexReset()---------------------------
Expect 'enter' 1: 'enter' 1
Again, expect 'enter' 1: 'enter' 1
Should have 'contest': 'contest'
Should have 'goto' 15: 'goto' 15

#endif

