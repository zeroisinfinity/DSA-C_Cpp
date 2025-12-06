//
// Created by sahil on 6/10/25.
//
#include <iostream>
using namespace std;

char* enter(int size){//b1
    char* hues = new char[size];
    for(int i = 0; i < size; i++){//b2
        cin >> hues[i];
    }//b2
    return hues;
}//b2