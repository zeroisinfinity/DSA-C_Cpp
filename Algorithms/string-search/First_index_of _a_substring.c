#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int first_index(const char* my_str, const char* sub_str){//b1
    int len_of_mystr = strlen(my_str), len_of_substr = strlen(sub_str);
    int search , sub_search;
    char for_else = 'T';
//Start a loop to traverse
//start
    for( search = 0 ; search < (len_of_mystr - len_of_substr + 1) ; search++ ){//b2
            if(my_str[search] == sub_str[0]){//b3
                    for(sub_search = 1 ; sub_search < len_of_substr ; sub_search++){//b5
                            if(sub_str[sub_search] == my_str[search + sub_search]){//b6
                                if(sub_search == (len_of_substr - 1)){//b6.2
                                    for_else = 'F';
                                }//b6.2
                                    continue;
                            }//b6
                            else{//b7
                                    break;
                            }//b7
                    }//b5
                    if(for_else == 'F'){//b8
                            return search;
                    }//b8
                    continue;
            }//b3
            else{//b4
                continue;
            }//b4
    }//b2
    return -1;
}//b1

int main(){//b1
    size_t len_a = 1000000;
    size_t len_b = 100000000;
    const char *str1 = "hell";
    const char *str2 = "hello";
    // Calculate the total length of the final string (+1 for the null terminator)
    size_t total_length = len_a + strlen(str1) + len_b + strlen(str2) + 1;
    // Allocate memory for the final string
    char *test_str = (char *)malloc(total_length);
    if (test_str == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    // Fill the string with 'a' repeated 1,000,000 times
    memset(test_str, 'a', len_a);
    // Append "hell" after 'a's
    strcpy(test_str + len_a, str1);
    // Append 'b' repeated 100,000,000 times
    memset(test_str + len_a + strlen(str1), 'b', len_b);
    // Append "hello" at the end
    strcpy(test_str + len_a + strlen(str1) + len_b, str2);
        const char* sub_str = "hello";
        clock_t start_time = clock();
        //find(test_str, sub_str);
        first_index(test_str, sub_str);
        //KMPsearch(test_str,sub_str);
        clock_t end_time = clock();
        double time = (double)(end_time - start_time)/CLOCKS_PER_SEC;
        printf("%lf\n",time);
        return 0;
}//b1

//Thats c code of finding first occurrence of substring in 0.18s in 1 billion characters
