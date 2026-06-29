#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution{//b1
        public:
            vector<int> vec;
            double maxy;
            size_t len;
            vector<vector<double>> tab;

            Solution(vector<int> arr){//b3
                vec = arr;
                vec.insert(vec.begin() , 1);
                vec.push_back(1);
                len = vec.size();
                tab = vector(len , vector<double>(len ,0));
            }//b3


            double burst(){//b4

                    for(int i = len - 2 ; i >= 1 ; --i){//b9
                        for(int j = i ; j < len - 1 ; ++j){//b10
                            double maxy = INT_MIN;
                            double cost = 0;
                            for(int indx = i ; indx <= j ; ++indx){//b5
                                cost = mul(i , indx , j) + tab[i][indx-1] + tab[indx+1][j] ; 
                                maxy = max(maxy,cost);
                            }//b5
                            tab[i][j] = maxy;
                        }//b10
                    }//b9

                    return tab[1][len-2];
            }//b4

            double mul(int i , int indx , int j){//b6
                    return vec[i-1] * vec[indx] * vec[j+1];
            }//b6
};//b1

int main(){//b2
        vector<int> arr = {3,1,5,8};
        Solution sol = Solution(arr);
        cout << sol.burst() << endl;
        return 0;
}//b2


