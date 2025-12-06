#include <iostream>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include "color_blank_fill_eff.h"
#include "color_blank_fill_ineff.h"
#include "color_blank_fill_nlogn.h"
#include "color_blank_fill_push.h"
#include "entry.h"
#include "display.h"
#include "keeperofthecodes.h"
#include "maximum_logn.h"
#include "maximum.h"
#include "bubblesort_itr.h"
#include "rec_bubblesort.h"
#include "attach.h"
#include "display_solptr.h"
using namespace std;
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.


/*
int main() {
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the <b>lang</b> variable name to see how CLion can help you rename it.*/
/*
int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    char* hues = enter(size);
    display(hues,size);
    //mergeSort(hues,0,size-1);
    int code = blank_fill_push(hues, size);
    const char* ans = decode(code);
    cout << ans << endl;
    cout << endl;
    display(hues,size);
    delete[] hues;*/
/*
    int array[] = {34,67,56,788,5454,78,-9,770,4456,78865,77755,44,77,44,9999};
    //int by1 = array[0], by2 = array[0];
    //void (*maxy)(int*,int,int,int,int) = maximum;
    //int max = maximum(array , array[0] , 0 ,18);
    cout << endl;
    //cout << "max is :" << max;
    maximum(array,2,15);
    //maximum(array,&by1,&by2,1,18);
    cout << array[0] << endl;
    return 0;
    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}*/
int main() {//b5
    // Allocate memory for array size (records holds the value entered by user)
    int *records = (int*)malloc(sizeof(int));
    printf("Enter the size of array :- ");
    scanf("%d", records);

    bool flag = false;
    bool bflag = false;
    int* ref = (int*)malloc(sizeof(int));
    *ref = -1;
    int **sortarr = (int**)malloc((*records) * sizeof(int*)); // ✅ uses initialized value
    // Allocate memory for array elements based on user input
    int *array = (int*)malloc((*records) * sizeof(int));

    // Input loop to fill the array
    for (int i = 0; i < *records; i++) {//b6
        printf("Enter array[%d] :- ", i);
        scanf("%d", &array[i]);
    }//b6

    attach(*records , array , sortarr);
    // Function pointer for bubblesort, for flexibility or callbacks
    solptr (*rec_bubblesort_ptr)(int*,int,int,int*,int,int*,solptr,bool*,bool*) = rec_bubblesort;

    // Call bubble sort and get pointer to sorted array
    solptr final_arr = rec_bubblesort_ptr(array, 0 , *records - 1, ref, *records - 2 , records , (solptr)sortarr , &flag, &bflag);

    // Display the sorted array
    display_solptr(*records, final_arr);


    // Cleanup dynamic memory
    free(array);
    array = nullptr;
    free(records);

    free(sortarr);
    sortarr = nullptr;
    free(ref);
    ref = nullptr;
    //free(final_arr);
    records = nullptr;
    return 0;
}//b5





