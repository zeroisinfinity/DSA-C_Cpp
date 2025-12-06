//
// Created by sahil on 6/10/25.
//

#include <iostream>
using namespace std;

const char* decode(int code){//b1

    switch(code){//b2
        case 0:
            return "Array was successfully shifted to right";
        case 1:
            return "Array was already full";
        case -1:
            return "Array was totally blank";
        case -2:
            return "Exception caught";
        default:
            return "Unknown code detected.";

        }//b2
    }//b1