#include <iostream>
#include <vector>
#include <string>
#include <limits.h>

using namespace std;

class Solution{//b1
        public:
            string text;
            int len;

            Solution(string str){//b2
                    text = str;
                    len = str.length();
            }//b2

            int part(int i){//b3
                    if(i >= len) return -1;
            
                    int cost = 0 , mini = INT_MAX;
                    for(int j = i ; j < len ; ++j){//b4
                            if(isPalindrome(i,j)){//b11
                                    cost = part(j+1) + 1;
                                    mini = min(mini,cost);
                            }//b11
                    }//b4
                    return mini;
            }//b3

            bool isPalindrome(int i , int j){//b6
                    bool flag = false;
                    for(int k = 0 ; k <= (j-i)/2 ; ++k){//b7
                            if(text[k+i] == text[j-k]) flag = true;
                            else{//b10 
                                flag = false;
                                break;
                            }//b10
                    }//b7
                    return flag;
            }//b6
};//b1


int main(){//b12
           string palin = "bababcbadcede";
           Solution sol = Solution(palin);
           //cout << sol.isPalindrome(0,2) << endl;
           cout << sol.part(0) << endl;
           return 0;
}//b12
