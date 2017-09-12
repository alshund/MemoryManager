//
// Created by shund on 12.09.2017.
//
#include <malloc.h>
#include <stdio.h>
#include "mmemory.h"
#include "memory_area.h"

node *head;

int _malloc(VA* ptr, size_t szBlock) {
    node* index_node = head;
    int next_node_size;
    while (index_node != NULL) {
        if (index_node->data->isEmpty == 1) {
            if (index_node->data->size > szBlock) {
                next_node_size = index_node->data->size - szBlock;
                index_node->data->size = szBlock;
                index_node->data->isEmpty = 0;
                VA next_node_va = index_node->data->va + index_node->data->size;
                *ptr = index_node->data->va;
                node* next_node = create_node(create_memory_block(next_node_va, next_node_size), index_node,index_node->next );
                index_node->next = next_node;
                printf("-1-");
                return 0;
            } else {
                printf("-2-");
            }
        }

        index_node = index_node->next;
    }
    return 0;
}
int _init(int n, int szPage){
    if (n  <  0 || szPage < 0) {
        return -1;
    }
    int size = n * szPage;
    node *new_node = init_node(size);
    head = new_node;
    return 0;
}
