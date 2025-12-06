#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rec(vector<int>& vec , int n ){//b1
        
        int ans = INT_MIN;
        vector<int> dp(n);

        for(int k = 0 ; k < n ; ++k){
            dp[k] = vec[k];
            for(int l = 0 ; l < k ; ++l){
                if(vec[k] > vec[l]) dp[k] = max(dp[k] , dp[l] + vec[k]);
            }
            ans = max(ans,dp[k]);
        }

                
        return ans;
        //return mem[i][j+1] < mem[j][j+1] ? mem[j][j+1] : mem[i][j+1];
    }//b1
    
    void display(int n , int m , vector<vector<int>>& mem){//b27
        for(int i = 0 ; i <= n ; ++i){//b25
                cout << endl;
                for(int j = 0 ; j <= m ; ++j){//b26
                        if(mem[i][j]!=INT_MIN) cout << "   " << mem[i][j] << "   ";
                        else  cout << "   " << 0 << "   ";
                }//b26
            }//b25
     }//b27

    int maxSumIncreasingSubsequence(vector<int>& arr, int n){//b2
        // Your code goes here
        //vector<vector<int>> mem(n,vector<int>(n,INT_MIN)); 
        return rec(arr,n);
   
    }//b2
};

int main(){//b4
        Solution soln;
        vector<int> arr = {4,1,2,3};
        cout << soln.maxSumIncreasingSubsequence(arr,arr.size());
        return 0;
}//b4
//
/*
 i - 0 j - 1 vec[i] - 4 vec[j] - 1
 i - 1 j - 2 vec[i] - 1 vec[j] - 2
 i - 1 j - 3 vec[i] - 1 vec[j] - 3
 i - 1 j - 4
 i - 0 j - 2 vec[i] - 4 vec[j] - 2
 i - 1 j - 2 vec[i] - 1 vec[j] - 2
 i - 1 j - 3 vec[i] - 1 vec[j] - 3
 i - 1 j - 4
 i - 0 j - 3 vec[i] - 4 vec[j] - 3
 i - 1 j - 2 vec[i] - 1 vec[j] - 2
 i - 1 j - 3 vec[i] - 1 vec[j] - 3
 i - 1 j - 4
 i - 0 j - 4
6
*/


