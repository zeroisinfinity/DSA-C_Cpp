#include <bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        
        int rec(vector<int>& prev , vector<int>&curr , string start , string target){//b2
            
            int n = start.size() , m = target.size();
            //for(int k = 0 ; k < n ; ++k) memtable[0][k] = k;
            for(int l = 0 ; l <= m ; ++l) prev[l] = l;

            for(int i = 1 ; i <= n ; ++i){//b25
                    curr[0] = i;
                    for(int j = 1 ; j <= m ; ++j){//b26
                                if(start[i-1] == target[j-1]) curr[j] = prev[j-1];
                                else curr[j] = 1 + min( { curr[j-1] ,
                                                          prev[j]   ,
                                                          prev[j-1] });

                                /*cout << endl;
                                cout << " i - " << i << " j - " << j << endl;
                                display(n,m,memtable);
                                cout << endl;*/
                    }//b26
                    prev = curr;
            }//b25
            //cout << memtable[n][m];
        
            ;
            return curr[m];
        }//b2
        
        /*void display(int n , int m , vector<vector<int>>& mem){//b27
            for(int i = 0 ; i <= n ; ++i){//b25
                    cout << endl;
                    for(int j = 0 ; j <= m ; ++j){//b26
                                cout << " " << mem[i][j] << " ";
                    }//b26
            }//b25
        }//b27*/

        int editDistance(string start, string target) {//b10
            int n = start.size() , m = target.size() ;
            vector<int> prev(m+1,0) , curr(m+1,0);
            return rec(prev,curr,start , target);
        }//b10

};


int main(){//b1
    Solution soln;
    cout << soln.editDistance("saturday","sunday") << endl;
    return 0;
}//b1


