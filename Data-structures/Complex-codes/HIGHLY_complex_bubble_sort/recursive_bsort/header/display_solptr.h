//
// Created by sahil on 6/23/25.
//

#ifndef DISPLAY_SOLPTR_H
#define DISPLAY_SOLPTR_H
typedef int** solptr;
typedef int* arrptr[];
typedef int* temp;
/**
   * Displays the array using pointer-to-pointer representation.
   *
   * @param size     Number of elements
   * @param ptr_ptr  Pointer to pointer of sorted elements
   */
void display_solptr(int size, solptr ptr_ptr);


#endif //DISPLAY_SOLPTR_H
