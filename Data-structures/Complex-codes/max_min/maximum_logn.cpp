//
// Created by sahil on 6/12/25.
//

#include <iostream>
using namespace std;

void maximum(int* arr , int intv, int size , int range = 1 , int trav = 0 ){//b1

    try {//b2
        if (size%2==0){//b10
            if (range >= size/2){//b11
                return;
            }//b11
        }//b10
        else{//b12
            if (range >= size){//b13
                return;
            }//b13
        }//b12
        if (trav + range >= size){//b4
            maximum(arr , intv*2 , size , intv , 0);
        }//b4
        else{//b7
            if (arr[trav] > arr[trav + range]){//b8
                maximum( arr , intv , size , range , trav + intv);
            }//b8
            else{//b9
                int temp = arr[trav];
                arr[trav] = arr[trav + range];
                arr[trav + range] = temp;
                maximum( arr, intv , size , range , trav + intv );
            }//b9
        }//b7
    }//b2

    catch (...){//b3
        cout << "caught exception" << endl;
    }//b3
}//b1