//
// Created by sahil on 6/15/25.
//

//
// Created by sahil on 6/12/25.
//

#include <iostream>
using namespace std;

//
// Created by sahil on 6/12/25.
//

#include <iostream>
using namespace std;

void maxcompact(int* arr , int intv, int size , int range = 1 , int trav = 0 ){//b1

    try {//b2
        if ((size % 2 == 0 && range >= size) || (size % 2 != 0 && range >= size / 2)) return; //b10, b11, b12, b13

        (trav + range >= size) ?
            maxcompact(arr, intv * 2, size, intv, 0) : //b4
            (arr[trav] > arr[trav + range] ? //b7, b8
                maxcompact(arr, intv, size, range, trav + intv) :
                (swap(arr[trav], arr[trav + range]), maxcompact(arr, intv, size, range, trav + intv)) //b9
            );

    }//b2

    catch (...) {//b3
        cout << "caught exception" << endl;
    }//b3
}//b1
