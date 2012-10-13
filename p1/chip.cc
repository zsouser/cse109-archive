#include "chip.h"
// Constructors and destructor
Chip::Chip(int x=0, int y=0) : ALU::ALU(x,y), mem(), stackpointer(199) {}
Chip::Chip(Chip& c) : ALU::ALU(c.reg1, c.reg2), mem(c.mem), stackpointer(c.stackpointer) {}
Chip::~Chip() { }
/** push() - pushes the accumulator onto the stack and returns the chip object **/
Chip& Chip::push() {
	stackpointer--;
	mem[stackpointer].set(ALU::acc());
	return *this;
}
/** pop() - discards the top element of the stack **/
Chip& Chip::pop() {
	++stackpointer;
	return *this;
}
/** pop(int reg) - performs the functions top() and pop() **/
Chip& Chip::pop(int reg) {
	top(reg);
	pop();
	return *this;
}
/** top(int reg) - either loads the top of the stack into memory or loads the accumulator into memory at a certain location **/
Chip& Chip::top(int reg) {
	if (reg == -1) load1(stackpointer);
	else if (reg == -2) load2(stackpointer);
	else if (reg > 0 && reg < 200) store(reg);
	return *this;
}
/** store(int index) - stores the accumulator in a specified index **/
Chip& Chip::store(int index) {
	mem[index].set(accum);
	return *this;
}
/** load1(int index) - loads a specified index into reg1 **/
Chip& Chip::load1(int index) {
	set1(mem[index].get());
	return *this;
}
/** load2(int index) - loads a specified index into reg2 **/
Chip& Chip::load2(int index) {
	set2(mem[index].get());
	return *this;
}
