#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{//b1
        public:
            vector<int> prices;
            int fee;
            size_t n;
            //int profit1 , profit2;
            Solution(int f){//b2
                    prices = {7,1,1,9,1,10};
                    n = prices.size();
                    fee = f;
            }//b2

            int transc(int i , bool buy){//b3
                int profit;
                if(i==n) return 0;

                if(buy){ profit = max( 
                                        -prices[i] + transc(i + 1 , 0) , 
                                        0 + transc(i + 1 , 1) 
                                    );
                }

                else {    
                        profit = max(
                                        prices[i] + transc(i + 1 , 1) - fee,
                                        0 + transc(i + 1 , 0)
                                    );
                }

                return profit;
            }//b3
};//b1



int main(){//b5
           
        Solution sol = Solution(2);
        cout << sol.transc(0,1) << endl;
}//b5

