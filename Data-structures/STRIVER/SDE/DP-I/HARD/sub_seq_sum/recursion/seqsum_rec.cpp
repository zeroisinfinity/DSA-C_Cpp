#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{//b1
               
        public:
            vector<int> arr;
            size_t n;
            int k;

            Solution(){//b2
                arr = {2,3,1,1};
                n = arr.size();
                k = 4;
            }//b2

            bool seqsum(int i , int target){//b3
                if(target == 0) return true;
                if(i == 0) return (arr[0] == target);
                
                bool notake = seqsum(i - 1 , target);
                bool take = false;
                
                if(target >= arr[i]) take = seqsum(i - 1 , target - arr[i]);

                return take || notake;
            }//b3
            
            void play(){//b5
                cout << seqsum(n - 1 , k) << endl;
            }//b5
};//b1

int main(){//b6
        
        Solution sol = Solution();
        sol.play();
}//b6
