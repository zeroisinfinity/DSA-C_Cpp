#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{//b1
        public:
            vector<int> prices;
            size_t n;
            //int profit1 , profit2;
            Solution(){//b2
                    prices = {1,9,7,0,4};
                    n = prices.size();
                    //profit1 = profit2 = 0;
            }//b2

            int transc(int i , bool buy , int cap){//b3
                int profit;
                if(cap == 0) return 0;
                if(i == n) return 0;

                if(buy){ profit = max( 
                                        -prices[i] + transc(i + 1 , 0 , cap) , 
                                        0 + transc(i + 1 , 1 , cap) 
                                    );
                }

                else {    
                        profit = max(
                                        prices[i] + transc(i + 1 , 1 , cap - 1),
                                        0 + transc(i + 1 , 0 , cap)
                                    );
                }

                return profit;
            }//b3
};//b1



int main(){//b5
           
        Solution sol = Solution();
        cout << sol.transc(0,1,2) << endl;
}//b5


