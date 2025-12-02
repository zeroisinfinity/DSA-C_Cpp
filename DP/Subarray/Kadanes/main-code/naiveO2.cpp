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
    //data(vec);
    vec = {12,-3,11,10,5,-9,1};
    display(vec);
    int sum = INT_MIN;
    int sub_start = -1 , sub_end;
    int start , end;
    int inst_sum = 0;
    for(auto it = vec.begin() ; it < vec.end() - 1; ++it){//b1
            sub_start++;
            sub_end = sub_start;
            for(auto iter = it + 1; iter <= vec.end() ; ++iter){//b2
                    sub_end++;
                    inst_sum += *(iter - 1); 
                    if(inst_sum > sum){//b4
                            sum = inst_sum;
                            start = sub_start;
                            end = sub_end;
                    }//b4
            }//b2
            inst_sum = 0;
    }//b1
    
    cout << "largest sum is = " << sum << " from index " << start << " to " << end - 1 << " . " << endl;

    return 0;
}
