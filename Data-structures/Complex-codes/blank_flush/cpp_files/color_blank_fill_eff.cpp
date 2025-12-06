//
// Created by sahil on 6/10/25.
//

#include <iostream>
using namespace std;

// Function to efficiently rearrange characters in the array by pushing '-' to the left
int blankfill_eff(char* colors , int size) {//b1

    try {//b2
        int dec = size - 1 ;  // dec: starts from end of array
        int inc = 0;          // inc: starts from beginning of array

        // Two-pointer approach: work inward from both ends
        while (dec > inc) {//b4

            // If different characters and right is '-', do a swap
            if (colors[dec] != colors[inc] && colors[dec]=='-') {//b5
                colors[dec] = colors[inc];  // move actual character to the right
                colors[inc] = '-';          // fill left with '-'
                inc++;                      // move left pointer forward
                dec--;                      // move right pointer backward
            }//b5

            // If left is already '-', move forward (left is handled)
            if (colors[inc] == '-'){//b6
                inc++;
            }//b6

            // If right is not '-', move backward (right is correctly placed)
            if (colors[dec] != '-'){//b7
                dec--;
            }//b7

        }//b4

        // Edge case: all '-' already at the end, nothing moved
        if (dec == size - 1){//b8
            return -1;  // Indicates array was already well-placed from the back
        }//b8

        // Edge case: all '-' already at the front, nothing to shift
        if (inc == 0){//b9
            return 1;   // Indicates array was already well-placed from the front
        }//b9

        // General case: some changes were made
        return 0;

    }//b2

    // Catch any unexpected runtime exceptions (e.g., nullptr access)
    catch (...) {//b3
        cout << "caught" << endl;
        return -2;
    }//b3

}//b1
