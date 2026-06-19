#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Solution{//b1
        public:
            vector<vector<int>> mem;
            int row , col;
            int src_r , src_c;
            int dest_r , dest_c;
            bool left , right , up , down;

            Solution(pair<int,int> mat , pair<int,int> source , pair<int,int> dest , vector<bool> moves){//b2
                    row = mat.first;
                    col = mat.second;
                    mem = vector(row , vector<int>(col , -1));
                    src_r = source.first;
                    src_c = source.second;
                    dest_r = dest.first;
                    dest_c = dest.second;
                    left = moves[0];
                    right = !left;
                    up = moves[2];
                    down = !up;
            }//b2

            int move(int i , int j ){//b3
                    if(i == dest_r && j == dest_c) return 1;
                    if(i >= row || i < 0 || j >= col || j < 0) return 0;
                    if(mem[i][j] != -1) return mem[i][j];

                    int l , r , u , d;
                    l = r = u = d = 0;

                    if(left) l = move(i , j - 1);
                    if(right) r = move(i , j + 1);
                    if(up) u = move(i - 1 , j);
                    if(down) d = move(i + 1 , j);

                    return mem[i][j] = l + r + u + d;
            }//b3
};//b1


int main(){//b5
    pair<int,int> mat = {4,4}, source = {0,0}, dest = {3,3}; 
    vector<bool> moves = {0,1,0,1};
    Solution sol = Solution(mat /* MATRIX */ , source /* SOURCE */ , dest /* DEST */ , moves /* MOVES */);
    cout << sol.move(0,0) << endl;
    return 0;
}//b5

