#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{//b1
        public:
            vector<int> prices;
            vector<vector<int>> tab;
            size_t n;
            //int profit1 , profit2;
            Solution(){//b2
                    prices = {1,9,7,8,0,4};
                    n = prices.size();
                    tab = vector(n + 1 , vector<int>(5,0));
            }//b2

            int transc(){//b3
                for(int i = n - 1 ; i >= 0 ; --i){//b4
                        for(int c = 3 ; c >= 0 ; --c){//b5
                                if(c%2==0){
                                    tab[i][c] = max( 
                                        -prices[i] + tab[i + 1][c+1] , 
                                        0 + tab[i + 1][c] 
                                    );
                                }
            
                                else{
                                    tab[i][c] = max(
                                        prices[i] + tab[i + 1][c+1],
                                        0 + tab[i + 1][c]
                                    );
                                }
                        }//b5
                    
                }//b4
                return tab[0][0];
            }//b3
};//b1



int main(){//b5
           
        Solution sol = Solution();
        cout << sol.transc() << endl;
}//b5





