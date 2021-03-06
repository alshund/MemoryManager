//
// Created by shund on 11.09.2017.
//
#ifndef MEMORYMANAGER_MEMORY_AREA_H
#define MEMORYMANAGER_MEMORY_AREA_H

#include <stdbool.h>
#include "mmemory.h"

#define LACK_OF_MEMORY -2;
#define INVALID_PARAMETERS -1;
#define SUCCESSFUL_IMPLEMENTATION 0;
#define UNKNOWN_ERROR 1;

typedef struct Memory_block {
    VA va;
    size_t size;
    bool isEmpty;
} Memory_block;

typedef struct Node {
    Memory_block *value;
    struct Node *next;
    struct Node *previous;
} Node;

typedef struct Linked_list {
    size_t size;
    Node *head;
} Linked_list;


Node* init_node(size_t size);
Memory_block* create_memory_block(VA va, size_t size);
Node* create_node(Memory_block* new_memory_block, Node* previous, Node* next);
void insert(Linked_list *linked_list, Node *previousNode,Node *nextNode, Memory_block *new_memory_block);
Node* get_node(Linked_list *linked_list, VA va);
void delete_node(Linked_list* linked_list, Node* elem);

#endif //MEMORYMANAGER_MEMORY_AREA_H
