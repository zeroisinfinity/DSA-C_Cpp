#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;


class Graph_krushkal {//b1

    public:
        static const int length = 10;
        static const int vertices = 7;
        int mincost;
        int parent[vertices];
        bool sel[length];
        int rank_arr[vertices];
        Graph_krushkal() {//b23
            fill(parent, parent + vertices, -1);   
            fill(sel, sel + length, false);
fill(rank_arr, rank_arr + vertices, 0);
            
        }//b23
        

};//b1


class Dissubset : public Graph_krushkal {//b3
    
    public:

        int ans;

        int find(int v) {
            if (v < 0 || v >= vertices) return -1;
            int root = v;
            while (parent[root] != -1) root = parent[root];

            int cur = v;
            while (cur != root) {
            int next = parent[cur];
            parent[cur] = root;
            cur = next;
            }
        return root;
        }
        

void unite(int lhs, int rhs) {
    if (lhs < 0 || lhs >= vertices || rhs < 0 || rhs >= vertices) return;

    int rl = find(lhs);   // returns root and compresses the path
    int rr = find(rhs);
    if (rl == -1 || rr == -1) return;
    if (rl == rr) return; // already same set

    if (rank_arr[rl] < rank_arr[rr]) {
        parent[rl] = rr;
    } else if (rank_arr[rl] > rank_arr[rr]) {
        parent[rr] = rl;
    } else {
        parent[rr] = rl;
        rank_arr[rl] += 1;
    }
}
};
class Edges : public Dissubset {//b2
    public:
        int edges_arr[length][3] = {   {0,1,1 },
                                       {0,2,20},
                                       {1,4,16},
                                       {1,3,25},
                                       {2,3,36},
                                       {2,6,35},
                                       {3,4,17},
                                       {3,5,4 },
                                       {4,5,19},
                                       {5,6,18}
                                    };
        void enter_data(){//b11
                for(int i = 0 ; i < length ; ++i){//b12
                    for(int j = 0 ; j < 3 ; ++j){//b13
                        cout << "ENTER - edges_arr[" << i << "] :- ";
                        cin  >>  edges_arr[i][j];
                    }//b13
                }//b12  
        }//b11
        int nextmin(){//b15
                int minn = INT_MAX;
                int ans = -1;
                for(int l = 0 ; l < 10 ; ++l){//b16
                        if(!sel[l] && edges_arr[l][2] < minn){//20
                            minn = edges_arr[l][2];
                            ans = l;
                        }//b20
                }//b16
                sel[ans] = true;
                return ans;
        }//b15
};//b2


int main(){

    Edges e;
    int here , u , v , k;
    while(k < 6){//b13
            here = e.nextmin();
            u = e.edges_arr[here][0];
            v = e.edges_arr[here][1];
            if(e.find(u) != e.find(v)){//b23
                e.unite(u,v);
                cout << " u - " << u << " , v - " << v << endl;
                k++;
            }//b23
    }//b13


    return 0;
}


