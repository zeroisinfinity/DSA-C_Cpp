#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution{//b1 
        public:
            vector<int> vec;
            int len;
            vector<vector<int>> tab;

            Solution(vector<int> arr){//b2
                    vec = arr;
                    len = arr.size();
                    tab = vector(len , vector<int>(len,0));
            }//b2

            int part(int i , int j){//b3
                    for(int i = len - 2 ; i >= 1 ; --i){//b8
                            for(int j = i + 1 ; j < len ; ++j){//b9
                                    int mini = INT_MAX;
                                    int cost = 0;
                                    for(int k = i ; k < j ; ++k){//b4
                                        cost = tab[i][k] + tab[k+1][j] + (vec[i-1] * vec[k] * vec[j]) ;
                                        mini = min(mini,cost);
                                    }//b4
                                    tab[i][j] = mini;
                            }//b9
                    }//b8

                    return tab[1][len-1];
            }//b3
};//b1


int main(){//b5
        vector<int> arr = {40,      20,     30,     10,     30};
        Solution sol = Solution(arr);
        cout << sol.part(1,sol.len - 1) << endl;
        return 0;
}//b5


