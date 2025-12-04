#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        
        int rec(int i , int j , string start , string target , vector<vector<int>>& memtable){//b2
            if(i < 0) return 1+j;
            if(j < 0) return 1+i;
            if(memtable[i][j] != -1) return memtable[i][j];
            if(start[i] == target[j]) return memtable[i][j] = 0 + rec(i-1,j-1,start,target,memtable);
            else return memtable[i][j] = 1 + min( { rec(i,j-1,start,target,memtable) ,
                               rec(i-1,j,start,target,memtable) ,
                               rec(i-1,j-1,start,target,memtable)
                             } );
        }//b2

        int editDistance(string start, string target) {//b10
            int n = start.size() -1 , m = target.size() - 1;
            vector<vector<int>> mem(n+1,vector<int>(m+1,-1));
            return rec(n, m , start , target , mem);
        }//b10

};


int main(){//b1
    Solution soln;
    cout << soln.editDistance("saturday","sunday") << endl;
    return 0;
}//b1
:
