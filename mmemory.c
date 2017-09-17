//
// Created by shund on 12.09.2017.
//
#include <malloc.h>
#include <stdio.h>
#include <mem.h>
#include <assert.h>
#include "mmemory.h"
#include "memory_area.h"

Linked_list *linked_list;

void print_list() {
    Node *index_node = linked_list->head;
    while (index_node != NULL) {
        printf("currentNode - %d  previous - %d next - %d va - %d, isEmpty - %d, size - %d\n",
               index_node,index_node->previous,index_node->next, index_node->value->va, index_node->value->isEmpty,
               index_node->value->size);
        index_node = index_node->next;
    }
}


int _malloc(VA *ptr, size_t szBlock) {
    if (linked_list == NULL) return UNKNOWN_ERROR;
    if (ptr == NULL || szBlock <= 0 || get_node(linked_list, *ptr) != NULL) return INVALID_PARAMETERS;

    int new_node_size;
    VA new_node_va;
    int index = 0;
    Node *index_node = linked_list->head;
    while (index_node != NULL) {
        if (index_node->value->isEmpty) {
            if (index_node->value->size == szBlock) {
                *ptr = index_node->value->va;
                index_node->value->isEmpty = false;
                return SUCCESSFUL_IMPLEMENTATION;
            } else if (index_node->value->size > szBlock) {
                *ptr = index_node->value->va;

                new_node_size = szBlock;
                new_node_va = index_node->value->va; // TODO: double check

                index_node->value->va = new_node_va + new_node_size;
                index_node->value->size -= szBlock;

                Memory_block *block = create_memory_block(new_node_va, new_node_size);
                block -> isEmpty = false;
                //index_node->value->isEmpty = false;

                insert(linked_list, index_node->previous, index_node, block);

                return SUCCESSFUL_IMPLEMENTATION;
            }
        }
        if (index_node->next == NULL) return LACK_OF_MEMORY;
        index++;
        index_node = index_node->next;
    }
    return UNKNOWN_ERROR;
}

int _init(int n, int szPage) {
    if (n < 0 || szPage < 0) return INVALID_PARAMETERS;
    linked_list = (Linked_list *) malloc(sizeof(Linked_list));
    if (linked_list == NULL) return UNKNOWN_ERROR;
    int size = n * szPage;
    Node *new_node = init_node(size);
    linked_list->size = size;
    linked_list->head = new_node;
    return SUCCESSFUL_IMPLEMENTATION;
}


int _free(VA ptr) { //!!!!!
    if (linked_list == NULL) return UNKNOWN_ERROR;
    if (ptr == NULL || get_node(linked_list, ptr) == NULL) return INVALID_PARAMETERS;
    Node *index_node = linked_list->head;
    while (index_node != NULL) {
        if (index_node->value->va == ptr && index_node->value->isEmpty == 0) {
            if (index_node->previous != NULL && index_node->previous->value->isEmpty
                && index_node->next != NULL && index_node->next->value->isEmpty) {
               // printf("double\n");
                index_node->previous->value->size += index_node->value->size;
                index_node->previous->value->size += index_node->next->value->size;
                delete_node(linked_list, index_node->next);
                delete_node(linked_list, index_node);
            } else if (index_node->previous != NULL && index_node->previous->value->isEmpty) {
               // printf("previous\n");
                index_node->previous->value->size += index_node->value->size;
                delete_node(linked_list, index_node);
            } else if (index_node->next != NULL && index_node->next->value->isEmpty) {
               // printf("next\n");
                index_node->value->size += index_node->next->value->size;
                index_node->value->isEmpty = 1;
                delete_node(linked_list, index_node->next);
            } else {
              //  printf("nothing\n");
                index_node->value->isEmpty = 1;
            }
            free(ptr);
            return SUCCESSFUL_IMPLEMENTATION;
        }
        index_node = index_node->next;
    }
    return UNKNOWN_ERROR;
}

int _write(VA ptr, void *pBuffer, size_t szBuffer) {
    if (ptr == NULL || pBuffer == NULL || szBuffer < 0) { return INVALID_PARAMETERS; }
    if (linked_list == NULL) { return UNKNOWN_ERROR; }
    Node *index_node = linked_list->head;
    printf("ptr %d \n", ptr);
    printf("head %d \n", linked_list->head->value->va);
    // printf("tail %d \n",linked_list->tail->value->va);
    printf("size %d \n", linked_list->size);
    if (linked_list->head->value->va <= ptr && ptr + szBuffer <= linked_list->head->value->va + linked_list->size) {
        printf("check \n");
        while (index_node != NULL) {
            printf("va %d  is empty %d\n", index_node->value->va, index_node->value->isEmpty);
            if (index_node->value->va == ptr && index_node->value->isEmpty == 0) {
                if (index_node->value->va + index_node->value->size - ptr < szBuffer) { return LACK_OF_MEMORY; }
                memcpy(ptr, pBuffer, szBuffer);
                return SUCCESSFUL_IMPLEMENTATION;
            }
            index_node = index_node->next;
        }
    } else return LACK_OF_MEMORY;

    return UNKNOWN_ERROR;
}

int _read(VA ptr, void *pBuffer, size_t szBuffer) {
    if (ptr == NULL || pBuffer == NULL || szBuffer < 0) { return INVALID_PARAMETERS; }
    if (linked_list == NULL) { return UNKNOWN_ERROR; }
    Node *index_node = linked_list->head;
    while (index_node != NULL) {
        if (!index_node->value->isEmpty) {
            if (index_node->value->va <= ptr && index_node->value->va + linked_list->size > ptr) {
                if (index_node->value->va + linked_list->size - ptr < szBuffer) { return LACK_OF_MEMORY; }
                memcpy(pBuffer, ptr, szBuffer);
                return SUCCESSFUL_IMPLEMENTATION;
            }
        }
        index_node = index_node->next;
    }
    return LACK_OF_MEMORY;
}