#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int rec(int indx , int len , vector<int>& price){//b1
                if(indx == 0) return len * price[0];
                int skip = rec(indx - 1 , len , price);
                int take = INT_MIN;
                int rodlen = indx + 1;
                if(rodlen <= len) take = price[indx] + rec(indx , len - rodlen , price);
                return max(take , skip);
                
    }//b1
    int rodCutting(vector<int> price, int n) {
                return rec(n-1,n,price);
    }
};

int main(){//b2
    Solution soln;
    vector<int> arr = {1, 6, 8, 9, 10, 19, 7, 20};
    int len = 8;
    cout << soln.rodCutting(arr,len) << endl;
    return 0; 
}//b2

