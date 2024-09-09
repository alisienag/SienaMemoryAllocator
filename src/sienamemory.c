#include "../include/sienamemory.h"
void SienaHeap_Init(SienaHeap* heap) {
	SienaBlock* first;
	first->size = 1;
	first->prev = NULL;
	first->next = NULL;
	first->pointer = heap->block[0];
}

void* SienaAllocate(SienaHeap* heap, unsigned int size) {
	SienaBlock* block;
	block->size = size;
	SienaBlock* prev = getLastBlock(heap);
	prev->next = block;
	block->prev = prev;
	block->next = nullptr;
}

SienaBlock* getLastBlock(SienaHeap* heap) {
	SienaHeap* copy_pointer = heap;
	while (copy_pointer->next != null) {
		copy_pointer = copy_pointer->next;
	}
	return copy_pointer;
}
