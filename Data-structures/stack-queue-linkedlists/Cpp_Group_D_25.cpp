#include <iostream>
#include <cstring>
//I'VE EXTRACTED THIS CODE FROM SNAPSHOT OF MY OWN CODE THUS THE COMMENTS COZ CHATGPT ADDED THEM BY ITSELF.
using namespace std;

#define size 50

class Stack {
public:
    int top;
    char stack[size];

    Stack() { 
        // b4: Check if the stack is empty
        top = -1; 
        // b4 end
    }

    int isstack_empty() {
        // b4: Check if the stack is empty
        if (top == -1) {
            return 1;
        } else {
            return 0;
        }
        // b4 end
    }

    int isstack_full() {
        // b5: Check if the stack is full
        if (top == size - 1) {
            return 1;
        } else {
            return 0;
        }
        // b5 end
    }

    void push(char chr) {
        // b6: Push characters into the stack
        if (!isstack_full()) {
            top++;
            stack[top] = chr;
        } else {
            cout << "Stack is already full" << endl;
        }
        // b6 end
    }

    char pop() {
        // b7: Pop characters from the stack
        if (!isstack_empty()) {
            char popped = stack[top];
            top--;
            return popped;
        } else {
            cout << "Stack is already empty" << endl;
            return '-';
        }
        // b7 end
    }

    void display() {
        // b3: Display the contents of the stack
        for (int iter = 0; iter <= top; iter++) {
            cout << stack[iter] << endl;
        }
        // b3 end
    }
};

int main() {
    // b1: Input the string from the user
    Stack palin;
    string str;
    cin >> str;
    // b1 end

    int i = 0, j = 0;

    // b2: Calculate the length of the string
    while (str[i] != '\0') {
        i++;
    }
    // b2 end

    // b8: Push each character of the string into the stack
    while (str[j] != '\0') {
        palin.push(str[j]);
        j++;
    }
    // b8 end

    i = 0;
    j--;

    // b9: Compare characters from the stack with the string
    while (j >= 0) {
        if (palin.pop() != str[i]) {
            // b10: If any character does not match, it's not a palindrome
            cout << "Not a palindrome" << endl;
            return 0;
            // b10 end
        }
        i++;
        j--;
    }
    // b9 end

    // b11: If all characters match, it's a palindrome
    cout << "Palindrome" << endl;
    return 0;
    // b11 end
}
