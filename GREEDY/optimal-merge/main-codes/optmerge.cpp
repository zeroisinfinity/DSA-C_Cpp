#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void display(vector<int>& vec , int n){//b9

    for(int i = 0 ; i < n ; ++i){ cout << "  " << vec[i] << "  ";}

}//b9

int main(){//b1
    int noofele = 5;    
    vector<int> ele;
    //cout << "No.of elements? - ";
    //cin >> noofele; 
    int val;
    /*
    for(int i = 0 ; i < noofele ; ++i){//b2"
        cout << "Enter ele - : ";
        cin >> val;
        ele.push_back(val);
    }//b2 
    */
    ele = {8,5,6,9,7};

    sort(ele.begin(),ele.end());
    int cost;
    int totalcost = 0;
    int i = 0;
    int range = 1;
    while(range <= noofele/2){//b5
            cout << "\n\n";
            display(ele,5);
            cout << "\n\n";
            if(i+range < noofele){//b6
                    cout << i << "  " << i + range << endl;
                    cost = ele[i] + ele[i+range];
                    ele[i] = cost;
                    totalcost+=cost;
                    ele[i+range] = -1;
                    i = range + i + 1;
            }//b6
            else{//b7
                    if(ele[i] != -1 ){//b8
                            cout << i << "  " << endl;;
                            totalcost += ele[i];
                    }//b8
                    range = range * 2;
                    i = 0;
            }//b7
            cout << endl;
    }//b5
    cout << "cost is - : " << totalcost << endl;
    return 0;
}//b1
