#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int(*bubblesort(int size , int *arr ,  int(*ret_ptr)[size]))[size]{//b1
 int trav = 0;
    bool swap_flag = true;
    int *bubble = malloc(sizeof(int));

    for (int *phase = &trav; *phase < size - 1; (*phase)++) {
        for (*bubble = 0; (*bubble < size - 1 - *phase) && swap_flag; (*bubble)++) {
            arr[*bubble] = (arr[*bubble] > arr[*bubble + 1]
                            ?
                            ((arr[*bubble] ^= (arr[*bubble + 1] ^= (arr[*bubble] ^= arr[*bubble + 1]))) + (swap_flag = 0))
                            :
                            ((*bubble == size - 2 - *phase) ? arr[*bubble] : arr[*bubble])
            );
        }
        if(!swap_flag){
            swap_flag = true;
        }
    }

    free(bubble);
    return ret_ptr;
}

void display(int size , int(*ptr_to_arr)[size]){//b6

      for(int iter = 0 ; iter < size ; iter++)
          printf("array[%d] :- %d", iter, ((*ptr_to_arr)[iter]));

}//b6

int main(){//b7

      int* records = (int*)malloc(sizeof(int));
      printf("Enter the size of array :- ");
      scanf("%d" , records);
      int* array = (int*)malloc((*records) * sizeof(int));
      
      printf("\n"); 
      
       for(int iter = 0 ; iter < *records ; iter++){//b8
          printf("Enter array[%d] :- ", iter);
          scanf("%d" , &array[iter]);
      }//b8
      
      int (*(*bubblesort_ptr)(int , int* , int(*)[*records]))[*records] = bubblesort;
      int(*final_arr)[*records] = bubblesort_ptr(*records , array , (int(*)[*records])array);
      
      printf("\n");
      display(*records , final_arr);
      printf("\n");
      
      free(array);
      array = NULL;
      return 0;
      
}//b7
