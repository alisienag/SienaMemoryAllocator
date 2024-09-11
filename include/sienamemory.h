#ifndef INCLUDE_SIENAMEMORY_H
#define INCLUDE_SIENAMEMORY_H

#define HEAP_SIZE 1024

#include <stddef.h>

struct SienaBlock;

typedef struct SienaHeap {
	char block[HEAP_SIZE];
	unsigned int cap;
	struct SienaBlock* first;
	struct SienaBlock* last;
} SienaHeap;

typedef struct SienaBlock {
	struct SienaBlock* next;
	struct SienaBlock* prev;
	void* pointer;
	unsigned int size;
} SienaBlock;

int SienaHeap_Init(SienaHeap* heap);
void* SienaAllocate(SienaHeap* heap, unsigned int size);
SienaBlock* getLastBlock(SienaHeap* heap);

#endif // INCLUDE_SIENAMEMORY_H
