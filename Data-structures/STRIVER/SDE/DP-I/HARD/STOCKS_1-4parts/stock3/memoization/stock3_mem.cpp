#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{//b1
        public:
            vector<int> prices;
            vector<vector<vector<int>>> mem;
            size_t n;
            //int profit1 , profit2;
            Solution(){//b2
                    prices = {1,9,7,8,0,4};
                    n = prices.size();
                    mem = vector(n , vector(2,vector<int>(3,-1)));
            }//b2

            int transc(int i , bool buy , int cap){//b3
                int profit = 0;
                if(cap==0) return 0;
                if(i==n) return 0;
                if(mem[i][buy][cap] != -1) return mem[i][buy][cap];

                if(buy){ 
                        profit = max( 
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

                return mem[i][buy][cap] = profit;
            }//b3
};//b1



int main(){//b5
           
        Solution sol = Solution();
        cout << sol.transc(0,1,2) << endl;
}//b5



