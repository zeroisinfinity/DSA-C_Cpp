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
	int sum = 0;
	int loop = 0;
	int max = vec[0];
	for(auto it = vec.begin() ; it != vec.end() ; ++it){
		sum += *it;
		if(it!=vec.begin()){
			if(*(it - 1) < 0){
				loop = it - vec.begin();
			}
			else it += (it - 1);
		}
	} 
	display(vec);
	cout << loop << endl;
	return 0;
}
