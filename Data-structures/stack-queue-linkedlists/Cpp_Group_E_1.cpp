#include <iostream>
#include <string>

using namespace std;

/*
    Queues are frequently used in computer programming, and a typical example is the 
    creation of a job queue by an operating system. If the operating system does not use 
    priorities, then the jobs are processed in the order they enter the system. 
    Write a C++ program for simulating a job queue. Write functions to add a job 
    and delete a job from the queue.
*/

const int MAX_SIZE = 100; // Maximum size of the queue

// Class to represent the Job Queue
class JobQueue {
private:
    struct Job {
        int jobID; // Unique identifier for the job
        string jobName; // Name of the job
    };

    Job queue[MAX_SIZE]; // Array to store jobs
    int front; // Index of the front job
    int rear; // Index of the rear job
    int size; // Current number of jobs in the queue

public:
    // Constructor
    JobQueue() {
        front = 0; // Initialize front index
        rear = -1; // Initialize rear index
        size = 0; // Initialize size
    }

    // Function to add a job to the queue
    void addJob(int id, const string& name) {
        if (size == MAX_SIZE) { // Check if the queue is full
            cout << "Queue is full. Cannot add more jobs." << endl;
            return;
        }

        rear++; // Increment rear index
        queue[rear].jobID = id; // Set job ID
        queue[rear].jobName = name; // Set job name
        size++; // Increment the size
        cout << "Job added: " << name << " (ID: " << id << ")" << endl;
    }

    // Function to delete a job from the queue
    void deleteJob() {
        if (size == 0) { // Check if the queue is empty
            cout << "No jobs in the queue to delete." << endl;
            return;
        }

        cout << "Job deleted: " << queue[front].jobName << " (ID: " << queue[front].jobID << ")" << endl;
        front++; // Increment front index
        size--; // Decrement the size
    }

    // Function to display the jobs in the queue
    void displayJobs() const {
        if (size == 0) {
            cout << "No jobs in the queue." << endl;
            return;
        }

        cout << "Jobs in the queue: " << endl;
        for (int i = front; i <= rear; i++) { // Iterate from front to rear
            cout << "Job ID: " << queue[i].jobID << ", Job Name: " << queue[i].jobName << endl;
        }
    }
};

int main() {
    JobQueue queue; // Create a JobQueue instance
    int choice, jobID;
    string jobName;

    do {
        cout << "\nJob Queue Menu:" << endl;
        cout << "1. Add Job" << endl;
        cout << "2. Delete Job" << endl;
        cout << "3. Display Jobs" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Job ID: ";
                cin >> jobID;
                cout << "Enter Job Name: ";
                cin >> jobName;
                queue.addJob(jobID, jobName);
                break;

            case 2:
                queue.deleteJob();
                break;

            case 3:
                queue.displayJobs();
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
