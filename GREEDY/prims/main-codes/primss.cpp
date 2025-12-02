
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;


class Graph_prims {//b1

    public:
        static const int length = 10;
        static const int vertices = 7;
        int mincost;
        int near[vertices];
        bool sel[vertices];
        Graph_prims() {//b23 
            fill(sel, sel + vertices, false);
            fill(near, near + vertices, -1);  
        }//b23
        

};//b1
class Edges : public Graph_prims {//b2

    public:
        int cost[vertices][vertices] = {
                                {  0,  1, 20, -1, -1, -1, -1 },
                                {  1,  0, -1, 25, 16, -1, -1 },
                                { 20, -1,  0, 36, -1, -1, 35 },
                                { -1, 25, 36,  0, 17,  4, -1 },
                                { -1, 16, -1, 17,  0, 19, -1 },
                                { -1, -1, -1,  4, 19,  0, 18 },
                                { -1, -1, 35, -1, -1, 18,  0 }
                                                                };

        void enter_data(){//b11
                for(int i = 0 ; i < vertices ; ++i){//b12
                    for(int j = 0 ; j < vertices ; ++j){//b13
                        cout << "ENTER - cost[ " << i << " ] :- ";
                        cin  >>  cost[i][j];
                    }//b13
                }//b12  
        }//b11
        
        void update_near(int u , int v , int step){//b26
                if(!step){//b28
                        for(int i = 0 ; i < vertices ; ++i){//b27 
                                near[i] = u;
                        }//b27
                        sel[0] = true;
                        return;
                }//b28
                else{//b29     
                        for(int i = 0 ; i < vertices ; ++i){//b27 
                                if((cost[u][i] > 0 && cost[u][i] < cost[v][i]) || cost[v][i] < 0){//b30
                                    if((cost[near[i]][i] < 0 || cost[near[i]][i] > cost[u][i]) && !sel[i] && cost[u][i] > 0) near[i] = u;
                                }//b30
                                else{//b31
                                    if((cost[near[i]][i] < 0 || cost[near[i]][i] > cost[v][i]) && !sel[i] && cost[v][i] > 0) near[i] = v;
                                }//b31
                        }//b27
                        return;
                }//b29
        }//b26

        void nextmin(int& u , int& v){//b15
                int minn = INT_MAX;
                int ans = -1;
                for(int l = 0 ; l < vertices ; ++l){//b16
                        if(!sel[l] && cost[near[l]][l] < minn && cost[near[l]][l] > 0){//20
                            minn = cost[near[l]][l];
                            ans = l;
                        }//b20
                }//b16
                u = near[ans];
                v = ans;
                sel[u] = sel[v] = true;
        }//b15
};//b2


int main(){

    Edges e;
    int u = 0 , v;

    for(int k = 0 ; k < e.vertices - 1 ; ++k){//b13
        
                if(!k) e.update_near(u,v,0);
                else e.update_near(u,v,1);

                e.nextmin(u,v);
                cout << " u - " << u << " , v - " << v << endl;
    }//b13
    return 0;
}



