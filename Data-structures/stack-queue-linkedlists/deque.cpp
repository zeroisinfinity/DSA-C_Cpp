#include <iostream>
#define MAX 5
using namespace std;

class Deque{//b1
    public:
          int de_que[MAX];
          int front , rear; 
          Deque(){//b2
              front = -1;
              rear = -1;
          }//b2
          
          bool isempty(void){//b3

                if(front == -1){//b4
                    return true;
                }//b4
                
                else{//b5
                    return false;
                }//b5
                
          }//b3
          
          bool isfull(void){//b6

                if((rear + 1)%MAX == front){//b7
                    return true;
                }//b7
                
                else{//b8
                    return false;
                }//b8
                
          }//b6
        
          void insert_front(int val){//b9
                if(isempty()){//b10
                    rear++;
                    front++;
                    de_que[front] = val;
                    return;
                }//b10
                else if(isfull()){//b11
                    cout<<"DEQUE OVERFLOW"<<endl;
                    return;
                }//b11
                if(front == 0){//b14
                    front = MAX - 1;
                    de_que[front] = val;
                    return;
                }//b14
                front--;
                de_que[front] = val;
          }//b9
          
          void insert_rear(int val){//b9
          
                if(isempty()){//b10
                    front++;
                    rear++;
                    de_que[rear] = val;
                    return;
                }//b10
                
                else if(isfull()){//b11
                    cout<<"DEQUE OVERFLOW"<<endl;
                    return;
                }//b11
                
                rear = (rear + 1)%MAX;
                de_que[rear] = val;
                
          }//b9
          
          void del_front(void){//b12
                
                if(isempty()){//b13
                      cout<<"DEQUE UNDERFLOW"<<endl;
                      return;
                }//b13
                
                if(front == rear){//b15
                      front = -1;
                      rear = -1;
                      return;
                      
                }//b15
              
                front = (front+1)%MAX;
                
          }//b12
          
          void del_rear(void){//b12
                
                
                if(isempty()){//b13
                      cout<<"DEQUE UNDERFLOW"<<endl;
                      return;
                }//b13
                
                if(front == rear){//b15
                      front = -1;
                      rear = -1;
                      return;
                      
                }//b15
                else if(rear == 0){
                      rear = MAX - 1;
                      return;
                }
                
                rear--;
                
                
                
          }//b12
          
          void display(void){//b17
                for(int trav = 0 ; trav < MAX ; trav++){//b18
                    cout<<"de_que["<<trav<<"] -- "<<de_que[trav]<<endl;
                }//b18
                cout<<"front --> "<<front<<"   "<<"rear --> "<<rear<<endl;
          }//b17
          
          
};//b1

int main(){//b20

          Deque dq;
          int choice , val;
          while(true){
              cin>>choice;
              switch(choice){
                  case 1:
                        cout<<"val --- ";
                        cin>>val;
                        dq.insert_front(val);
                        cout<<"front --> "<<front<<"   "<<"rear --> "<<rear<<endl;
                        break;
                  case 2:
                        cout<<"val --- ";
                        cin>>val;
                        dq.insert_rear(val);
                        cout<<"front --> "<<front<<"   "<<"rear --> "<<rear<<endl;
                        break;
                  case 3:
                        dq.del_front();
                        cout<<"front"<<dq.front<<"   "<<"rear"<<dq.rear<<endl;
                        break;
                  case 4:
                        dq.del_rear();
                        cout<<"front --> "<<front<<"   "<<"rear --> "<<rear<<endl;
                        break;
                  case 5:
                        dq.display();
                        break;
                }
              if(choice == 6){
              break;
              }
          }
          return 0;
}//b20
