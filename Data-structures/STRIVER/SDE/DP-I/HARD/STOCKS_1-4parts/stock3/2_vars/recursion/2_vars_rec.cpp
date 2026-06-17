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

            int transc(int i , int cap){//b3
                int profit;
                if(cap == 4) return 0;
                if(i == n) return 0;

                if(cap%2==0){ profit = max( 
                                        -prices[i] + transc(i + 1 ,  cap + 1) , 
                                        0 + transc(i + 1 , cap) 
                                    );
                }

                else {    
                        profit = max(
                                        prices[i] + transc(i + 1 , cap + 1),
                                        0 + transc(i + 1 , cap)
                                    );
                }

                return profit;
            }//b3
};//b1



int main(){//b5
           
        Solution sol = Solution();
        cout << sol.transc(0,0) << endl;
}//b5



