#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{//b1
               

        public:

            vector<int> arr;
            vector<vector<bool>> tab;

            int n;
            int k;

            Solution() {
                arr = {2, 3, 1, 1};
                n = arr.size();
                k = 4;
                tab = vector<vector<bool>>(n, vector<bool>(k + 1, 0));            
            }//b2

            bool seqsum(){//b3
                for(int i = 0 ; i < n ; ++i) tab[i][0] = true;
                if(tab[0][arr[0] <= k) tab[0][arr[0]] = true;
                
                for(int i = 1 ; i < n ; ++i){
                    for(int target = 1 ; target <= k ; ++target){
                            displayTab();
                            bool notake = tab[i-1][target];
                            bool take = false;
                            if(take <= target) take = tab[i-1][target - arr[i]];
                            tab[i][target] = (take || notake);
                    }
                }
                return tab[n-1][k];
            }//b3
  
            void displayTab() {
                cout << "\nTabulation Table:\n\n";
                for (int i = 0; i < n; i++) {
                for (int target = 0; target <= k; target++) {

                    if (tab[i][target] == -1)
                            cout << "- ";
                    else
                            cout << tab[i][target] << " ";
                    }
                    cout << endl;
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
        sol.displayTab();
}//b6


