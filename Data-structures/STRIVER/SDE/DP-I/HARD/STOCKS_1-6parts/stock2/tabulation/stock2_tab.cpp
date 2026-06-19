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
                    prices = {7,1,1,1,9};
                    n = prices.size();
                    tab = vector(n + 1 , vector<int>(2,0));
            }//b2

            int transc(){//b2
                for(int i = n - 1 ; i >= 0 ; --i){
                            tab[i][1] = max( 
                                        -prices[i] + tab[i + 1][0] , 
                                        0 + tab[i + 1][1] 
                                    );
            
                            tab[i][0] = max(
                                        prices[i] + tab[i + 1][1],
                                        0 + tab[i + 1][0]
                                    );
                    
                

                }
                    return tab[0][1];
            }//b3
};//b1



int main(){//b5
           
        Solution sol = Solution();
        cout << sol.transc() << endl;
}//b5



