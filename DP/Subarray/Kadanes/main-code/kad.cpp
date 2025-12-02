#include <iostream>
#include <climits>

using namespace std;

int main(){//b1

     //   int arr[7] = {12,-3,11,10,5,-9,1};

        //int arr[7] = {8, -4, 3, 2, -6, 7, 5};
    
        int arr[15] = {6, -9, 4, -1, 2, 1, -12, 7, -3, 8, -20, 5, 4, -2, 9};
        int maxsum = INT_MIN;
        int prevsum = arr[0];
        int start = 0, end , br = 0;

        for(int i = 1 ; i < 7 ; ++i){//b2
            if(prevsum < 0){//b5
                prevsum = arr[i];
                br = i;
            }//b5
            else prevsum = arr[i] + prevsum;
            if(prevsum > maxsum){//b6
                maxsum = prevsum;
                start = br;
                end = i;
            }//b6
        }//b2
        
        cout << "sum is - " << maxsum << " with sub i = " << start << " and j = " << end << " . " << endl;

        return 0;
}//b1
