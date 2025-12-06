#include <bits/stdc++.h>
using namespace std;

class Solution {//b1
  public:

   int rec(vector<int>& vec, int n , int i , int rem){//b1
            int take = 0 , skip = 0;
            if(rem == 0){
                    //cout << "vec[i] -  " <<  vec[i] << "   vec[j - 1]  - " << vec[j - 1] << "   vec[j-2]  -  " << vec[j-2] << "   rem  -  "  << rem << "  best gain  -  " << 1 << endl; 
                    return 1;
            }
            if(i >= n || rem < 0) return 0; 
            if(vec[i] <= rem) take = rec(vec,n,i,rem-vec[i]);
            skip = rec(vec,n,i+1,rem);
            //cout << vec[i] << "  " << vec[j] << " rem  " << rem << " best  " << best << endl;
            //cout << rhs << " " << lhs << endl;
            return take + skip;
            //return best
   }//b2

   int count(vector<int>& coins, int N, int amount){//b3
            return rec(coins , N , 0, amount);
    }//b3
};//b1

int main(){//b7
            Solution soln;
            vector<int> arr = {2,4,10};
            int amt = 10;
            cout << soln.count(arr,arr.size(),amt) << endl;
            return 0;
}//b7
