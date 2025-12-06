#include <bits/stdc++.h>
using namespace std;

class Solution {//b1
  public:

   int rec(vector<int>& vec, vector<vector<long long>>& mem , int n , int rem){//b1

            int take = 0 , skip = 0;

            for(int k = 0 ; k < rem + 1 ; ++k) if(k % vec[0] == 0) mem[0][k] = 1;
            
            for(int i = 1 ; i < n ; ++i){
                    for(int T = 0 ; T < rem + 1 ; ++T){
                            skip = mem[i-1][T];
                            take = 0;
                            if(vec[i] <= T) take = mem[i][T - vec[i]];
                            mem[i][T] = take + skip;
                    }
            }

            return mem[n-1][rem];
   }//b2

   int count(vector<int>& coins, int N, int amount){//b3
            vector<vector<long long>> mem(N,vector<long long>(amount+1,0));
            return rec(coins , mem , N , amount);
    }//b3
};//b1

int main(){//b7
            Solution soln;
            vector<int> arr = {2,4,10};
            int amt = 10;
            cout << soln.count(arr,arr.size(),amt) << endl;
            return 0;
}//b7

