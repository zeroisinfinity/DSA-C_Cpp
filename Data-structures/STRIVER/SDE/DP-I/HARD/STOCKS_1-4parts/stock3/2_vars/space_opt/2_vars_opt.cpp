#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{//b1
        public:
            vector<int> prices;
            vector<int> prev;
            vector<int> curr;
            size_t n;
            //int profit1 , profit2;
            Solution(){//b2
                    prices = {1,9,7,8,0,4};
                    n = prices.size();
                    prev = curr = vector(5,0);
            }//b2

            int transc(){//b3
                for(int i = n - 1 ; i >= 0 ; --i){//b4
                        curr = vector(5,0);
                        for(int c =  3 ; c >= 0 ; --c){
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
                return max(prev[0],prev[2]);
            }//b3
};//b1


int main(){//b5
           
        Solution sol = Solution();
        cout << sol.transc() << endl;
}//b5






