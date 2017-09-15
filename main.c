//
// Created by shund on 11.09.2017.
//
#include <stdio.h>
#include <malloc.h>
#include <mem.h>
#include "mmemory.h"
int main() {
    VA va1;
    VA va2;
    VA va3;
    _init(1, 15);
    _malloc(&va1, 11);
    _malloc(&va2, 1);
    _malloc(&va3, 9);
    char *buffer = "qwerty";
    VA allocated_buffer = (char *) malloc(sizeof(char) * 6);
    _free(va1);
    printf("%d\n", _write(va1, buffer, 10));
    printf("%d\n", _read(va1+3, allocated_buffer, 9));
//    printf("%s\n", allocated_buffer);


    return 0;
}