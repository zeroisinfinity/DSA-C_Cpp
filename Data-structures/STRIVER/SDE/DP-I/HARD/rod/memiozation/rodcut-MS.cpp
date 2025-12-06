#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int rec(int indx , int len , vector<int>& price , vector<vector<int>>& mem){//b1
                if(indx == 0) return len * price[0];
                if(mem[indx][len] != -1) return mem[indx][len];
                int skip = rec(indx - 1 , len , price, mem);
                int take = INT_MIN;
                int rodlen = indx + 1;
                if(rodlen <= len) take = price[indx] + rec(indx , len - rodlen , price, mem);
                return mem[indx][len] = max(take , skip);
                
    }//b1
    int rodCutting(vector<int> price, int n) {
                vector<vector<int>> mem(n,vector<int>(n+1,-1));
                return rec(n-1, n, price , mem);
    }
};

int main(){//b2
    Solution soln;
    vector<int> arr = {1, 6, 8, 9, 10, 19, 7, 20};
    int len = 8;
    cout << soln.rodCutting(arr,len) << endl;
    return 0; 
}//b2


