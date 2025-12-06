//
// Created by sahil on 6/9/25.
//
#include <iostream>
using namespace std;

int blankfill_ineff(char* colors , int size) {//b1

    try {//b2
        int track_blank = -1 , track_hue = 0;
        bool flag1 = true ;
        for (int hue = 0 ; hue < size ; hue ++) {//b4
            for (int col = 0 ; col < size ; col ++) {//b5
                if (colors[col] == '-') {//b6
                    track_blank = col;
                }//b6
            }//b5

            if (track_blank == -1){//b9
                return 1;
            }//b9

            while (flag1){//b7
                if (colors[track_hue] != '-'){//b11
                    flag1 = false;
                }//b11
                else{//b12
                    track_hue++;
                }//b12
                if (track_hue >= size) {//b8
                    return -1;
                }//b8

            }//b7
            if (track_blank <= track_hue){//b10
                return 0;
            }//b10
            colors[track_blank] = colors[track_hue];
            colors[track_hue] = '-';
            flag1 = true;
        }//b4
        return 0;
    }//b2
        catch (...) {//b3
            cout << "caught" << endl;
            return -2;
        }//b3
}//b1

