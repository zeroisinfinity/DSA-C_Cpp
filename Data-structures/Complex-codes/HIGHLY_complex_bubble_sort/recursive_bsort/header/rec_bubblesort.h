#ifndef REC_BUBBLESORT_H
#define REC_BUBBLESORT_H



    typedef int** solptr;
    typedef int* arrptr[];
    typedef int* temp;

    /**
     * Recursive bubble sort function.
     *
     * @param arr         Pointer to the original array
     * @param phase       Current phase of recursion
     * @param bubble      Current index in bubbling
     * @param ref_trav    Reference tracker pointer
     * @param trav        Traversal index
     * @param size        Pointer to array size
     * @param soln        Solution pointer-to-pointer (2D array)
     * @param swap_flag   Pointer to bool that tracks if swap is needed
     * @param base_flag   Pointer to bool that tracks base case
     * @return            2D pointer representing sorted result
     */
    solptr rec_bubblesort(int *arr , int phase , int bubble , int* ref_trav , int trav , int *size , solptr soln , bool* swap_flag, bool* base_flag);



#endif // REC_BUBBLESORT_H
