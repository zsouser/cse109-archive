#include <cstdlib>

void check(bool good, char * errmsg, int line, char * file) {
  if (!good) cerr << errmsg << " in " << file << " on line " << line;
}
