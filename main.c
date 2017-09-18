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
    va4 = NULL;

    free(va2);
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
    int err;
    VA va1;
    VA va2;
    VA va3;
    char *buffer = "write";

    err = _write(va1, buffer, 5);
    assert(-1 == err);

    err = _write(va1, buffer, -1);
    assert(-1 == err);

    _init(1, 25);

    _malloc(&va1, 5);

    err = _write(va1, buffer, 5);
    assert(0 == err);

    _malloc(&va2, 5);
    _malloc(&va3, 10);

    _free(va2);
    va2 = NULL;

    err = _write(va2, buffer, 5);
    assert(-1 == err);

    err = _write(va1, buffer, 10);
    assert(-2 == err);

    err = _write(va1 + 2, buffer, 3);
    assert(0 == err);

    err = _write(va3, buffer, 10);
    assert(0 == err);

    _free(va1);
    va1 = NULL;

    _free(va3);
    va3 = NULL;

    printf("write test passed\n");
}

void read_test() {
    int err;
    VA va1;
    VA va2;
    VA va3;
    char *read_buffer = (char *)malloc(6);
    char *write_buffer = "write";

    err = _read(va1, read_buffer, 5);
    assert(-1 == err);

    err = _read(va1, read_buffer, -1);
    assert(-1 == err);

    _init(1, 25);

    _malloc(&va1, 5);

    _write(va1, write_buffer, 5);
    err = _read(va1, read_buffer, 5);
    assert(0 == err);

    _malloc(&va2, 5);
    _malloc(&va3, 10);

    _write(va2, write_buffer, 2);
    err = _read(va2 + 3, write_buffer, 2);
    assert(-2 == err);
    printf("write test password");
}

int main() {
    malloc_test();
    free_test();
    write_test();
    read_test();
    return 0;
}