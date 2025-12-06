#include <iostream>
using namespace std;

struct Node{//b1
	int data;
	Node* left;
	Node* right;
};//b1

class Tree{//b2
	public:
		Node* root;
		Tree(){//b6
			root -> left = nullptr;
			root -> right = nullptr;
		}//b6
		void insert_left_node(int& val){//b4
		
			if(!root){//b5
				root = new Node();
				root -> data = val;
				return;
			}//b5
			
			Node* arg_node = new Node();
			arg_node -> data = val;
			
			root -> left = arg_node;
		}//b4
};//b2

int main(){//b3
	return 0;
}//b3
