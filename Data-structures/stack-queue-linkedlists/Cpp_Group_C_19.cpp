#include <iostream>
using namespace std;

//struct NODE
class Node { //b1
    public:
        string name;
        int PRN;
        Node* next;
        
        //default constructor
        Node() { //b2
            name = "";
            PRN = 0;
            next = nullptr;
        } //b2
        
        //Parameterized constructor
        Node(string name , int PRN) { //b3
            this->name = name;
            this->PRN = PRN;
            this->next = nullptr;
        } //b3
}; //b1

class Pinnacle {
    public:
        Node* Head;
        int size;
        
	Pinnacle():Head(NULL),size(0){};
        
        void insert_at_start(const string& str, int value) { //b-1
            Node* arg_node;
            arg_node = new Node();
            arg_node->name = str; 
            arg_node->PRN = value;
            arg_node->next = Head;
            Head = arg_node;
            size++;
        } //b-1
        
        void insert_at_location(const string& str, int value, int location);
        void insert_at_end(const string& str, int value);
        
        void del_from_start(void) { //b1
            Node* ll_holder = Head->next;
            delete Head; 
            Head = ll_holder;
            size--;
        } //b1
        
        void del_from_end(void);
        void del_from_location(int location);
        void display_LL(void);
        void friend concatenate_LL(Pinnacle& list1, Pinnacle& list2);
};

void Pinnacle::insert_at_location(const string& str, int value, int location) { //b-1 
    if(location < 1) { //b-2
        cout << "Location should be greater than or equal to 1" << endl;
        return;
    } //b-2
        
    if(location == 1) { //b-3 
        insert_at_start(str, value);
        return;
    } //b-3
    
    Node* arg_node = new Node();
    arg_node->name = str; 
    arg_node->PRN = value;
    
    Node* ll_holder = Head;
    for(int iter = 1; iter < (location - 1) && ll_holder; ++iter) { //b-4
        ll_holder = ll_holder->next;
    } //b-4

    if(!ll_holder) { //b-5
        cout << "Location out of range." << endl;
        return; 
    } //b-5

    arg_node->next = ll_holder->next;
    ll_holder->next = arg_node;
    size++;
} //b-1

void Pinnacle::insert_at_end(const string& str, int value) { //b1
    Node* arg_node = new Node;
    arg_node->name = str; 
    arg_node->PRN = value;
    arg_node->next = NULL;
    
    if(!Head) { //b2 
        Head = arg_node;
        return;
    } //b2_
    
    Node* ll_holder = Head;
    while(ll_holder->next) { //b3
        ll_holder = ll_holder->next;
    } //b3
    
    ll_holder->next = arg_node;
    size++;
} //b1

void Pinnacle::display_LL(void) { //b1
    if(!Head) { //b2
        cout << "List is empty" << endl;
    } //b2

    Node* ll_holder = Head;
    while(ll_holder) { //b2
        cout << ll_holder->name << endl;
        cout << ll_holder->PRN << endl;
        ll_holder = ll_holder->next;
    } //b2
} //b1

void Pinnacle::del_from_location(int location) { //b1
    if(!Head) { //b2
        del_from_start();
        return;
    } //b2
    
    Node* ll_holder = Head;
    for(int travs = 1; travs < (location - 1) && ll_holder; travs++) { //b3 
        ll_holder = ll_holder->next;
    } //b3
    
    if(!ll_holder) { //b4
        cout << "Out of range" << endl;
    } //b4
    
    Node* fake_node = ll_holder->next->next;
    delete ll_holder->next;
    ll_holder->next = fake_node;
    size--;
} //b1

void Pinnacle::del_from_end(void) { //b1
    if(!Head) { //b2
        cout << "List is empty" << endl;
    } //b2
    
    Node* ll_holder = Head;
    while(ll_holder->next->next) { //b3
        ll_holder = ll_holder->next;
    } //b3
    
    delete ll_holder->next;
    ll_holder->next = NULL;
    size--;
} //b1

void concatenate_LL(Pinnacle& list1, Pinnacle& list2){
    Node* ll_holder = list1.Head;
    while(ll_holder -> next){
          ll_holder = ll_holder -> next;
    }
    ll_holder -> next = list2.Head;
    list1.size += list2.size;
}

int main() {
    Pinnacle list1;
    list1.insert_at_start("abc", 76);
    list1.insert_at_start("xyz", 5476);
    list1.insert_at_start("pqr", 76);
    list1.insert_at_start("hij", 68236);

    Pinnacle list2;
    list2.insert_at_start("lmno", 9933);
    list2.insert_at_start("srt", 993);
    list2.insert_at_start("klm", 9931);
    list2.insert_at_start("blah", 4393);
    list2.insert_at_start("haha", 9930);

    list1.display_LL();
    cout<<list1.size<<endl;
    cout<<"---------------------------------------------------------------------------------------------------------------------"<<endl;
    list2.display_LL();
    cout<<list2.size<<endl;
    cout<<"---------------------------------------------------------------------------------------------------------------------"<<endl;
    concatenate_LL(list1,list2);
    list1.display_LL();
    cout<<list1.size<<endl;
    cout<<"---------------------------------------------------------------------------------------------------------------------"<<endl;
    list2.display_LL();
    cout<<list2.size<<endl;
    return 0;
}
