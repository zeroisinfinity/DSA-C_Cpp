#include <iostream>
using namespace std;

//struct NODE
class Node{//b1
	public:
		
		int data;
		Node* next;
		
		//default constructor
		Node(){//b2
			
			data = 0;
			next = nullptr;
		}//b2
		
		//Parameterized constructor
		Node(int data, Node* next){//b3
			
			this -> data = data;
			this -> next = next;
			
		}//b3
		
};//b1
 


class LinkedList{

		public:
			Node* Head;
			//Node node_obj;
			//LinkedList():Head(NULL),node_obj(){}; //cannot intialize obj of another class.
			

			void insert_at_start(int value){ //b-1
					Node* arg_node;
					arg_node = new Node();
					cout<<"arg_node at start - "<<arg_node<<endl;
					arg_node -> data = value;
					arg_node -> next = Head;
					Head = arg_node;
		
			}//b-1
			void insert_at_location(int value, int location);

			void insert_at_end(int value);
			void del_from_start(void){//b1
					Node* ll_holder = Head -> next;
					delete Head; 
					Head = ll_holder;
			}//b1
			
			void del_from_end(void);
			void del_from_location(int location);
			void display_LL(void);
			
};



void LinkedList :: insert_at_location(int value , int location){ //b-1 
		
		//IF LOCATION IS < 1
		if(location < 1){//b-2
				cout<<"Location should be greater than or equal to 1"<<endl;
				return ;
                
}//b-2
		
		//IF LOCATION IS 1
		if(location == 1){//b-3 
				insert_at_start(value);
				return;
}//b-3
		Node* arg_node = new Node();
		arg_node -> data = value;
		//arg_node -> next = Head;
		Node* ll_holder = Head;
		

		for(int iter = 1; iter < (location - 1 ) && ll_holder ; ++iter){//b-4
				ll_holder = ll_holder -> next;
			}//b-4

		if(!ll_holder){//b-5
                cout<<"Location out of range."<<endl;
				return ; 
            }//b-5

		arg_node -> next = ll_holder -> next;
		ll_holder -> next = arg_node;
		cout<<"arg_node at location - "<<arg_node<<endl;

                
        
}//b-1

void LinkedList :: insert_at_end(int value){//b1
        
        Node* arg_node = new Node;
        arg_node -> data = value;
        arg_node -> next = NULL;
        
        if(!Head){//b2 
                Head = arg_node;
                return;
            }//b2_
        
        Node* ll_holder = Head;
        while(ll_holder -> next){//b3
            ll_holder = ll_holder -> next;
            }//b3
        ll_holder -> next = arg_node;
		cout<<"arg_node at end - "<<arg_node<<endl;

}//b1


void LinkedList :: display_LL(void){//b1

        if(!Head){//b2
            cout<<"List is empty"<<endl;
        }//b2

        Node* ll_holder = Head;
        while(ll_holder){//b2
            cout<<ll_holder -> data<<endl;
            ll_holder = ll_holder -> next;
			cout<<"node display - "<<ll_holder<<endl;

            }//b2
        
}//b1



			
void LinkedList :: del_from_location(int location){//b1
		
		if(!Head){//b2
		  	return del_from_start();
		}//b2
		Node* ll_holder = Head;
		for(int travs = 1 ; travs < (location - 1) && ll_holder ; travs++){//b3 
			ll_holder = ll_holder -> next;
			}//b3
		if(!ll_holder){//b4
			cout<<"out of range"<<endl;
		}//b4
		Node* fake_node;
		fake_node = ll_holder -> next -> next;
		delete ll_holder->next;
		ll_holder -> next = fake_node;
}//b1



void LinkedList :: del_from_end(void){//b1
		if(!Head){//b2
			cout<<"List is empty"<<endl;
		}//b2
		
		Node* ll_holder = Head;
		while(ll_holder->next->next){//b3
			ll_holder = ll_holder -> next;
			}//b3
		delete ll_holder->next;
		ll_holder->next = NULL;
			
}//b1
int main(){

    LinkedList list1;

    list1.insert_at_end(10);
    list1.insert_at_end(20);
    list1.insert_at_end(11);
    list1.insert_at_end(21);
    list1.insert_at_end(12);
    /*list1.insert_at_end(22);
    list1.insert_at_end(13);
    list1.insert_at_end(23);
    list1.insert_at_start(5);*/
	list1.insert_at_start(50);
    //list1.insert_at_start(500);
    //list1.insert_at_start(5000);
    /*list1.insert_at_start(500000);

	
    list1.insert_at_location(15, 78979);
	list1.insert_at_location(155, 5);
    list1.insert_at_location(145, 2);
    list1.insert_at_location(109, 9);*/
    list1.insert_at_location(189, 3);

	
    list1.del_from_start();
    list1.del_from_location(3);
    //list1.del_from_end();
	
    cout << "Linked list after insertions: "<<endl;
	
    list1.display_LL();

	
	return 0;
}
