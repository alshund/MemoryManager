//
// Created by shund on 11.09.2017.
//
#ifndef MEMORYMANAGER_MEMORY_AREA_H
#define MEMORYMANAGER_MEMORY_AREA_H

#include "mmemory.h"

typedef struct memory_block {
    VA* va;
    size_t size;
    int isEmpty;
} memory_block;

typedef struct node {
    memory_block *data;
    struct node *next;
    struct node *previous;
} node;

memory_block* init_memory_block(size_t size);
node* init_node(size_t size);
memory_block* create_memory_block(VA* va, size_t size);
node* create_node(memory_block* new_memory_block, node* previous, node* next);

#endif //MEMORYMANAGER_MEMORY_AREA_H
