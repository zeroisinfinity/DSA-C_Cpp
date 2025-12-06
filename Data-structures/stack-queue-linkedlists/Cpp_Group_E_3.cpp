#include <iostream>
#include <string>

using namespace std;

/*
    A double-ended queue (deque) is a linear list in which additions and deletions may be 
    made at either end. Obtain a data representation mapping a deque into a one-dimensional 
    array. Write a C++ program to simulate deque with functions to add and delete elements 
    from either end of the deque.
*/

const int MAX_SIZE = 100; // Maximum size of the deque

// Class to represent the Deque
class Deque {
private:
    int deque[MAX_SIZE]; // Array to store elements
    int front; // Index of the front element
    int rear; // Index of the rear element
    int size; // Current number of elements in the deque

public:
    // Constructor
    Deque() {
        front = -1; // Initialize front index
        rear = -1; // Initialize rear index
        size = 0; // Initialize size
    }

    // Function to add an element at the front of the deque
    void addFront(int value) {
        if (size == MAX_SIZE) { // Check if the deque is full
            cout << "Deque is full. Cannot add more elements." << endl;
            return;
        }

        if (front == -1) { // If the deque is empty
            front = 0;
            rear = 0; // Initialize both front and rear to the first index
        } else {
            front = (front - 1 + MAX_SIZE) % MAX_SIZE; // Circularly decrement front index
        }

        deque[front] = value; // Add the element at the front
        size++; // Increment the size
        cout << "Added " << value << " at the front." << endl;
    }

    // Function to add an element at the rear of the deque
    void addRear(int value) {
        if (size == MAX_SIZE) { // Check if the deque is full
            cout << "Deque is full. Cannot add more elements." << endl;
            return;
        }

        if (rear == -1) { // If the deque is empty
            front = 0; // Initialize front index
            rear = 0; // Initialize rear index
        } else {
            rear = (rear + 1) % MAX_SIZE; // Circularly increment rear index
        }

        deque[rear] = value; // Add the element at the rear
        size++; // Increment the size
        cout << "Added " << value << " at the rear." << endl;
    }

    // Function to delete an element from the front of the deque
    void deleteFront() {
        if (size == 0) { // Check if the deque is empty
            cout << "No elements in the deque to delete." << endl;
            return;
        }

        cout << "Deleted " << deque[front] << " from the front." << endl;
        front = (front + 1) % MAX_SIZE; // Circularly increment front index
        size--; // Decrement the size

        // Reset front and rear if deque becomes empty
        if (size == 0) {
            front = -1;
            rear = -1;
        }
    }

    // Function to delete an element from the rear of the deque
    void deleteRear() {
        if (size == 0) { // Check if the deque is empty
            cout << "No elements in the deque to delete." << endl;
            return;
        }

        cout << "Deleted " << deque[rear] << " from the rear." << endl;
        rear = (rear - 1 + MAX_SIZE) % MAX_SIZE; // Circularly decrement rear index
        size--; // Decrement the size

        // Reset front and rear if deque becomes empty
        if (size == 0) {
            front = -1;
            rear = -1;
        }
    }

    // Function to display the elements in the deque
    void display() const {
        if (size == 0) {
            cout << "No elements in the deque." << endl;
            return;
        }

        cout << "Elements in the deque: ";
        for (int i = 0; i < size; i++) {
            int index = (front + i) % MAX_SIZE; // Calculate circular index
            cout << deque[index] << " ";
        }
        cout << endl;
    }
};

int main() {
    Deque deque; // Create a Deque instance
    int choice, value;

    do {
        cout << "\nDeque Menu:" << endl;
        cout << "1. Add Element at Front" << endl;
        cout << "2. Add Element at Rear" << endl;
        cout << "3. Delete Element from Front" << endl;
        cout << "4. Delete Element from Rear" << endl;
        cout << "5. Display Elements" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to add at the front: ";
                cin >> value;
                deque.addFront(value);
                break;

            case 2:
                cout << "Enter value to add at the rear: ";
                cin >> value;
                deque.addRear(value);
                break;

            case 3:
                deque.deleteFront();
                break;

            case 4:
                deque.deleteRear();
                break;

            case 5:
                deque.display();
                break;

            case 6:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
