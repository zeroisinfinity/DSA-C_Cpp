#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


void swap(vector<int>& heap, int i, int j){
    int temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}
 

void del(vector<int>& heap , int& len){//b5
    
    swap(heap,0,len-1);
    int j = 1;
    int curr = 0;
    while(j < len - 1){//b8
            if(heap[j] < heap[j+1]){//b9
                    j = j+1; 
            }//b9
            
            if(heap[curr] < heap[j]){//b23
                    swap(heap,curr,j);
                    curr = j;
                    j = 2*j + 1;
            }//b23
            else    break;
    }//b8
    len--;
    display(heap,len);

    //len--;
}//b5

void display(vector<int>& heap , int len){//b9
    cout << endl;
    for(int j = 0 ; j < len ; ++j)
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
    int len = 9 , root = 0;
    vector<int> vec = {40,34,67,23,1,6,45,8,33};
    for(int i = 0 ; i < 9 ; ++i)
        insert(vec,i,root);

    display(vec,len);
    cout << "len is - " << len << endl;
    del(vec,len);
    cout << "len is - " << len << endl;
    del(vec,len);
    cout << "len is - " << len << endl;
    del(vec,len);
    cout << "len is - " << len << endl;

    return 0;
}//b3
