//
// Created by sahil on 6/23/25.
//

#ifndef ATTACH_H
#define ATTACH_H
typedef int** solptr;
typedef int* arrptr[];
typedef int* temp;

/**
    * Attaches original array pointers to pointer-to-pointer structure.
    *
    * @param size     Number of elements
    * @param arr      Original array
    * @param ptr_ptr  Pointer-to-pointer that will point to array elements
    */
   void attach(int size, int* arr , solptr ptr_ptr);
#endif //ATTACH_H
