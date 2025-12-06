#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int rodCutting(vector<int> price, int n) {

                vector<int> prev(n+1,0) , curr(n+1,0);
        

                for(int rodlen = 0 ; rodlen <= n ; ++rodlen)
                        prev[rodlen] = rodlen * price[0];

                for(int indx = 1 ; indx < n ; ++indx){//b10
                    for(int rodlen = 0 ; rodlen <= n ; ++rodlen){//b11
                            int skip = prev[rodlen];
                            int take = INT_MIN;
                            int rodlen_atindx = indx + 1;
                            if(rodlen_atindx <= rodlen) take = price[indx] + curr[rodlen-rodlen_atindx];
                            curr[rodlen] = max(take,skip);
                    }//b11
                    prev = curr;
                }//b10
                return prev[n];
    }
};

int main(){//b2
    Solution soln;
    vector<int> arr = {1, 6, 8, 9, 10, 19, 7, 20};
    int len = 8;
    cout << soln.rodCutting(arr,len) << endl;
    return 0; 
}//b2



