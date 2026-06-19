#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{//b1
        public:
            vector<int> prices;
            vector<int> prev2 , prev1 , curr;
            int cd;
            size_t n;
            //int profit1 , profit2;
            Solution(){//b2
                    prices = {0,11,3,10,11};
                    n = prices.size();
                    cd = 1;
                    prev2 = prev1 = curr = vector<int>(2,0);
            }//b2

            int transc(){//b3
                int profit;
                for(int i = n - 1 ; i >= 0 ; --i){
                        curr[1] = max( 
                                        -prices[i] + prev1[0] , 
                                        0 + prev1[1]
                                    );
                    

                  
                        curr[0] = max(
                                        prices[i] + prev2[1],
                                        0 + prev1[0]
                                    );
                        prev2 = prev1;
                        prev1 = curr;
                }
                return prev1[1];
            }//b3
};//b1



int main(){//b5
           
        Solution sol = Solution();
        cout << sol.transc() << endl;
}//b5




