#include <iostream>
#include <fstream>
#include "progchip.h"

int main(int argc, char **argv) {
  ProgChip p;
  ifstream in(argv[1]);
  p.load(in);
  p.run(argc==3);
}
