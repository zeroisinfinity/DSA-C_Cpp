#include <iostream>
#include <cstring>
using namespace std;
#define size 1000

typedef struct{//b1
    char opening;
    char closing;
} brackets; //b1

class Stack{//b2
    
    private:
       brackets pairs[4] = {  {'(' , ')'} , 
                              {'[' , ']'} , 
                              {'{' , '}'},
                              {'<' , '>'},
                            };
    public:
       char stack[size];
       int top;
       string expression;
       Stack(string exp){//b3
            expression = exp;
            top = -1;
        }//b3
        
        bool isfull(){//b9
            if(top == size - 1){//b10
                cout<<"Stack is full"<<endl;
                return true;
            }//b10
            else{//b11
                return false;
            }//b11
        }//b9
        
        bool isempty(){//b9
            if(top == -1){//b10
                return true;
            }//b10
            else{//b11
                return false;
            }//b11
        }//b9
        
       void push(char brac){
            if(!isfull()){//b4
                top++;
                stack[top] = brac;
            }//b4
            else{//b5
                cout<<"Stack overflow"<<endl;
            }//b5
       }
       
       char pop(void){//b6
            if(!isempty()){//b7
                char brac = stack[top];
                top--;
                return brac;
            }//b7
            else{//b8
                cout<<"Stack underflow"<<endl;
                return '\0';
            }//b8
       }//b6
       
       
        int traverse_brac(char key);
        bool parenthesized(void);
               
};//b2


int Stack::traverse_brac(char key){//b14
            for(int trav = 0 ; trav < 4 ; trav++){//b15
                if(key == pairs[trav].opening or key == pairs[trav].closing){//b16
                  return trav;
                }//b16
            }//b15
            return -1;
}//b14
    
bool Stack::parenthesized(void){//b12
            for(int ch = 0 ; ch < expression.length() ; ch++){//b13
                  char exp_ch = expression[ch];
                  int indx = traverse_brac(exp_ch);
                  if(exp_ch == pairs[indx].opening and indx != -1){//b18
                      push(exp_ch);
                  }//b18
                  else if(indx == -1){//b19
                      continue;
                  }//b19
                  else{//b19
                      if(pop() == pairs[indx].opening){//b20
                          continue;
                      }//b20
                      else{//b21
                          return false;
                      }//b21
                  }//b19
            }//b13
            if(isempty()){
              return true;
            }
            else{
              return false;
            }
        }//b12
              


int main(){
      string exp;
      getline(cin,exp);
      Stack s1(exp);
      
      if(s1.parenthesized()){
          cout<<"Well parenthesized"<<endl;
      }
      else{
        cout<<"Expression not well parenthesized"<<endl;
        }
      
      return 0;
}

