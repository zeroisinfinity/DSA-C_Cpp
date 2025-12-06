//
// Created by sahil on 6/19/25.
//

#ifndef BUBBLESORT_ITR_H
#define BUBBLESORT_ITR_H
typedef int (*IntArrayPtr)[];
IntArrayPtr bubblesort(int size, int *arr, IntArrayPtr ret_ptr);
void display(int size, IntArrayPtr ptr_to_arr);
#endif //BUBBLESORT_ITR_H
