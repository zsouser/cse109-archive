#ifndef CHIP_H
#define CHIP_H
#include "memory.h"
#include "/home/zrs212/cse109.101/p0/alu.h"
class Chip : public ALU {
public:
	Memory mem[200];
	int stackpointer;
	Chip();
	Chip(int x);
	Chip(int x, int y);
	Chip(Chip& c);
	~Chip();
	Chip& push();
	Chip& pop();
	Chip& pop(int reg);
	Chip& top(int reg);
	Chip& store(int index);
	Chip& load1(int index);
	Chip& load2(int index);
};
#endif
