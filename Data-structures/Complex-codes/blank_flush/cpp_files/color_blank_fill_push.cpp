//
// Created by sahil on 6/10/25.
//

#include <iostream>
using namespace std;

int blank_fill_push(char* colors , int size){//b1

    try{//b2
        int anchor = 0;
        int hue = 0;
        bool flag = true;
        while(hue < size){//b4
            if (colors[hue] == '-'){//b7
                if (flag) {//b8
                    hue++;
                }//b8
                else{//b9
                    colors[hue] = colors[anchor];
                    colors[anchor] = '-';
                    anchor++;
                    hue++;
                }//b9
            }//b7
            else{//b5
                if (flag) {//b10
                    anchor = hue;
                }//b10
                flag = false;
                hue++;
            }//b5

        }//b4
        if (anchor==0 && flag){//b10
            return -1;
        }//b10
        if (anchor == 0){//b11
            return 1;
        }//b11

        return 0;
    }//b2
    catch (...){//b3
        cout << "caught" << endl;
        return -2;
        }//b3
}//b1