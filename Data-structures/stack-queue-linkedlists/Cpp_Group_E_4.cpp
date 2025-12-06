#include <iostream>
#include <string>

using namespace std;

/*
    Pizza parlor accepting a maximum M orders. Orders are served on a first-come, 
    first-served basis. Once placed, an order cannot be cancelled. 
    Write a C++ program to simulate the system using a circular queue.
*/

const int MAX_SIZE = 5; // Maximum number of orders

// Class to represent the Circular Queue for the pizza parlor
class CircularQueue {
private:
    string orders[MAX_SIZE]; // Array to store orders
    int front; // Index of the front order
    int rear; // Index of the rear order
    int size; // Current number of orders in the queue

public:
    // Constructor
    CircularQueue() {
        front = -1; // Initialize front index
        rear = -1; // Initialize rear index
        size = 0; // Initialize size
    }

    // Function to add an order to the circular queue
    void addOrder(const string& order) {
        if (size == MAX_SIZE) { // Check if the queue is full
            cout << "Order queue is full. Cannot add more orders." << endl;
            return;
        }

        if (front == -1) { // If the queue is empty
            front = 0; // Initialize front index
        }

        rear = (rear + 1) % MAX_SIZE; // Circularly increment rear index
        orders[rear] = order; // Add the order
        size++; // Increment the size
        cout << "Order added: " << order << endl;
    }

    // Function to serve (delete) an order from the circular queue
    void serveOrder() {
        if (size == 0) { // Check if the queue is empty
            cout << "No orders to serve." << endl;
            return;
        }

        cout << "Serving order: " << orders[front] << endl;
        front = (front + 1) % MAX_SIZE; // Circularly increment front index
        size--; // Decrement the size

        // Reset front and rear if the queue becomes empty
        if (size == 0) {
            front = -1;
            rear = -1;
        }
    }

    // Function to display the current orders in the queue
    void displayOrders() const {
        if (size == 0) {
            cout << "No orders in the queue." << endl;
            return;
        }

        cout << "Current orders in the queue: ";
        for (int i = 0; i < size; i++) {
            int index = (front + i) % MAX_SIZE; // Calculate circular index
            cout << orders[index] << " ";
        }
        cout << endl;
    }
};

int main() {
    CircularQueue queue; // Create a CircularQueue instance
    int choice;
    string order;

    do {
        cout << "\nPizza Parlor Menu:" << endl;
        cout << "1. Add Order" << endl;
        cout << "2. Serve Order" << endl;
        cout << "3. Display Current Orders" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter order name: ";
                cin >> order;
                queue.addOrder(order);
                break;

            case 2:
                queue.serveOrder();
                break;

            case 3:
                queue.displayOrders();
                break;

            case 4:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
