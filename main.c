//
// Created by shund on 11.09.2017.
//
#include <stdio.h>
#include <malloc.h>
#include "mmemory.h"
int main() {
    VA va1;
    VA va2;
    VA va3;
    _init(1, 15);
    _malloc(&va1, 11);
    _malloc(&va2, 1);
    _malloc(&va3, 9);
    printf("%d\n", va1);
    printf("%d\n", va2);
    printf("%d\n", va3);
    _free(va1);
    printf("%d\n", va1);
    printf("%d\n", va2);
    printf("%d\n", va3);

    return 0;
}