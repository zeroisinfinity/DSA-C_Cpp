#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rec(vector<int>& vec , int n , int i , int j){//b1
        int best;      
        if(j >= n ) {
            return vec[i];
        }
        best = rec(vec,n,i,j+1);
        if(vec[i] < vec[j]) {
            best = max(best,vec[i] + rec(vec,n,j,j+1));
            return best;
        }
        return best;
    }//b1
    
    int maxSumIncreasingSubsequence(vector<int>& arr, int n){//b2
        // Your code goes here
        int ans = INT_MIN;
        for(int i = 0 ; i < n ; ++i)
            ans = max(ans,rec(arr,n,i,i+1));
        return ans;
    }//b2
};

int main(){//b4
        Solution soln;
        vector<int> arr = {15,19,11,12,16,19,20};
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
