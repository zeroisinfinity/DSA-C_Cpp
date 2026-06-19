#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{//b1
        public:
            vector<int> prices;
            int maxprofit;
            int mini;
            size_t n;

            Solution(){//b2
                    prices = {7,1,5,6,4,0,9};
                    maxprofit = 0;
                    mini = prices[0];
                    n = prices.size();
            }//b2

            int profit(){//b3
                    for(int i = 1 ; i < n ; ++i){//b4
                            int cost = prices[i] - mini;
                            maxprofit = max(maxprofit , cost);
                            mini = min(mini , prices[i]);
                    }//b4

                    return maxprofit;
            }//b3
};//b1



int main(){//b5
           
        Solution sol = Solution();
        cout << sol.profit() << endl;
}//b5
