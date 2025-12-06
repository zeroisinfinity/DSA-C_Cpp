#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


void display(vector<int>& heap , int len){//b9
    cout << endl;
    for(int j = 0 ; j < len ; ++j)
        cout << "  " << heap[j] << "   " ;

    cout << endl;

}//b9

void insert(vector<int>& heap , int indx , int root){//b1
    int temp = heap[indx];
    int i = indx;
    while(i > root && temp > heap[i/2]){//b2
                heap[i] = heap[i/2];
                i = i/2;
    }//b2
    heap[i] = temp;
    //display(heap,indx);
}//b1


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


void heapsort(vector<int>& heap , int& len){//b5
    
    while(len > 1){//b12
        swap(heap,0,len-1);
        len--;
        int j = 1;
        int curr = 0;
        while(j < len - 1){//b8
            if(heap[j] <= heap[j+1]){//b9
                    j++;
            }//b9

            if(heap[curr] < heap[j]){//b29
                        swap(heap,curr,j);
                        curr = j;
                        j = 2*j + 1;
            }//b29
            else        break;
        
        }//b8
        display(heap,17);
        //cout << len << "  " << i << "   " << j << endl;  
    }//b12
    //len--;
}//b5

int main(){//b3
    int len = 17 , root = 0;
    vector<int> vec = {-78,-45,-78,-556,-78,-345,67,355,335,7,77,446,2,222,7,7,75};
    for(int i = 0 ; i < len ; ++i)
        insert(vec,i,root);

    display(vec,len);
    /*cout << "len is - " << len << endl;
    del(vec,len);
    cout << "len is - " << len << endl;
    del(vec,len);
    cout << "len is - " << len << endl;
    del(vec,len);
    cout << "len is - " << len << endl;*/

    heapsort(vec,len);
    //cout << "end"<<endl;
    display(vec,17);

    return 0;
}//b3
