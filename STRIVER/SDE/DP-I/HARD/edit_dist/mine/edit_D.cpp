#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

class Solution {//b2
  public:
    map<char,vector<int>> records;
    vector<pair<int,pair<int,char>>> dup;
    vector<int> matches;
    int ops_ins;
    int ops_rep;
    int ops_del;
    map<char,bool> found;

    void display_map(char ch){//b8
            cout << "FOR " << ch << " indices are ";
            for(auto it = records[ch].begin() ; it != records[ch].end() ; ++it){//b9
                    cout << *it;
            }//b9
            cout << endl;
    }//b8
    
    
    
int find_match(vector<int>& vec, int target) {
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] == target) {
            return i;
        }
    }
    return -1;
}

    void display_vec(vector<int>& vec){//b8
            cout << endl << "vec is - ";
            //int i = 0;
            for(auto it = vec.begin() ; it != vec.end() ; ++it){//b9
                    cout << " " << *it << " ";
                    //cout << "width is " << width(i);
                    //cout << endl;
                    //i++;
            }//b9
            cout << endl;
    }//b8
    
    
    
    void store(string start , string target){//b4
            cout << endl;
            int pos;
            for(char ch : target){//b5
                    pos = 0;
                    while((pos = start.find(ch,pos)) != string::npos){//b6
                                records[ch].push_back(pos);
                                matches.push_back(pos);
                                cout << endl;
                                cout << "FOUND " << ch << " at " << pos << endl;
                                pos++;
                    }//b6
                    if(start.find(ch,0)==string::npos){//b9
                        cout << "NOT FOUND " << ch << endl;
                        records[ch].push_back(-1);
                    }//b9
                    cout << endl;
                    display_map(ch);
            }//b5
            display_vec(matches);
    }//b4



    void sort_it(vector<int>& vec){//b10
            sort(vec.begin(),vec.end());
            display_vec(vec);
    }//b10
    
    void find_dup(string start){//b17
            int len;
            int indx;
            for(int i = 0 ; i < matches.size() ; ++i){//b18
                    char ch = start[matches[i]];
                    indx = 0;
                    len = records[ch].size();
                    while(indx < len && len > 1 && !found[ch]){//b19
                                    int m_indx = find_match(matches,records[ch][indx]);
                                    dup.push_back( {m_indx , {width(m_indx),ch}});
                                    cout << width(m_indx) << " " << ch << endl;
                                    indx++;
                            
                    }//b19
                    found[ch] = true;
            }//b18
    }//b17

    void sanitize(){//b25

            sort(dup.begin(),dup.end(),[](const auto& a , const auto& b){
                                                return a.second.first > b.second.first;
                                         }
                );
            int len , indx;
            auto a = dup.begin();
            char ch;
            while(a != dup.end()){//b26
                    ch = a.second.second;
                    len = records[ch].size();
                    indx = 0;
                    while(indx < len){//b27
                                  records[ch][find_match(matches,a.first)] = -1;
                    }//b27
            }//b26
            
    }//b25

    int width(int indx){//b11
            int rhs = 0;
            int lhs = 0;
            int trav = indx;
            while(matches[trav] - matches[trav - 1] == 1 && trav - 1 >= 0 ){//b12
                lhs++;
                trav--;
            }//b12

            trav = indx;

            while(matches[trav + 1] - matches[trav] == 1 && trav + 1 < matches.size()){//b12
                rhs++;
                trav++;
            }//b12
            
            return lhs+rhs;
    }//b11

    int ins();
    int rep();
    int del();
    int editDistance(string start, string target) {//b3
                int n = start.length() , m = target.length();
                if(n >= m){//b15
                    ops_del = n - m;
                    ops_rep = m;
                }//b15
                else{//b16
                    ops_ins = m - n;
                    ops_rep = n;
                }//b16
                
                store(start , target);
                sort_it(matches);
                find_dup(start);
                return -1;
    }//b3
};//b2

int main(){//b1
    Solution soln;
    soln.editDistance("saturday" , "sunday");
    return 0;

}//b1
