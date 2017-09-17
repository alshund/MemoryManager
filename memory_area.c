//
// Created by shund on 11.09.2017.
//
#include <malloc.h>
#include <stdio.h>
#include "memory_area.h"

Memory_block* init_memory_block(size_t size) {
//    VA* va = (VA*)malloc(size);
//    Memory_block *new_memory_block = (Memory_block*) malloc(sizeof(Memory_block));
//    new_memory_block->va = va;
//    new_memory_block->size = size;
//    new_memory_block->isEmpty = 1;
//    return new_memory_block;
}

Node* init_node(size_t size) {
    VA va = (VA)malloc(size * sizeof(VA));
    Node* new_node = create_node(create_memory_block(va, size), NULL, NULL);
//    Node *new_node = (Node*) malloc(sizeof(Node));
//    new_node->value = init_memory_block(size);
//    new_node->next = NULL;
//    new_node->previous = NULL;
//    return new_node;
    return new_node;
}

Memory_block* create_memory_block(VA va, size_t size) {
    Memory_block *new_memory_block = (Memory_block*) malloc(sizeof(Memory_block));
    new_memory_block->va = va;
    new_memory_block->size = size;
    new_memory_block->isEmpty = true;
    return new_memory_block;
}

Node* create_node(Memory_block* new_memory_block, Node* previous, Node* next) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = new_memory_block;
    new_node->previous = previous;
    new_node->next = next;
    return new_node;
}

void insert (Linked_list *linked_list, size_t index, Memory_block *new_memory_block) {
    Node *elm = get_node_by_index(linked_list, index);
    Node *ins = (Node*)malloc(sizeof(Node));
    ins->value = new_memory_block;
    ins->previous = elm;
    ins->next = elm->next;

    if (elm->next) {
        elm->next->previous = ins;
    }
    elm->next = ins;

    if (!elm->previous) {
        linked_list->head = elm;
    }
    if (!elm->next) {
        linked_list->tail = elm;
    }
}

Node* get_node_by_va (Linked_list *linked_list, VA va) {
    Node *target_node = linked_list->head;
    while (target_node != NULL) {
//        printf("va %d\n", target_node->value->va);
//        printf("size %d\n", target_node->value->size);
//        printf("ptr %d\n", va);
        if (target_node->value->va <= va && target_node->value->va + target_node->value->size > va && target_node->value->isEmpty == false) {
            return target_node;
        }
        target_node = target_node->next;
    }

    return NULL;
}

Node* get_node_by_index(Linked_list *linked_list, size_t index) {
    Node *target_node = linked_list->head;
    size_t i = 0;

    while (target_node && i < index) {
        target_node = target_node->next;
        i++;
    }

    return target_node;
}

void delete_node(Linked_list* linked_list, size_t index){
    Node *elm = NULL;
    elm = get_node_by_index(linked_list, index);
    if (elm->previous) {
        elm->previous->next = elm->next;
    }
    if (elm->next) {
        elm->next->previous = elm->previous;
    }
    if (!elm->previous) {
        linked_list->head = elm->next;
    }
    if (!elm->next) {
        linked_list->tail = elm->previous;
    }

    free(elm);
}