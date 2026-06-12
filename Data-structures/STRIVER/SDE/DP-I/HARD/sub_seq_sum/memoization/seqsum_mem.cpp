#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{//b1
               

        public:

            vector<int> arr;
            vector<vector<int>> mem;

            int n;
            int k;

            Solution() {
                arr = {2, 3, 1, 1};
                n = arr.size();
                k = 4;
                mem = vector<vector<int>>(n, vector<int>(k + 1, -1));            
            }//b2

            bool seqsum(int i , int target){//b3
                displayMem();
                if(target == 0) return 1;
                if(i == 0) return (arr[0] == target);
                if(mem[i][target] != -1) return mem[i][target];
                
                bool notake = seqsum(i - 1 , target);
                bool take = 0;
                
                if(target >= arr[i]) take = seqsum(i - 1 , target - arr[i]);
                
                return mem[i][target] = (take || notake);
            }//b3
           
            void displayMem() {

                cout << "\nMemoization Table:\n\n";

                for (int i = 0; i < n; i++) {

                for (int target = 0; target <= k; target++) {

                    if (mem[i][target] == -1)
                            cout << "- ";
                    else
                            cout << mem[i][target] << " ";
                    }

                    cout << endl;
                }

                cout << endl;
            }

            void play(){//b5
                cout << seqsum(n - 1 , k) << endl;
            }//b5
};//b1

int main(){//b6
        
        Solution sol = Solution();
        sol.play();
        sol.displayMem();
}//b6

