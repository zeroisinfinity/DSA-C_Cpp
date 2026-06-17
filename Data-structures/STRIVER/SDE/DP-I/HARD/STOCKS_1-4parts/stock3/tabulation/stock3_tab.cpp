#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{//b1
        public:
            vector<int> prices;
            vector<vector<vector<int>>> tab;
            size_t n;
            //int profit1 , profit2;
            Solution(){//b2
                    prices = {1,9,7,8,0,4};
                    n = prices.size();
                    tab = vector(n + 1 , vector(2 , vector<int>(3,0)));
            }//b2

            int transc(){//b3
                for(int i = n - 1 ; i >= 0 ; --i){//b4
                        for(int c = 1 ; c < 3 ; ++c){//b5
                                tab[i][1][c] = max( 
                                        -prices[i] + tab[i + 1][0][c] , 
                                        0 + tab[i + 1][1][c] 
                                    );
            
                                tab[i][0][c] = max(
                                        prices[i] + tab[i + 1][1][c-1],
                                        0 + tab[i + 1][0][c]
                                    );
                        }//b5
                    
                }//b4
                return max(tab[0][1][0] , max(tab[0][1][1] , tab[0][1][2]));
            }//b3
};//b1



int main(){//b5
           
        Solution sol = Solution();
        cout << sol.transc() << endl;
}//b5




