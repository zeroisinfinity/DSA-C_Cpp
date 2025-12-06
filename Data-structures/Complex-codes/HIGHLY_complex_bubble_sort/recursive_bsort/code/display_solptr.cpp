#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef int** solptr;
typedef int* arrptr[];
typedef int* temp;


void display_solptr(int size, solptr ptr_ptr) {//b4
    for (int i = 0; i < size; i++)
        printf("array[%d] :- %d\n", i, (*ptr_ptr[i]));
}//b4

//
// Created by sahil on 6/23/25.
//
