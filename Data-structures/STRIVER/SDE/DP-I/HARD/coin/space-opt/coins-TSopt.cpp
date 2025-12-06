#include <bits/stdc++.h>
using namespace std;

class Solution {//b1
  public:

   int count(vector<int>& coins, int N, int amount){//b3
            vector<long long> curr(amount+1,0) , prev(amount+1,0);
            int take , skip; 
            for(int k = 0 ; k < amount + 1 ; ++k) if(k % coins[0] == 0) prev[k] = 1;
            
            for(int i = 1 ; i < N ; ++i){//b5 
                    vector<long long> curr(amount+1,0);
                    for(int T = 0 ; T < amount + 1 ; ++T){//b6
                            skip = prev[T];
                            take = 0;
                            if(coins[i] <= T) take = curr[T - coins[i]];
                            curr[T] = take + skip;
                    }//b6
                    prev = curr;
            }//b5
            
            return prev[amount];
    }//b3
};//b1

int main(){//b7
            Solution soln;
            vector<int> arr = {2,4,10};
            int amt = 10;
            cout << soln.count(arr,arr.size(),amt) << endl;
            return 0;
}//b7


