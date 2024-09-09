#ifndef SIENAMEMORY_H
#define SIENAMEMORY_H

#define HEAP_SIZE 1024

typedef struct SienaHeap {
	char block[HEAP_SIZE];
	unsigned int cap = HEAP_SIZE;
} SienaHeap;

typedef struct SienaBlock {
	struct SienaBlock* next;
	struct SienaBlock* prev;
	void* pointer;
	unsigned int size;
} SienaBlock;

void SienaHeap_Init(SienaHeap* heap);
void* SienaAllocate(SienaHeap* heap, unsigned int size);
SienaBlock* getLastBlock(SienaHeap* heap);

#endif // INCLUDE_SIENAMEMORY_H
