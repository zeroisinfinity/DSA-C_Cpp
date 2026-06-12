#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{//b1
               

        public:

            vector<int> arr;
            vector<bool> prev;
            vector<bool> curr;

            int n;
            int k;

            Solution() {
                arr = {2, 3, 1 , 1};
                n = arr.size();
                k = 4;      
                prev = curr = vector<bool>(k+1,0);
            }//b2

            bool seqsum(){//b3
                prev[0] = true;
                if(prev[arr[0]] <= k) prev[arr[0]] = true;
                
                for(int i = 1 ; i < n ; ++i){
                    for(int target = 1 ; target <= k ; ++target){
                            displayOpt();
                            bool notake = prev[target];
                            bool take = false;
                            if(take <= target) take = prev[target - arr[i]];
                            curr[target] = (take || notake);
                    }
                    prev = curr;
                }
                return prev[k];
            }//b3
  
            void displayOpt() {
                cout << "\nTabulation Table:\n\n";
                for (int target = 0; target <= k; target++) {
                        cout << prev[target] << " ";
                    }
                    cout << endl;
                }
        
            void play(){//b5
                cout << seqsum() << endl;
            }//b5
};//b1

int main(){//b6
        
        Solution sol = Solution();
        sol.play();
        sol.displayOpt();
}//b6



