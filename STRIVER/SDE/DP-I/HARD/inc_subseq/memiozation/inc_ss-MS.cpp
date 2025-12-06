#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rec(vector<int>& vec , vector<vector<int>>& mem , int n , int i , int j){//b1
        int best;

        if(j >= n ) return vec[i];
        
        
        if(mem[i][j]!=INT_MIN) best = mem[i][j];
        else best = mem[i][j] = rec(vec,mem,n,i,j+1);

        if(vec[i] < vec[j]) {
            best = mem[i][j] = max(best,vec[i] + rec(vec,mem,n,j,j+1));
        }
        cout << endl;
        display(n-1,n-1,mem);
        cout << endl;
        cout << " i - " << i << " j - " << j << " best - " << best << endl;
        return best;
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
        vector<vector<int>> mem(n,vector<int>(n,INT_MIN)); 
        int ans = INT_MIN;
        for(int i = 0 ; i < n ; ++i)
            ans = max(ans,rec(arr,mem,n,i,i+1));
        return ans;
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

