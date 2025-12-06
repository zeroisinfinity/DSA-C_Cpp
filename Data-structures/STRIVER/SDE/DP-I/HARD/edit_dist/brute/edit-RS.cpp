#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int rec(int i , int j , string start , string target){//b2
        if(i < 0) return 1+j;
        if(j < 0) return 1+i;
        if(start[i] == target[j]) return rec(i-1,j-1,start,target);
        else return 1 + min( { rec(i,j-1,start,target) ,
                               rec(i-1,j,start,target) ,
                               rec(i-1,j-1,start,target)
                             } );

    }//b2
    int editDistance(string start, string target) {
        return rec(start.size() - 1 , target.size() - 1 , start , target);
    }
};


int main(){//b1
    Solution soln;
    cout << soln.editDistance("saturday","sunday") << endl;
    return 0;
}//b1
