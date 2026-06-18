#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{//b1
        public:
            vector<int> prices;
            vector<int> prev;
            vector<int> curr;
            int fee;
            size_t n;
            //int profit1 , profit2;
            Solution(int f){//b2
                    prices = {7,1,1,1,9};
                    n = prices.size();
                    prev = curr = vector(2,0);
                    fee = f;
            }//b2

            int transc(){//b3
                prev[0] = prev[1] = 0;
            
                for(int i = n - 1 ; i >= 0 ; --i){//b4
                        curr = {0,0}; 
                        curr[1] = max( 
                                        -prices[i] + prev[0] , 
                                        0 + prev[1] 
                                    );
      
                        curr[0] = max(
                                        prices[i] + prev[1] - fee,
                                        0 + prev[0]
                                    );
                                
                        prev = curr;

                }//b4
                return prev[1];
            }//b3
};//b1



int main(){//b5
           
        Solution sol = Solution(2);
        cout << sol.transc() << endl;
}//b5




