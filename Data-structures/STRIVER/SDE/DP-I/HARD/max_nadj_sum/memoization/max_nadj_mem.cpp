#include <iostream>
#include <vector>
using namespace std;

class Solution{//b1
        public:
            vector<int> vec;
            vector<int> mem;
            size_t len;

            Solution(vector<int>& arr){//b2
                vec = arr;
                len = arr.size();
                mem = vector(len,-1);
            }//b2

            int nadj(int i){//b1
                    if(i >= len) return 0;
                    if(mem[i] != -1) return mem[i];
                    return mem[i] = max( nadj(i+1) , vec[i] + nadj(i+2) );
            }//b1
};//b1
  


int main(){//b3
            vector<int> arr = {2,4,9,11,3,14,8};
            Solution sol = Solution(arr);
            cout << sol.nadj(0) << endl;
            return 0;
}//b3

