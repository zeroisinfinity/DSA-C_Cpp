#include <iostream>
#include <climits>
#include <vector>

using namespace std;

void data(vector<int>& vec){
	char yn;
	int datum;
	while(true){
		cout << "Add? - " ;
		cin >> yn;
		if(yn != 'n'){
			cout << "Add datum - ";
			cin >> datum;
			vec.push_back(datum);
		}
		else break;
	}
}

void display(vector<int>& vec){
	for(auto it = vec.begin() ; it != vec.end() ; ++it){
		cout << "  " << *it << "  ";
	}
	cout << endl;
}

int main(){
        
    vector<int> vec;
    data(vec);
    display(vec);
    int sum = INT_MIN;
    int inst_sum = 0;
    int sub_start = -1 , sub_end = 0;
    int start , end;
    for(auto it = vec.begin() ; it < vec.end() - 1; ++it){//b1
            sub_start++;
            for(auto iter = it + 1; iter < vec.end() ; ++iter){//b2
                    sub_end++;
                    for(auto itertr = it ; itertr <= iter ; ++itertr){//b3
                            inst_sum += *itertr; 
                    }//b3
                    if(inst_sum > sum){//b4
                            sum = inst_sum;
                            start = sub_start;
                            end = sub_end;
                    }//b4
                    inst_sum = 0;
            }//b2
            sub_end = sub_start + 1;
    }//b1
    
    cout << "largest sum is = " << sum << " from index " << start << " to " << end - 1 << " . " << endl;

    return 0;
}
