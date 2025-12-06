#include <iostream>
#include <climits>

using namespace std;

int main(){//b1

       // int arr[7] = {12,-3,11,10,5,-9,1};
        int arr[15] = {6, -9, 4, -1, 2, 1, -12, 7, -3, 8, -20, 5, 4, -2, 9};
        int soln[7];
        soln[0] = arr[0];

        for(int i = 1 ; i < 7 ; ++i){//b2
            if(soln[i-1] < 0) soln[i] = arr[i];
            else soln[i] = arr[i] + soln[i-1];
        }//b2
        
        int sum = 0;

        for(int j = 0 ; j < 7 ; ++j){//b3
            if(soln[j] > sum) sum = soln[j];
        }//b3

        cout << "sum is - " << sum << endl;

        return 0;
}//b1
