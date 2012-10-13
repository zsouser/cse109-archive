#ifndef ALU_H
#define ALU_H
#include <iostream>
using namespace std;
class ALU {
public:
  // Constructors
  ALU(int x, int y);
  ALU(int x);
  ALU();
  ALU(ALU& a);
  
  // Flags for operations
  static const int ADD = 0;
  static const int SUB = 1;
  static const int MUL = 2;
  static const int DIV = 3;
  static const int MOD = 4;
  
  // Accessor methods
  int get1(), get2();

  // Mutator methods
  ALU &set1(int x), &set2(int x);

  // Operations
  ALU &op(const int flag);
  int acc();

  // Member variables
  int accum, reg1, reg2;
};
ostream& operator <<(ostream& out, ALU& a);
#endif
