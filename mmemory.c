//
// Created by shund on 12.09.2017.
//
#include <malloc.h>
#include <stdio.h>
#include "mmemory.h"
#include "memory_area.h"

Linked_list *linked_list;

int _malloc(VA* ptr, size_t szBlock) {
    int next_node_size;
    VA next_node_va;
    int index = 0;
    Node* index_node = linked_list->head;

    while (index_node != NULL) {
        if (index_node->value->isEmpty) {
            if (index_node->value->size == szBlock) {
                *ptr = index_node->value->va;

                index_node->value->size = szBlock;
                index_node->value->isEmpty = false;

                return SUCCESSFUL_IMPLEMENTATION;
            } else if (index_node->value->size > szBlock) {
                *ptr = index_node->value->va;

                next_node_size = index_node->value->size - szBlock;
                next_node_va = index_node->value->va + szBlock;

                index_node->value->size = szBlock;
                index_node->value->isEmpty = false;

                insert(linked_list, index, create_memory_block(next_node_va, next_node_size));

                return SUCCESSFUL_IMPLEMENTATION;
            }
        }

        if (index_node->next == NULL) {
            return LACK_OF_MEMORY;
        }

        index++;
        index_node = index_node->next;
    }
    return UNKNOWN_ERROR;
}
int _init(int n, int szPage){
    if (n  <  0 || szPage < 0) {
        return INVALID_PARAMETERS;
    }
    linked_list = (Linked_list*)malloc(sizeof(Linked_list));
    int size = n * szPage;
    Node *new_node = init_node(size);
    linked_list->size = 1;
    linked_list->head = new_node;
    linked_list->tail = new_node;
    return SUCCESSFUL_IMPLEMENTATION;
}
