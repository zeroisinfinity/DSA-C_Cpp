#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Solution{//b1
        public:
            vector<int> prev , curr;
            int row , col;
            int src_r , src_c;
            int dest_r , dest_c;
            bool left , right , up , down;

            Solution(pair<int,int> mat , pair<int,int> source , pair<int,int> dest , vector<bool> moves){//b2
                    row = mat.first;
                    col = mat.second;
                    prev = curr = vector(col + 1 , 0);
                    src_r = source.first;
                    src_c = source.second;
                    dest_r = dest.first;
                    dest_c = dest.second;
                    left = moves[0];
                    right = !left;
                    up = moves[2];
                    down = !up;
            }//b2

            int move(){//b3

                    right = down = 1;


                    for(int i = row - 1; i >= 0 ; --i){//b7 

                        if(i == dest_r) curr[dest_c] = 1;
                        else curr = vector(col+1,0);

                        for(int j = col - 1 ; j >= 0 ; --j){//b8

                                int r=0 , d=0;
                                if(i == dest_r && j == dest_c) continue; 

                                if(right) r = curr[j + 1];
                                if(down) d = prev[j];

                                curr[j] = r + d;
                        }//b8
                        prev = curr;
                    }//b7

                    return prev[0];

            }//b3
};//b1


int main(){//b5
    pair<int,int> mat = {3,3}, source = {0,0}, dest = {2,2}; 
    vector<bool> moves = {0,1,0,1};
    Solution sol = Solution(mat /* MATRIX */ , source /* SOURCE */ , dest /* DEST */ , moves /* MOVES */);
    cout << sol.move() << endl;
    return 0;
}//b5



