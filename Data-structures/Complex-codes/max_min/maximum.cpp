#include <iostream>
using namespace std;

void maxtravial(int *arr , int* bysofar , int* bysofar2 , int trav , int size){//b1

    try{//b2

        if(trav < size){//b7

            if(*bysofar < arr[trav]){//b3
                *bysofar = arr[trav];
                maxtravial(arr , bysofar , bysofar2 , trav+1, size);
            }//b3

            else{//b4

                if(*bysofar2 > arr[trav]){//b11
                    *bysofar2 = arr[trav];
                    maxtravial(arr , bysofar , bysofar2 , trav+1, size);
                }//b11

                else{//b12
                    maxtravial(arr , bysofar , bysofar2 , trav+1, size);
                }//b12

            }//b4
        }//b7

        else{//b8
            return;
        }//b8

    }//b2

    catch(...){//b5
        cout << "Caught" << endl;
        return;
    }//b5

}//b1