#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution{//b1 
        public:
            vector<int> vec;
            int len;
            vector<vector<int>> mem;

            Solution(vector<int> arr){//b2
                    vec = arr;
                    len = arr.size();
                    mem = vector(len , vector<int>(len,-1));
            }//b2

            int part(int i , int j){//b3
                    if(i==j) return 0;
                    if(mem[i][j] != -1) return mem[i][j];
                    int mini = INT_MAX;
                    int cost = 0;
                    for(int k = i ; k < j ; ++k){//b4
                        cost = part(i , k) + part(k+1 , j) + (vec[i-1] * vec[k] * vec[j]) ;
                        if(cost < mini) mini = cost;
                    }//b4
                    return mem[i][j] = mini;
            }//b3
};//b1


int main(){//b5
        vector<int> arr = {40,      20,     30,     10,     30};
        Solution sol = Solution(arr);
        cout << sol.part(1,sol.len - 1) << endl;
        return 0;
}//b5

