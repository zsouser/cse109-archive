#ifndef MEMORY_H
#define MEMORY_H
class Memory {
public:
	Memory();
	Memory(int x);
	Memory(Memory& mem);
	~Memory();
	void set(int x);
	int get();
	int value;
};
#endif
