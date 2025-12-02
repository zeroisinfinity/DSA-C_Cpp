#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;


class Graph_prims {//b1

    public:
        //static const int length = 10;
        static const int vertices = 8;
        const int INF = INT_MAX / 4;
        int mincost;
        int relax[vertices];
        bool sel[vertices];
        Graph_prims() {//b23 
            fill(sel, sel + vertices, false);
            fill(relax , relax + vertices , INF);
        }//b23
        

};//b1
class Edges : public Graph_prims {//b2

    public:
        int curr;
        vector<char> route[vertices];
        int cost[vertices][vertices] = {
                                {    0,         10,     4,      INF,    INF,    INF,    INF ,   INF },
                                {    10,        0,      INF,    5,      16,     INF,    INF,    INF },
                                {    4,         INF,    0,      11,     INF,    INF,    INF,    12 },
                                {    INF,       5,      11,     0,      6,      4,      INF,    INF },
                                {    INF,       16,     INF,    6,      0,      1,      INF,    13 },
                                {    INF,       INF,    INF,    INF,    1,      0,      11,     INF},
                                {    INF,       INF,    INF,    INF,    INF,    11,     0,      16},
                                {    INF,       INF,    12,     12,     13,     18,     16,     0 }
                                                                                                    };
    
        void enter_data(int u){//b11
                for(int i = 0 ; i < vertices ; ++i){//b12
                        relax[i] = cost[u][i];
                }//b12  
                sel[u] = true; 
        }//b11
        
        int relaxation(){//b26
                int u = nextmin();
                for(int i = 0 ; i < vertices ; ++i){//b36
                        if(relax[u] + cost[u][i] < relax[i]) relax[i] = relax[u] + cost[u][i];
                }//b36
                return u;
        }//b26

        int nextmin(){//b15
                int minn = INT_MAX;
                int ans;
                for(int l = 0 ; l < vertices ; ++l){//b16
                        if(!sel[l] && relax[l] < minn){//20
                            minn = relax[l];
                            ans = l;
                        }//b20
                }//b16
                //cout << "Min cost for " << ans << " is " << minn << endl;
                sel[ans] = true;

                for(int i = 0 ; i < vertices ; ++i) cout << "    [ " << relax[i] << " ]    " ;

                cout << "\n\n\n";

                for(int i = 0 ; i < vertices ; ++i) cout << "    [ " << sel[i]   << " ]    " ;

                cout << "\n\n\n";
                return ans;
        }//b15
        
        
};//b2


int main(){

    Edges e;
    e.curr = 4 ; int k = 0 , u;
    e.enter_data(e.curr);
    while (k < e.vertices - 1){//b13
                u = e.relaxation();
                k++;
                cout << " u is now " << u << endl;
    }//b13
    return 0;
    
}


