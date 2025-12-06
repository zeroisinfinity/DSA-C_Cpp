#include <bits/stdc++.h>
using namespace std;

class Solution {//b1
  public:

   int rec(vector<int>& vec, vector<vector<long long>>& mem , int n , int i , int rem){//b1
            int take = 0 , skip = 0;
            if(i == 0) return (rem % vec[i] == 0);
            if(mem[i][rem] != -1) return mem[i][rem]; 
            if(vec[i] <= rem) take = rec(vec,mem,n,i,rem-vec[i]);
        
            skip = rec(vec,mem,n,i-1,rem);
            //cout << vec[i] << "  " << vec[j] << " rem  " << rem << " best  " << best << endl;
            //cout << rhs << " " << lhs << endl;
            return mem[i][rem] = take + skip;
            //return best
   }//b2

   int count(vector<int>& coins, int N, int amount){//b3
            vector<vector<long long>> mem(N,vector<long long>(amount+1,-1));
            return rec(coins , mem , N , N - 1, amount);
    }//b3
};//b1

int main(){//b7
            Solution soln;
            vector<int> arr = {2,1};
            int amt = 10;
            cout << soln.count(arr,arr.size(),amt) << endl;
            return 0;
}//b7

