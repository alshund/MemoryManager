//
// Created by shund on 11.09.2017.
//
#include <stdio.h>
#include <malloc.h>
#include <mem.h>
#include <assert.h>
#include "mmemory.h"

void malloc_free_test() {
    VA va1;
    VA va2;
    VA va3;
    VA va4 = malloc(5);

    int err = _malloc(&va1, 11);
    assert(0 == err);
    err = _malloc(&va2, 1);
    assert(0 == err);
    err = _malloc(&va3, 9);
    assert(-2 == err);

    err = _free(va1);
    assert(0 == err);
    err = _free(va2);
    assert(0 == err);
    err = _free(va4);
    assert(-2 == err);
    printf("malloc free test passed \n");
}

int main() {
    _init(1, 15);
//    VA va1;
//    VA va2;
//    VA va3;

//    _malloc(&va1, 11);
//    _malloc(&va2, 1);
//    _malloc(&va3, 9);
//    char *buffer = "qwerty";
//    VA allocated_buffer = (char *) malloc(sizeof(char) * 6);
//    _free(va1);
//    printf("%d\n", _write(va1, buffer, 10));
//    printf("%d\n", _read(va1+3, allocated_buffer, 9));
    malloc_free_test();

    return 0;
}