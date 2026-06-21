#include <iostream>
#include <vector>

using namespace std;

class Solution{//b1

        public:
            vector<vector<int>> calender;
            vector<vector<int>> mem;
            size_t len;
            size_t acts;

            Solution(vector<vector<int>> c){//b2
                    calender = c;
                    len = c.size();
                    acts = c[0].size();
                    mem = vector(len , vector<int>(acts + 1,-1));
            }//b2

            int train(int indx , int choice){//b3
                        if(indx == 0){//b4
                                int maxy = 0;
                                for(int i = 0 ; i < acts ; ++i)
                                    if(i != choice) maxy = max(maxy , calender[indx][i]);
                                
                                return maxy;
                        }//b4
                        
                        if(mem[indx][choice] != -1) return mem[indx][choice];

                        int maxy = 0;
                        for(int i = 0 ; i < acts ; ++i){//b5
                                if(i != choice){//b6
                                              int merit = calender[indx][i] + train(indx - 1 , i);
                                              maxy = max(merit,maxy);
                                }//b6
                        }//b5

                        return mem[indx][choice] = maxy;

            }//b3
};//b1

int main(){//b7
        vector<vector<int>> calen = {{5,7,1},
                                     {8,2,9},
                                     {5,7,2},
                                     {4,8,9}
                                    };
        Solution soln = Solution(calen);
        cout << soln.train(soln.len - 1 ,  soln.acts) << endl;
        return 0;
}//b7

