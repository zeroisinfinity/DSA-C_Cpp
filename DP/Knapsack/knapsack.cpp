#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int profit[5] = {0,3,5,6,8};
const int weight[5] = {0,1,2,1,2};
const int constraint = 5;


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


void dominance(vector<pair<int,int>>& curr){
    // sort by weight ascending, profit descending
    sort(curr.begin(), curr.end(), [](auto &a, auto &b){
        if(a.second == b.second) return a.first > b.first; // higher profit first if weight same
        return a.second < b.second; // smaller weight first
    });

    vector<pair<int,int>> filtered;
    int max_profit = -1;

    for(auto &s : curr){
        if(s.first > max_profit){ // only keep non-dominated
            filtered.push_back(s);
            max_profit = s.first;
        }
    }

    curr = filtered;
}

void fill(vector<pair<int,int>>& curr , vector<pair<int,int>>& prev , int ele , int indx){//b14
	
	
		curr = prev;
		int p , w;
		if(weight[ele] <= constraint ) curr.emplace_back(profit[ele] , weight[ele]);
		for(auto& trav : prev){//b4
				if(trav.first) p = trav.first + profit[ele] ;
				if(trav.second) w = trav.second + weight[ele] ;
				if(w <= constraint && trav.first && trav.second ) curr.emplace_back(p,w);
	
		}//b4
	

}//b14
 
void display(vector<vector<pair<int,int>>>& vec,int* soln , int lenght = 4 , int opt = 0){//b10
	if(!opt) {
	int i = 0;
	for(auto& sets : vec){//b9
		cout << "SETS[" << i << "] - " ;
		for(auto& v : sets){//b11
			cout << "{"<< v.first << "," << v.second << "}";
		}//b11
		cout << endl;
		++i;
	}//b9
	}
	else{
		for(int j = 0 ; j < lenght ; ++j){
			cout << soln[j];
		}
		cout << endl;
}//b10
}
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


void ans(vector<vector<pair<int,int>>>& soln , int* bit , int length , int size){//b17
	
}//b17

int main(){//b1

	int soln[4] = {0};

	vector<vector<pair<int,int>>> subsets;
	for(int trav = 0 ; trav < 5 ; ++trav){//b15
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
	ans(subsets,soln,4,subsets.size()-1);
	display(subsets,soln,4,1);
	return 0;
}//b1
