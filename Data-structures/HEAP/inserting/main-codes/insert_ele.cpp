#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


void display(vector<int>& heap , int len){//b9
    cout << endl;
    for(int j = 0 ; j < 9 ; ++j)
        cout << "  " << heap[j] << "   " ;

    cout << endl;

}//b9

void insert(vector<int>& heap , int indx , int root){//b1
    int temp = heap[indx];
    int i = indx;
    while(i > root && temp > heap[i % 2 == 0 ? (i/2) - 1 : i/2]){//b2
                heap[i] = heap[i % 2 == 0 ? (i/2) - 1 : i/2];
                i = i % 2 == 0 ? (i/2) - 1 : i/2 ;
    }//b2
    heap[i] = temp;
    display(heap,indx);
}//b1

int main(){//b3
    int len = 9;
    vector<int> vec = {40,34,67,23,1,6,45,8,33};
    for(int i = 0 ; i < 9 ; ++i)
        insert(vec,i);


    return 0;
}//b3
