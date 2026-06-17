#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{//b1
        public:
            vector<int> prices;
            vector<vector<int>> prev;
            vector<vector<int>> curr;
            size_t n;
            //int profit1 , profit2;
            Solution(){//b2
                    prices = {1,9,7,8,0,4};
                    n = prices.size();
                    prev = curr = vector(2,vector<int>(3,0));
            }//b2

            int transc(){//b3
                for(int i = n - 1 ; i >= 0 ; --i){//b4 
                        curr = vector(2,vector<int>(3,0));
                        for(int c =  1 ; c < 3 ; ++c){
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
                return max(prev[1][0],max(prev[1][1],prev[1][2]));
            }//b3
};//b1



int main(){//b5
           
        Solution sol = Solution();
        cout << sol.transc() << endl;
}//b5





