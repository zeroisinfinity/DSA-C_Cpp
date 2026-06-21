#include <iostream>
#include <vector>

using namespace std;

class Solution{//b1

        public:
            vector<vector<int>> calender;
            vector<int> curr , prev;
            size_t len;
            size_t acts;

            Solution(vector<vector<int>> c){//b2
                    calender = c;
                    len = c.size();
                    acts = c[0].size();
                    curr = prev = vector<int>(acts + 1 ,0);
            }//b2

            int train(){//b3

                        for(int choice = 0 ; choice < (acts + 1); ++choice){//b9
                            int maxy = 0;
                            for(int i = 0 ; i < acts ; ++ i){//b10 
                                if(i != choice) maxy = max(maxy , calender[0][i]);
                            }//b10
                            prev[choice] = maxy;
                        }//b9 

                        for(int indx = 1 ; indx < len ; ++indx){//b11
                            for(int choice = 0 ; choice < (acts + 1); ++choice){//b5
                                int maxy = 0;
                                for(int i = 0 ; i < acts ; ++i){//b12
                                    int merit = 0;
                                    if(i != choice){//b6
                                              if(choice == 3) merit = curr[i];
                                              else merit = calender[indx][choice] + prev[i];
                                    }//b6
                                    maxy = max(maxy,merit);
                                }//b12
                                curr[choice] = maxy;
                            }//b5
                            prev = curr;
                        }//b11

                        return prev[acts];

            }//b3
};//b1

int main(){//b7
        vector<vector<int>> calen = {{5,7,1},
                                     {8,2,9},
                                     {5,7,2},
                                     {4,8,9}
                                    };
        Solution soln = Solution(calen);
        cout << soln.train() << endl;
        return 0;
}//b7



