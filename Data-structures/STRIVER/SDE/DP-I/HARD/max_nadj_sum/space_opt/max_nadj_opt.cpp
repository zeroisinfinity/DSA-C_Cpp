#include <iostream>
#include <vector>
using namespace std;

class Solution{//b1
        public:
            vector<int> vec;
            vector<int> prev;
            int curr;
            size_t len;

            Solution(vector<int>& arr){//b2
                vec = arr;
                len = arr.size();
                prev = vector(2,0);
                curr = 0;
            }//b2

            int nadj(){//b1
                    for(int i = len - 1 ; i >= 0 ; --i){//b4
                        curr = 0;
                        curr = max( prev[0] , vec[i] + prev[1] );
                        prev[1] = prev[0];
                        prev[0] = curr;
                    }//b4
                    return max(prev[0],prev[1]);
            }//b1
};//b1
  


int main(){//b3
            vector<int> arr = {2,4,9,11,3,14,8};
            Solution sol = Solution(arr);
            cout << sol.nadj() << endl;
            return 0;
}//b3



