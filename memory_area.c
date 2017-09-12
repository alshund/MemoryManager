//
// Created by shund on 11.09.2017.
//
#include <malloc.h>
#include <stdio.h>
#include "memory_area.h"

memory_block* init_memory_block(size_t size) {
//    VA* va = (VA*)malloc(size);
//    memory_block *new_memory_block = (memory_block*) malloc(sizeof(memory_block));
//    new_memory_block->va = va;
//    new_memory_block->size = size;
//    new_memory_block->isEmpty = 1;
//    return new_memory_block;
}

node* init_node(size_t size) {
    VA va = (VA)malloc(size * sizeof(VA));
    node* new_node = create_node(create_memory_block(va, size), NULL, NULL);
//    node *new_node = (node*) malloc(sizeof(node));
//    new_node->data = init_memory_block(size);
//    new_node->next = NULL;
//    new_node->previous = NULL;
//    return new_node;
    return new_node;
}

memory_block* create_memory_block(VA va, size_t size) {
    memory_block *new_memory_block = (memory_block*) malloc(sizeof(memory_block));
    new_memory_block->va = va;
    new_memory_block->size = size;
    new_memory_block->isEmpty = 1;
    return new_memory_block;
}

node* create_node(memory_block* new_memory_block, node* previous, node* next) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = new_memory_block;
    new_node->previous = previous;
    new_node->next = next;
    return new_node;
}

