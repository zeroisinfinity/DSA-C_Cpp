#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstdbool>

typedef int** solptr;
typedef int* arrptr[];
typedef int* temp;

void attach(int size, int* arr , solptr ptr_ptr) {//b4
    for (int i = 0; i < size; i++){//b8
        ptr_ptr[i] = &arr[i];
    }//b8
}//b4
//
// Created by sahil on 6/23/25.
//
