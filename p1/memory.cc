#include "memory.h"
using namespace std;
// Constructors and destructors
Memory::Memory() : value(0) { }
Memory::Memory(int x) : value(x) { }
Memory::Memory(Memory& mem) : value(mem.value) { }
Memory::~Memory() { }
// Accessor and mutator methods
void Memory::set(int x) {
	value = x;
}
int Memory::get() {
	return value;
}
