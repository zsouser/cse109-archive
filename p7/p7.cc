#include "hash.h"

int main(int argc, char **argv) {
  ifstream data(argv[1]);
  ifstream freq(argv[2]);
  Hash hash(data);
  hash.find(freq);
}


