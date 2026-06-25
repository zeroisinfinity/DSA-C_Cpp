#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Solution{//b1
        public:
            int row , col;
            int src_r , src_c;
            int dest_r , dest_c;
            bool left , right , up , down;
            vector<vector<int>> maze;
            vector<vector<int>> tab;

            Solution(vector<vector<int>> mat , pair<int,int> source , pair<int,int> dest , vector<bool> moves){//b2
                    maze = mat;
                    row = mat.size();
                    col = mat[0].size();
                    tab = vector(row + 1, vector<int>(col + 1 , 0));
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
                    tab[dest_r][dest_c] = 1;

                    for(int i = row - 1 ; i >= 0 ; --i){//b7
                            for(int j = col - 1 ; j >= 0 ; --j){//b8
                                    int l , r , u , d;
                                    l = r = u = d = 0;
                                    if(i == dest_r && j == dest_c) continue;
                                    if(maze[i][j] == -1) continue;
                                    if(left) l = tab[i][j - 1];
                                    if(right) r = tab[i][j + 1];
                                    if(up) u = tab[i - 1][j];
                                    if(down) d = tab[i + 1][j];

                                    tab[i][j] = l + r + u + d;
                            }//b8
                    }//b7
                    return tab[0][0];
            }//b3
};//b1


int main(){//b5
    vector<vector<int>> mat = {
                        {0, 0, 0, 0},
                        {0,-1, 0, 0},
                        {0, 0,-1, 0},
                        {0, 0, 0, 0}
    };

    pair<int,int> source = {0,0}, dest = {3,3}; 
    vector<bool> moves = {0,1,0,1};
    Solution sol = Solution(mat /* MATRIX */ , source /* SOURCE */ , dest /* DEST */ , moves /* MOVES */);
    cout << sol.move() << endl;
    return 0;
}//b5



