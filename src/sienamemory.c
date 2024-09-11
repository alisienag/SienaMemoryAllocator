#include "../include/sienamemory.h"



int SienaHeap_Init(SienaHeap* heap) {
	SienaBlock* first;
	first->size = 1;
	first->prev = NULL;
	first->next = NULL;
	first->pointer = &heap->block[0];
	heap->cap = HEAP_SIZE;
	heap->first = first;
	heap->last = first;
	return 0;
}

void* SienaAskMemory(SienaHeap* heap) {

}

int SienaGiveMemory(SienaHeap* heap, void* memory) {
	if (memory == NULL) {
		return 1;
	}
	SienaBlock* copy_pointer = heap->first;
	while (copy_pointer->pointer != memory) {
		copy_pointer = copy_pointer->next;
		if (copy_pointer == NULL) {
			return 1;
		}
	}
	
	if (copy_pointer == heap->first) {
		heap->first->next->prev = NULL;
		heap->first = heap->first->next;
	} else if (copy_pointer == heap->last) {
		heap->last->prev->next = NULL;
	} else {
		copy_pointer->prev->next = copy_pointer->next;
	}

	copy_pointer->next = NULL;
	copy_pointer->prev = NULL;
	copy_pointer->pointer = NULL;

	return 0;
}

SienaBlock* getLastBlock(SienaHeap* heap) {
	SienaBlock* copy_pointer = heap->first;
	while (copy_pointer->next != NULL) {
		copy_pointer = copy_pointer->next;
	}
	return copy_pointer;
}

void* SienaAllocate(SienaHeap* heap, unsigned int size) {
	SienaBlock* block;
	block->size = size;
	SienaBlock* prev = getLastBlock(heap);
	prev->next = block;
	block->prev = prev;
	block->next = NULL;
	block->pointer = SienaAskMemory(heap);
	return block->pointer;
}


