#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int profit[13] = {0, 95, 88, 81, 70, 65, 63, 56, 45, 41, 35, 25, 15};
const int weight[13] = {0, 23, 21, 20, 17, 16, 15, 14, 11, 10,  8,  6,  4};
const int constraint = 50;
const int pwsize = 13;
// Optimal set: Obj2 + Obj4 + Obj5 + Obj8 → weight = 4+3+2+5 = 14
// Profit = 40 + 50 + 35 + 30 = 155

// Optimal set: Obj2 + Obj3 → Profit = 22

// Optimal set: Obj1 + Obj4 → Profit = 50

// Optimal set: Obj2 + Obj4 → Profit = 42



bool cmp(pair<int,int>& curr , pair<int,int>& next){//b12
	return curr.first < next.first;
}//b12

/*
void dominance(vector<pair<int,int>>& curr){//b3
	
	sort(curr.begin() , curr.end() , cmp);

	for(auto it = curr.begin() ; it != curr.end() ; ++it){//b4
		if(it != curr.begin()){//b5	
			int prev_p = (it - 1) -> first;
			int prev_w = (it - 1) -> second;

			if( prev_p >= it -> first && prev_w <= it -> second ) it = curr.erase(it);
			
		}//b5
		
	}//b4

}//b
*/


void dominance(vector<pair<int,int>>& curr){//b25
    // sort by weight ascending, profit descending
    sort(curr.begin(), curr.end(), [](auto &a, auto &b){//b28
        if(a.second == b.second) return a.first > b.first; // higher profit first if weight same
        return a.second < b.second; // smaller weight first
    }/*b28*/);

    vector<pair<int,int>> filtered;
    int max_profit = -1;

    for(auto &s : curr){//b26
        if(s.first > max_profit){ //b27 
            filtered.push_back(s);
            max_profit = s.first;
        }//b27
    }//b26

    curr = filtered;
}//b25

void fill(vector<pair<int,int>>& curr , vector<pair<int,int>>& prev , int ele , int indx){//b14
	
	
		curr = prev;
		int p , w;
		if(weight[ele] <= constraint ) curr.emplace_back(profit[ele] , weight[ele]);
		for(auto& trav : prev){//b4
				p = trav.first + profit[ele] ;
				w = trav.second + weight[ele] ;
				if(w <= constraint) curr.emplace_back(p,w);
	
		}//b4
	

}//b14
void display(vector<vector<pair<int,int>>>& vec,int* bit , int length = 4 , int opt = 0){//b10
	if(!opt) {//b22
	int i = 0;
	for(auto& sets : vec){//b9
		cout << "SETS[" << i << "] - " ;
		for(auto& v : sets){//b11
			cout << "{"<< v.first << "," << v.second << "}";
		}//b11
		cout << endl;
		++i;
	}//b9
	}//b22
	else{//b23
	        cout << "SOLUTION - [  " ;
		for(int j = 0 ; j < length - 1; ++j){//b24
			if(bit[j]) cout << "{" << profit[j+1]<<","<< weight[j+1]<<"}  ";
		}//b24
		cout << "]"<<endl;
       }//b23
}//b10
/*
void ans(vector<vector<pair<int,int>>>& soln , int* bit , int length){//b17
	int i = length-1;
	for(auto trav = soln.rbegin() ; trav!=soln.rend() - 1 ; ++trav){//b18
		pair<int , int> target =  {trav -> rbegin() -> first , trav -> rbegin() -> second};
		pair<int , int> arg = make_pair((trav+1) -> rbegin() -> first , (trav+1) -> rbegin() -> second);
		if(arg == target) bit[i] = 0;
		else bit[i] = 1;
	}//b18
}//b17
*/


void ans(vector<vector<pair<int,int>>>& soln , int* bit , int length , int i){//b17
	pair <int,int> target = {soln[length].rbegin()->first, soln[length].rbegin()->second};
	bool exists = false;
	int j = i - 1;
	for(int trav = length ; trav >= 1 ; --trav){//b18
                for(auto& pr : soln[trav-1]){//b19
                        if(pr==target){//b20
                            exists = true;
                            break;
                        }//b20
                }//b19
              
              if(exists) bit[j] = 0;
              else{//b21
                  bit[j] = 1;
                  i = trav;
                  int f = target.first - profit[i];
                  int s = target.second - weight[i];
                  if(f < 0 || s < 0) target = {0,0};
                  else target = {f,s};
                  
              }//b21
              --j;
              exists = false;
        }//b18
}//b17

int main(){//b1

	int soln[pwsize-1] = {0};

	vector<vector<pair<int,int>>> subsets;
	for(int trav = 0 ; trav < pwsize ; ++trav){//b15
		vector<pair<int,int>> curr;
		if(!trav) curr.emplace_back(profit[trav],weight[trav]);
		else fill(curr , subsets[trav-1], trav , subsets[trav-1].size()-1);
		subsets.push_back(curr);
		//display(subsets);
	}//b15
	//display(subsets);
	for(auto& iter : subsets){//b16
		dominance(iter);
	}//b16
	
	display(subsets,soln);
	ans(subsets,soln,subsets.size()-1,pwsize-1);
	display(subsets,soln,pwsize,1);
	return 0;
}//b1
