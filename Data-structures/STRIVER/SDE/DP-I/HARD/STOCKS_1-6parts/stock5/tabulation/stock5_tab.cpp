#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{//b1
        public:
            vector<int> prices;
            vector<vector<int>> tab;
            int cd;
            size_t n;
            //int profit1 , profit2;
            Solution(int cooldown){//b2
                    prices = {0,11,3,10,11};
                    n = prices.size();
                    cd = cooldown;
                    tab = vector(n+cd+1,vector<int>(2,0));
            }//b2

            int transc(){//b3
                int profit;
                for(int i = n - 1 ; i >= 0 ; --i){
                        tab[i][1] = max( 
                                        -prices[i] + tab[i + 1][0] , 
                                        0 + tab[i + 1][1]
                                    );
                    

                  
                        tab[i][0] = max(
                                        prices[i] + tab[i + cd + 1][1],
                                        0 + tab[i + 1][0]
                                    );
                    
                }
                return tab[0][1];
            }//b3
};//b1



int main(){//b5
           
        Solution sol = Solution(1);
        cout << sol.transc() << endl;
}//b5




