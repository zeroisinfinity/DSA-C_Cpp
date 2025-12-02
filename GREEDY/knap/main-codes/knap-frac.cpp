#include <iostream>
#include <iomanip>
using namespace std;

int main(){//b1 
    int n = 7;
    int capacity = 15;
    int bag = 0;
    int profit[7] = {12,17,9,7,5,21,8};
    int weight[7] = {2,5,7,3,1,4,1};
    int o_weight[7] = {2,5,7,3,1,4,1};
    double net[7];
    double temp;
    double maxprof;

    for(int i = 0 ; i < 7 ; ++i)
                net[i] = (double)profit[i]/weight[i];

    for(int j = 0 ; j < 6 ; ++j){//b5
        for(int k = j + 1 ; k < 7 ; ++k){//b6
            if(net[j] < net[k]){//b7
                temp = net[k]    ; net[k] = net[j]       ; net[j] = temp;
                temp = profit[k] ; profit[k] = profit[j] ; profit[j] = temp;
                temp = weight[k] ; weight[k] = weight[j] ; weight[j] = temp;
            }//b7
        }//b6
    }//b5

    int p = 0;
    int soln[7][2] = {0}; 
    
    for (int i = 0; i < 7; i++) {
                    soln[i][0] = weight[i];       
    }

    while(bag + 1 <= capacity && p < 7){//b8
                if(weight[p] > 0){//b10
                    bag++;
                    weight[p]--;
                    soln[p][1]++;
                    maxprof += net[p];
                }//b10
                else p++;
        }//b8

cout << fixed << setprecision(6);
cout << "profit  weight  net        units_taken  frac_taken  profit_taken\n";
for (int i = 0; i < n; ++i) {
    double frac = double(soln[i][1]) / double(o_weight[i]); // orig_weight is copy of weights before you destroy them
    double profit_taken = frac * profit[i];
    cout << setw(6) << profit[i] << "  "
         << setw(6) << o_weight[i] << "  "
         << setw(8) << net[i] << "  "
         << setw(11) << soln[i][1] << "  "
         << setw(9) << frac << "  "
         << setw(12) << profit_taken << '\n';
}
cout << "\nTotal profit = " << maxprof << '\n';
    return 0;
}//b1
