#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution{//b1
        public:
            vector<int> vec;
            double maxy;
            size_t len;

            Solution(vector<int> arr){//b3
                vec = arr;
                len = arr.size();
            }//b3

            double burst(int i , int j){//b4
                    if(i > j) return 0;
                    double maxy = INT_MIN;
                    double cost = 0;
                    for(int indx = i ; indx <= j ; ++indx){//b5
                            cost = mul(i , indx , j) + burst(i,indx-1) + burst(indx+1,j);
                            maxy = max(maxy,cost);
                    }//b5
                    return maxy;
            }//b4

            double mul(int i , int indx , int j){//b6
                    if(i == 0 && len == j + 1) return vec[indx];
                    else if(i==0) return vec[indx] * vec[j+1];
                    else if(j == len - 1) return vec[i-1] * vec[indx];
                    else return vec[i - 1] * vec[indx] * vec[j + 1];
            }//b6
};//b1

int main(){//b2
        vector<int> arr = {3,1,5,8};
        Solution sol = Solution(arr);
        cout << sol.burst(0,arr.size() - 1) << endl;
        return 0;
}//b2
