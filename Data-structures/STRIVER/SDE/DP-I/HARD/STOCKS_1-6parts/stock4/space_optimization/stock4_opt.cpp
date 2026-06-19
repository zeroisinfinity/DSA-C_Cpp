#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{//b1
        public:
            vector<int> prices;
            vector<vector<int>> prev;
            vector<vector<int>> curr;
            int k;
            size_t n;
            //int profit1 , profit2;
            Solution(int trns){//b2
                    prices = {0,1,0,1,0,1,0,1};
                    n = prices.size();
                    k = trns;
                    prev = curr = vector(2,vector<int>(trns+1,0));
            }//b2

            int transc(){//b3
                for(int i = n - 1 ; i >= 0 ; --i){//b4 
                        curr = vector(2,vector<int>(k+1,0));
                        for(int c =  1 ; c < k+1 ; ++c){
                            curr[1][c] = max( 
                                        -prices[i] + prev[0][c] , 
                                        0 + prev[1][c] 
                                    );
      
                            curr[0][c] = max(
                                        prices[i] + prev[1][c-1],
                                        0 + prev[0][c]
                                    );
                        }
                        prev = curr;

                }//b4
                return prev[1][k];
            }//b3
};//b1



int main(){//b5
           
        Solution sol = Solution(4);
        cout << sol.transc() << endl;
}//b5






