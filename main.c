//
// Created by shund on 11.09.2017.
//
#include <stdio.h>
#include <malloc.h>
#include "mmemory.h"
int main() {
    VA va;
    _init(12, 12);
    int kek = _malloc(&va, 143);
    printf(" %d - Hello, World!\n", kek);
    return 0;
}