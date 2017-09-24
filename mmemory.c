//
// Created by shund on 12.09.2017.
//
#include <malloc.h>
#include <stdio.h>
#include <mem.h>
#include "mmemory.h"
#include "memory_area.h"

Linked_list *linked_list;

int _malloc(VA *ptr, size_t szBlock) {
    if (linked_list == NULL) return UNKNOWN_ERROR;
    if (ptr == NULL) return INVALID_PARAMETERS;

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
                new_node_va = index_node->value->va;

                index_node->value->va = new_node_va + new_node_size;
                index_node->value->size -= szBlock;

                Memory_block *block = create_memory_block(new_node_va, new_node_size);
                block -> isEmpty = false;

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
    if (linked_list != NULL) free(linked_list);
    if (n < 0 || szPage < 0) return INVALID_PARAMETERS;
    linked_list = (Linked_list *) malloc(sizeof(Linked_list));
    if (linked_list == NULL) return UNKNOWN_ERROR;
    int size = n * szPage;
    Node *new_node = init_node(size);
    linked_list->size = size;
    linked_list->head = new_node;
    return SUCCESSFUL_IMPLEMENTATION;
}


int _free(VA ptr) {
    if (linked_list == NULL) return UNKNOWN_ERROR;
    if (ptr == NULL || get_node(linked_list, ptr) == NULL) return INVALID_PARAMETERS;
    Node *index_node = linked_list->head;
    while (index_node != NULL) {
        if (index_node->value->va == ptr && index_node->value->isEmpty == 0) {
            if (index_node->previous != NULL && index_node->previous->value->isEmpty
                && index_node->next != NULL && index_node->next->value->isEmpty) {
                index_node->previous->value->size += index_node->value->size;
                index_node->previous->value->size += index_node->next->value->size;
                delete_node(linked_list, index_node->next);
                delete_node(linked_list, index_node);
            } else if (index_node->previous != NULL && index_node->previous->value->isEmpty) {
                index_node->previous->value->size += index_node->value->size;
                delete_node(linked_list, index_node);
            } else if (index_node->next != NULL && index_node->next->value->isEmpty) {
                index_node->value->size += index_node->next->value->size;
                index_node->value->isEmpty = 1;
                delete_node(linked_list, index_node->next);
            } else {
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
    if (linked_list == NULL) return UNKNOWN_ERROR;
    if (ptr == NULL || pBuffer == NULL || szBuffer < 0) return INVALID_PARAMETERS;
    if (linked_list->head->value->va <= ptr && ptr + szBuffer <= linked_list->head->value->va + linked_list->size) {
        Node *index_node = linked_list->head;
        while (index_node != NULL) {
            if (index_node->value->va <= ptr && ptr + szBuffer <= index_node->value->va + index_node->value->size
                && !index_node->value->isEmpty) {
                memcpy(ptr, pBuffer, szBuffer);
                return SUCCESSFUL_IMPLEMENTATION;
            }
            index_node = index_node->next;
        }
        return LACK_OF_MEMORY;
    } else return LACK_OF_MEMORY;
    return UNKNOWN_ERROR;
}

int _read(VA ptr, void *pBuffer, size_t szBuffer) {
    if (linked_list == NULL) return UNKNOWN_ERROR;
    if (ptr == NULL || pBuffer == NULL || szBuffer < 0) return INVALID_PARAMETERS;
    if (linked_list->head->value->va <= ptr && ptr <= linked_list->head->value->va + linked_list->size) {
        Node *index_node = linked_list->head;
        while (index_node != NULL) {
            if (index_node->value->va <= ptr && ptr + szBuffer <= index_node->value->va + index_node->value->size
                && !index_node->value->isEmpty) {
                memcpy(pBuffer, ptr, szBuffer);
                return SUCCESSFUL_IMPLEMENTATION;
            }
            index_node = index_node->next;
        }
        return LACK_OF_MEMORY;
    } else return LACK_OF_MEMORY;
    return UNKNOWN_ERROR;
}