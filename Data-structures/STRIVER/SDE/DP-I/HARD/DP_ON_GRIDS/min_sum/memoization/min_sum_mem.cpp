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
            vector<vector<int>> mem;

            Solution(vector<vector<int>> mat , pair<int,int> source , pair<int,int> dest , vector<bool> moves){//b2
                    maze = mat;
                    row = mat.size();
                    col = mat[0].size();
                    src_r = source.first;
                    src_c = source.second;
                    dest_r = dest.first;
                    dest_c = dest.second;
                    mem = vector(row , vector<int>(col , -1));
                    left = moves[0];
                    right = !left;
                    up = moves[2];
                    down = !up;
            }//b2

            double move(int i , int j ){//b3
                    //if(i == dest_r && j == dest_c) return 1;
                    if(i == dest_r && j == dest_c) return maze[dest_r][dest_c];
                    if(i >= row || j >= col) return INFINITY;
                    if(mem[i][j] != -1) return mem[i][j];
                    //if(maze[i][j] == -1) return 0;

                    //int l , r , u , d;
                    double cost = INFINITY;
                    /*if(left) l = move(i , j - 1);
                    if(right) r = move(i , j + 1);
                    if(up) u = move(i - 1 , j);
                    if(down) d = move(i + 1 , j);*/
                        
                    cost = min(maze[i][j] + move(i,j+1) , maze[i][j] + move(i+1,j));

                    return mem[i][j] = cost;
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



