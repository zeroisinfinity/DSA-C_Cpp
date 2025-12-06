//
// Created by sahil on 6/27/25.
//
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef int (*IntArrayPtr)[];
IntArrayPtr bubblesort(int size, int *arr, IntArrayPtr ret_ptr) {//b1
    int trav = 0;
    int swap_flag = INT_MAX;
    int *bubble = (int*)malloc(sizeof(int));

    for (int *phase = &trav; (*phase < size - 1) && (swap_flag > (*phase + 1 - size)); (*phase)++) {//b2
        swap_flag = 0;
        for (*bubble = 0; (*bubble < size - 1 - *phase); (*bubble)++) {//b3
            arr[*bubble] = (arr[*bubble] > arr[*bubble + 1]
                            ?
                            ((arr[*bubble] ^= (arr[*bubble + 1] ^= (arr[*bubble] ^= arr[*bubble + 1]))) + (swap_flag++)*0)
                            :
                            (arr[*bubble] + (swap_flag--)*0)
            );
        }//b3
    }//b2
    free(bubble);
    bubble = nullptr;
    return ret_ptr;
}//b1

void display(int size, IntArrayPtr ptr_to_arr) {
    for (int i = 0; i < size; i++)
        printf("array[%d] :- %d\n", i, (*ptr_to_arr)[i]);
}

/*
int main() {
    int *records = malloc(sizeof(int));
    printf("Enter the size of array :- ");
    scanf("%d", records);
    int *array = malloc((*records) * sizeof(int));
    for (int i = 0; i < *records; i++) {
        printf("Enter array[%d] :- ", i);
        scanf("%d", &array[i]);
    }
    IntArrayPtr (*bubblesort_ptr)(int,int*,IntArrayPtr) = bubblesort;
    IntArrayPtr final_arr = bubblesort_ptr(*records, array, (IntArrayPtr)array);
    display(*records, final_arr);
    free(array);
    free(records);
    return 0;
}
*/
