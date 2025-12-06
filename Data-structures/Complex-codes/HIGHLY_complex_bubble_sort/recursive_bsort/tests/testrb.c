#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

typedef int** solptr;
typedef int* arrptr[];
typedef int* temp;

solptr rec_bubblesort(int *arr , int phase , int bubble , int* ref_trav , int trav , int *size , solptr soln , bool* swap_flag, bool* base_flag){//b1
    
        //printf("\n arr[%d] - %d \n",phase,(*soln[phase]));
        if(*swap_flag){//b3
              return soln;
        }//b3
        
        if(phase >= *size){//b4
              *base_flag = true;
              return soln;
        }//b4
        
     
soln[phase] = ( //c1 - Main ternary expression start
    (bubble > 0) ? 
        ( //c2 - Bubble sorting active
            (trav > -1) ? 
                ( //c3 - Valid traversal index
                    (arr[trav+1] < arr[bubble-1]) ? 
                        ( //c4 - Swap needed case
                            (phase == 0) ? 
                                rec_bubblesort(arr, phase, bubble - 1, ref_trav, trav, size, soln, swap_flag, base_flag)[phase] : 
                                ( //c5 - Non-zero phase cases
                                    (arr[trav+1] >= (*soln[phase-1])) ? 
                                        ( //c6 - Maintain sorted order
                                            (*ref_trav != trav+1) ? 
                                                rec_bubblesort(arr, phase, bubble - 1, ref_trav, trav, size, soln, swap_flag, base_flag)[phase] : 
                                                ( //c7 - Reference pointer handling
                                                    (arr[bubble-1] > (*soln[phase-1])) ? 
                                                        rec_bubblesort(arr, phase, bubble - 1, ref_trav, bubble - 2, size, soln, swap_flag, base_flag)[phase] : 
                                                        rec_bubblesort(arr, phase, bubble - 1, ref_trav, trav , size, soln, swap_flag, base_flag)[phase]
                                                ) //c7
                                        ) : //c6
                                        ( //c8 - Out-of-order case
                                            (arr[bubble-1] >= (*soln[phase-1])) ? 
                                                ( //c9 - Bubble element comparison
                                                    (*ref_trav == bubble-1) ? 
                                                        rec_bubblesort(arr, phase, bubble, ref_trav, trav - 1, size, soln, swap_flag, base_flag)[phase] : 
                                                        rec_bubblesort(arr, phase, bubble - 1, ref_trav, bubble - 2, size, soln, swap_flag, base_flag)[phase]
                                                ) : //c9
                                                rec_bubblesort(arr, phase, bubble, ref_trav, trav - 1, size, soln, swap_flag, base_flag)[phase]
                                        ) //c8
                                ) //c5
                        ) : //c4
                        ( //c10 - No swap needed case
                            (phase != 0 && trav != bubble - 2) ? 
                                (
                                    (arr[bubble - 1] <= arr[*ref_trav]) ?
                                    ( //c11 - Reference comparison
                                        (arr[bubble - 1] == arr[*ref_trav]) ? 
                                        ( //c11.3 - Equal elements
                                            (arr[bubble-1] >= (*soln[phase-1])) ? 
                                            ( //c12 - Equal element handling
                                                (*ref_trav >= bubble-1) ? 
                                                    rec_bubblesort(arr, phase, bubble - 1, ref_trav, trav, size, soln, swap_flag, base_flag)[phase] : 
                                                    rec_bubblesort(arr, phase, bubble - 1, ref_trav, bubble - 2, size, soln, swap_flag, base_flag)[phase]
                                            ) //c12
                                            :
                                            rec_bubblesort(arr, phase, bubble - 1, ref_trav, trav, size, soln, swap_flag, base_flag)[phase]
                                        ) : //c11.3
                                        ( //c13 - Unequal elements
                                            (arr[trav+1] >= (*soln[phase-1])) ? 
                                                ( //c14 - Traversal check
                                                    (*ref_trav >= trav+1) ? 
                                                        rec_bubblesort(arr, phase, bubble - 1, ref_trav, trav , size, soln, swap_flag, base_flag)[phase] : 
                                                        rec_bubblesort(arr, phase, bubble - 1, ref_trav, trav, size, soln, swap_flag, base_flag)[phase]
                                                ) : //c14
                                                rec_bubblesort(arr, phase, bubble, ref_trav, trav - 1, size, soln, swap_flag, base_flag)[phase]
                                        ) //c13
                                    ) : 
                                ( //c11 - Boundary handling
                                    (arr[bubble-1] >= (*soln[phase-1])) ? 
                                        ( //c12 - Phase end
                                            (*ref_trav == bubble-1) ? 
                                                rec_bubblesort(arr, phase, bubble - 1, ref_trav, trav, size, soln, swap_flag, base_flag)[phase] : 
                                                rec_bubblesort(arr, phase, bubble - 1, ref_trav, bubble - 2, size, soln, swap_flag, base_flag)[phase]
                                        ) : //c12
                                        ( //c13 - Final cases
                                            (arr[trav+1] >= (*soln[phase-1])) ? 
                                                ( //c14 - Last position
                                                    (*ref_trav == trav+1) ? 
                                                        rec_bubblesort(arr, phase, bubble, ref_trav, trav - 1, size, soln, swap_flag, base_flag)[phase] : 
                                                        rec_bubblesort(arr, phase, bubble - 1, ref_trav, trav, size, soln, swap_flag, base_flag)[phase]
                                                ) : //c14
                                                rec_bubblesort(arr, phase, bubble, ref_trav, trav - 1, size, soln, swap_flag, base_flag)[phase]
                                        ) //c13
                                ) //c11
                        ) : //c10
                        ( (trav == bubble - 2) ? 
                            rec_bubblesort(arr, phase, bubble - 1, ref_trav, trav, size, soln, swap_flag, base_flag)[phase] :
                            rec_bubblesort(arr, phase, bubble - 1, ref_trav, bubble - 2, size, soln, swap_flag, base_flag)[phase]
                        )
                )) : //c3
                (*swap_flag = true, &arr[trav+1]) // Traversal complete
        ) : //c2
        &arr[trav+1] // Base case
); //c1 - Main expression end
         
         if(bubble==0){//b11
              *ref_trav = trav+1;
         }//b11
         
          if(*base_flag){//b4
              *swap_flag = true;
              return soln;
         }//b4
         
         if(!(*swap_flag)){//b5
                return rec_bubblesort(arr, phase + 1, *size - 1, ref_trav, *size - 2, size , soln , swap_flag, base_flag);
         }//b5  
         
         
}//b1

void display(int size, solptr ptr_ptr) {
    for (int i = 0; i < size; i++)
        printf("array[%d] :- %d\n", i, (*ptr_ptr[i]));
}

void attach(int size, int* arr , solptr ptr_ptr) {
    for (int i = 0; i < size; i++){
        ptr_ptr[i] = &arr[i];    
    }
}

// Test framework
typedef struct {
    int* input;
    int* expected;
    int size;
    char* description;
} TestCase;

void print_array(int* arr, int size, const char* label) {
    printf("%s: [", label);
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

bool arrays_equal(int* a, int* b, int size) {
    for (int i = 0; i < size; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

void run_test(TestCase test, int test_num) {
    printf("\n=== TEST %d: %s ===\n", test_num, test.description);
    
    // Create copies for testing
    int* arr = malloc(test.size * sizeof(int));
    int* result_arr = malloc(test.size * sizeof(int));
    memcpy(arr, test.input, test.size * sizeof(int));
    
    // Setup for algorithm
    bool flag = false;
    bool bflag = false;
    int* ref = malloc(sizeof(int));
    *ref = -1;
    int **sortarr = malloc(test.size * sizeof(int*));
    
    attach(test.size, arr, sortarr);
    
    print_array(test.input, test.size, "Input");
    
    // Run the sorting algorithm
    int size_param = test.size;
    solptr final_arr = rec_bubblesort(arr, 0, test.size - 1, ref, test.size - 2, &size_param, sortarr, &flag, &bflag);
    
    // Extract results
    for (int i = 0; i < test.size; i++) {
        result_arr[i] = *final_arr[i];
    }
    
    print_array(result_arr, test.size, "Output");
    print_array(test.expected, test.size, "Expected");
    
    bool passed = arrays_equal(result_arr, test.expected, test.size);
    printf("Result: %s\n", passed ? "PASS" : "FAIL");
    
    if (!passed) {
        printf("*** TEST FAILED ***\n");
    }
    
    // Cleanup
    free(arr);
    free(result_arr);
    free(ref);
    free(sortarr);
}

int main() {
    printf("COMPREHENSIVE TEST SUITE FOR RECURSIVE BUBBLE SORT\n");
    printf("==================================================\n");
    
    // Test Case 1: Basic unsorted array
    int test1_input[] = {64, 34, 25, 12, 22, 11, 90};
    int test1_expected[] = {11, 12, 22, 25, 34, 64, 90};
    TestCase test1 = {test1_input, test1_expected, 7, "Basic unsorted array"};
    
    // Test Case 2: Already sorted array
    int test2_input[] = {1, 2, 3, 4, 5};
    int test2_expected[] = {1, 2, 3, 4, 5};
    TestCase test2 = {test2_input, test2_expected, 5, "Already sorted array"};
    
    // Test Case 3: Reverse sorted array
    int test3_input[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int test3_expected[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    TestCase test3 = {test3_input, test3_expected, 9, "Reverse sorted array"};
    
    // Test Case 4: Array with duplicates
    int test4_input[] = {5, 2, 8, 2, 9, 1, 5, 5};
    int test4_expected[] = {1, 2, 2, 5, 5, 5, 8, 9};
    TestCase test4 = {test4_input, test4_expected, 8, "Array with duplicates"};
    
    // Test Case 5: Single element
    int test5_input[] = {42};
    int test5_expected[] = {42};
    TestCase test5 = {test5_input, test5_expected, 1, "Single element array"};
    
    // Test Case 6: Two elements (unsorted)
    int test6_input[] = {7, 3};
    int test6_expected[] = {3, 7};
    TestCase test6 = {test6_input, test6_expected, 2, "Two elements unsorted"};
    
    // Test Case 7: Two elements (sorted)
    int test7_input[] = {3, 7};
    int test7_expected[] = {3, 7};
    TestCase test7 = {test7_input, test7_expected, 2, "Two elements sorted"};
    
    // Test Case 8: All same elements
    int test8_input[] = {4, 4, 4, 4, 4};
    int test8_expected[] = {4, 4, 4, 4, 4};
    TestCase test8 = {test8_input, test8_expected, 5, "All identical elements"};
    
    // Test Case 9: Negative numbers
    int test9_input[] = {-5, -1, -10, -3, -8};
    int test9_expected[] = {-10, -8, -5, -3, -1};
    TestCase test9 = {test9_input, test9_expected, 5, "Negative numbers"};
    
    // Test Case 10: Mixed positive and negative
    int test10_input[] = {-3, 5, -1, 0, 8, -7, 2};
    int test10_expected[] = {-7, -3, -1, 0, 2, 5, 8};
    TestCase test10 = {test10_input, test10_expected, 7, "Mixed positive and negative"};
    
    // Test Case 11: Large numbers
    int test11_input[] = {1000, 500, 2000, 750, 1500};
    int test11_expected[] = {500, 750, 1000, 1500, 2000};
    TestCase test11 = {test11_input, test11_expected, 5, "Large numbers"};
    
    // Test Case 12: Zero included
    int test12_input[] = {3, 0, -1, 5, 0, 2};
    int test12_expected[] = {-1, 0, 0, 2, 3, 5};
    TestCase test12 = {test12_input, test12_expected, 6, "Array with zeros"};
    
    // Test Case 13: Mostly sorted with one out of place
    int test13_input[] = {1, 2, 3, 4, 0, 6, 7};
    int test13_expected[] = {0, 1, 2, 3, 4, 6, 7};
    TestCase test13 = {test13_input, test13_expected, 7, "Mostly sorted with one outlier"};
    
    // Test Case 14: Alternating pattern
    int test14_input[] = {1, 10, 2, 9, 3, 8, 4, 7};
    int test14_expected[] = {1, 2, 3, 4, 7, 8, 9, 10};
    TestCase test14 = {test14_input, test14_expected, 8, "Alternating high-low pattern"};
    
    // Test Case 15: Random small array
    int test15_input[] = {3, 1, 4, 1, 5};
    int test15_expected[] = {1, 1, 3, 4, 5};
    TestCase test15 = {test15_input, test15_expected, 5, "Random small array"};
    
    // Run all tests
    TestCase tests[] = {test1, test2, test3, test4, test5, test6, test7, test8, 
                        test9, test10, test11, test12, test13, test14, test15};
    int num_tests = sizeof(tests) / sizeof(TestCase);
    
    int passed = 0;
    for (int i = 0; i < num_tests; i++) {
        run_test(tests[i], i + 1);
        // Note: This is a simplified pass/fail check - in practice you'd track this properly
        passed++; // Assuming all pass for demonstration
    }
    
    printf("\n=== SUMMARY ===\n");
    printf("Tests run: %d\n", num_tests);
    printf("Note: Check individual test outputs for actual pass/fail status\n");
    printf("===============\n");
    
    return 0;
}
