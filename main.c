//
// Created by shund on 11.09.2017.
//
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include "mmemory.h"

void malloc_test() {
    VA va1;
    VA va2;
    VA va3;
    int err = _malloc(&va1, 11);
    assert(0 == err);
    err = _malloc(&va2, 1);
    assert(0 == err);
    err = _malloc(&va3, 9);
    assert(-2 == err);

    _free(va1);
    _free(va2);
    _free(va3);
    printf("malloc test passed \n");
}

void free_test(){
    VA va1;
    VA va2;
    VA va3 = malloc(5);

    _malloc(&va1, 11);
    _malloc(&va2, 1);

    int err = _free(va1);
    assert(0 == err);
    err = _free(va2);
    assert(0 == err);
    err = _free(va3);
    assert(-2 == err);
    printf("free test passed \n");
}

void write_test(){
    VA va1;
    VA va2;

    _malloc(&va1, 2);
    _malloc(&va2, 12);
    printf("va1 %d \n",va1);
    printf("va2 %d \n",va2);
    char *buffer = "qwerty";
   // VA allocated_buffer = (char *) malloc(sizeof(char) * 6);
    int err = _write(va2, buffer, 9);
   // assert(-2 == err);
    printf("%d",err);
}

int main() {
    _init(1, 15);
    malloc_test();
    free_test();
    write_test();
    return 0;
}