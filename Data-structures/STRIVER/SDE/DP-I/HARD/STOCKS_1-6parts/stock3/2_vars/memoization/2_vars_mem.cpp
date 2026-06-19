#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{//b1
        public:
            vector<int> prices;
            vector<vector<int>> mem;
            size_t n;
            //int profit1 , profit2;
            Solution(){//b2
                    prices = {1,9,7,8,0,4};
                    n = prices.size();
                    mem = vector(n , vector<int>(4,-1));
            }//b2

            int transc(int i , int cap){//b3
                int profit = 0;
                if(cap==4) return 0;
                if(i==n) return 0;
                if(mem[i][cap] != -1) return mem[i][cap];

                if(cap%2==0){ 
                        profit = max( 
                                        -prices[i] + transc(i + 1 , cap + 1) , 
                                        0 + transc(i + 1 , cap) 
                                    );
                }

                else {    
                        profit = max(
                                        prices[i] + transc(i + 1 , cap + 1),
                                        0 + transc(i + 1 , cap)
                                    );
                }

                return mem[i][cap] = profit;
            }//b3
};//b1



int main(){//b5
           
        Solution sol = Solution();
        cout << sol.transc(0,0) << endl;
}//b5




