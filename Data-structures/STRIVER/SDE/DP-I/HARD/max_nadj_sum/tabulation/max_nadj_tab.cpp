#include <iostream>
#include <vector>
using namespace std;

class Solution{//b1
        public:
            vector<int> vec;
            vector<int> tab;
            size_t len;

            Solution(vector<int>& arr){//b2
                vec = arr;
                len = arr.size();
                tab = vector(len+2,0);
            }//b2

            int nadj(){//b1
                    for(int i = len - 1 ; i >= 0 ; --i){//b4
                        tab[i] = max( tab[i+1] , vec[i] + tab[i+2] );
                    }//b4
                    return tab[0];
            }//b1
};//b1
  


int main(){//b3
            vector<int> arr = {2,4,9,11,3,14,8};
            Solution sol = Solution(arr);
            cout << sol.nadj() << endl;
            return 0;
}//b3


