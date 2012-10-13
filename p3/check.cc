#include "check.h"
using namespace std;

void check(bool good, char * errmsg, int line, char * file) {
  if (!good) {
    cerr << errmsg << " in " << file << " on line " << line;
    exit(0);
  }
}
