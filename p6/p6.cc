#include "fullprog.h"
#include <fstream>
using namespace std;

int main(int argc, char **argv) {
  FullProg f;
  ifstream in(argv[1]);
  f.load(in);
  f.run(argc==3);
}
