#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

class Solution{//b1
        public:
            int row , col;
            int src_r , src_c;
            int dest_r , dest_c;
            bool left , right , up , down;
            double pos_inf = INFINITY;
            vector<vector<int>> maze;
            vector<double> curr , prev;

            Solution(vector<vector<int>> mat , pair<int,int> source , pair<int,int> dest , vector<bool> moves){//b2
                    maze = mat;
                    row = mat.size();
                    col = mat[0].size();
                    src_r = source.first;
                    src_c = source.second;
                    dest_r = dest.first;
                    dest_c = dest.second;
                    prev = vector(col + 1 , pos_inf);
                    left = moves[0];
                    right = !left;
                    up = moves[2];
                    down = !up;
            }//b2

            double move(int i , int j ){//b3
                    //if(i == dest_r && j == dest_c) return 1;
                    for(int i = row - 1 ; i >= 0 ; --i){//b8
                            curr = vector(col + 1 , pos_inf);
                            if(i == dest_r) curr[dest_c] = maze[dest_r][dest_c];
                            for(int j = col - 1 ; j >= 0 ; --j){//b9
                                if(i == dest_r && j == dest_c){//b10
                                        curr[j] = maze[dest_r][dest_c];
                                        continue;
                                }//b10
                                curr[j] = min(maze[i][j] + curr[j+1] , maze[i][j] + prev[j]);
                            }//b9
                            prev = curr;
                    }//b8
                    return prev[0];
            }//b3
};//b1


int main(){//b5
    vector<vector<int>> mat = {
                        {5,     1,      5,      10},

                        {3,     1,      12,     2},

                        {4,     2,      3,      3},

                        {2,     9,      8,      5}
    };

    pair<int,int> source = {0,0}, dest = {3,3}; 
    vector<bool> moves = {0,1,0,1};
    Solution sol = Solution(mat /* MATRIX */ , source /* SOURCE */ , dest /* DEST */ , moves /* MOVES */);
    cout << sol.move(0,0) << endl;
    return 0;
}//b5





