#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{//b1
        public:
            vector<int> prices;
            vector<int> prev;
            vector<int> curr;
            int k;
            size_t n;
            //int profit1 , profit2;
            Solution(int trns){//b2
                    prices = {0,1,0,1,0,1,0,1};
                    n = prices.size();
                    k = trns * 2;
                    prev = curr = vector((trns*2) + 1,0);
            }//b2

            int transc(){//b3
                for(int i = n - 1 ; i >= 0 ; --i){//b4
                        curr = vector(k+1,0);
                        for(int c =  k - 1 ; c >= 0 ; --c){
                            if(c%2==0){
                                curr[c] = max( 
                                        -prices[i] + prev[c+1] , 
                                        0 + prev[c] 
                                    );
                            }
      
                            else{
                                curr[c] = max(
                                        prices[i] + prev[c+1],
                                        0 + prev[c]
                                    );
                            }
                        }
                        prev = curr;
                }//b4
                return prev[0];
            }//b3
};//b1


int main(){//b5
           
        Solution sol = Solution(4);
        cout << sol.transc() << endl;
}//b5







