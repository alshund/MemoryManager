//
// Created by shund on 11.09.2017.
//
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include "mmemory.h"

void init_test() {
    int err;
    VA va1;
    VA va2;
}

void malloc_test() {
    int err;
    VA va1;
    VA va2;
    VA va3;
    VA va4;

    err = _malloc(&va1, 11);
    assert(1 == err);

    _init(1, 25);

    err = _malloc(&va1, 10);
    assert(0 == err);
    err = _malloc(&va1, 5);
    assert(-1 == err);


    err = _malloc(NULL, -1);
    assert(-1 == err);

    err = _malloc(&va2, 5);
    assert(0 == err);
    err = _malloc(&va3, 10);
    assert(0 == err);
    _free(va2);
    va2 = NULL;
    err = _malloc(&va2, 4);
    assert(0 == err);
    err = _malloc(&va4, 2);
    assert(-2 == err);
    err = _malloc(&va4, 1);
    assert(0 == err);
    _free(va1);
    va1 = NULL;
    _free(va3);
    va3 = NULL;
    _free(va4);
    va4 = NULL;free(va2);
    va2 = NULL;
    printf("malloc test passed \n");
}

void free_test(){
    int err;
    VA va1;
    VA va2;
    VA va3;
    VA va4;
    VA va5;

    err = _free(va1);
    assert(-1 == err);

    _init(1, 25);

    err = _free(va1);
    assert(-1 == err);

    _malloc(&va1, 10);
    _malloc(&va2, 5);
    _malloc(&va3, 5);
    _malloc(&va4, 5);

    err = _free(va3);
    assert(0 == err);
    va3 = NULL;

    _malloc(&va3,4);
    _malloc(&va5,1);



    err = _free(va1);
    assert(0 == err);
    va1 = NULL;

    err = _free(va2);
    assert(0 == err);
    va2 = NULL;


    err = _free(va4);
    assert(0 == err);
    va4 = NULL;

    err = _free(va5);
    assert(0 == err);
    va5 = NULL;

    err = _free(va3);
    assert(0 == err);
    va3 = NULL;

    err = _free(va3);
    assert(-1 == err);

    printf("free test passed \n");
}

void write_test(){
    _init(1, 15);
    VA va1;
    VA va2;

    _malloc(&va1, 2);
    _malloc(&va2, 12);
    printf("va1 %d \n",va1);
    printf("va2 %d \n",va2);
    char *buffer = "qwerty";
    _free(va2);
   // VA allocated_buffer = (char *) malloc(sizeof(char) * 6);
    int err = _write(va2, buffer, 6);
   // assert(-2 == err);
    printf("%d",err);
}

int main() {
    malloc_test();
    free_test();
   // write_test();
    return 0;
}