#include <iostream>
#include <limits>
#define MAX 100
using namespace std;

class Job_queue{//b1
      private:
          string queue[MAX];
          int front;
          int rear;
      public:
          Job_queue(){//b2
              front = -1;
              rear = -1;
          }//b2
          
          bool isempty(void){//b3
                if(rear == -1){//b4
                    return true;
                }//b4
                else{//b5
                    return false;
                }//b5
          }//b3
          
          bool isfull(void){//b6
                if(rear == MAX - 1 && front == 0){//b7
                    return true;
                }//b7
                else{//b8
                    return false;
                }//b8
          }//b6
          
          void addjob(string job){//b9
          
                if(isempty()){//b10
                    front ++;
                }//b10
                
                if(isfull()){//b11
                    cout<<"Overflow"<<endl;
                    return;
                }//b11
                
                rear ++;
                queue[rear] = job;
          }//b9
          
          string deljob(void){//b12
          
                if(isempty()){//b13
                    return "Underflow";
                }//b13
                string deleted_job = queue[front];

                
                if(front == rear){//b14
                    cout<<"reached"<<endl;
                    front = -1;
                    rear = -1;
                }//b14
                front ++;
                for(int i = 1; i <= rear ; i++){
                      queue[i - 1] = queue[i];
                } 
                return deleted_job;
          }//b12
          
          void display_jobs(void){//b19
                if(isempty()){//b26
                    cout<<"QUEUE IN EMPTY NO JOBS"<<endl;
                }//b26
                for(int ele = front ; ele <= rear ; ele++){//b20
                    if(queue[ele] != ""){//b21
                    cout<<"queue["<<ele<<"] --- "<<queue[ele]<<endl;
                    }//b21
                }//b20
          }//b19
          
};//b1

int menu(void) {
    int op;
    while (true) { // Input validation loop
        cout << "Enter 1 to register a job in CPU" << endl;
        cout << "Enter 2 to delete a job from CPU" << endl;
        cout << "Enter 3 to display the job-queue" << endl;
        cout << "Enter 4 to exit" << endl;
        cout << "Enter --- ";

        cin >> op;

        if (cin.fail()) {
            cin.clear();  // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
            cout << "Invalid input. Please enter a digit." << endl;
        } else {
            break; // Exit the loop when a valid input is entered
        }
    }
    return op;
}


int main() { // b23
    int queue_count = 0;
    string job, choice, del;
    Job_queue jb;
    int option = menu();
    while (true) { // b16
        switch (option) { // b17
            case 1:
                cout << "Enter job --- ";
                cin.ignore();  
                getline(cin, job);
                jb.addjob(job);
                break;
            case 2:
                cout << "Deleting job ..." << endl;
                del = jb.deljob();
                if (del != "Underflow") { // b24
                    cout << "Job " << del << " is deleted" << endl;
                } else { // b25
                    cout << "Queue is in underflow condition" << endl;
                }
                break;
            case 3:
                jb.display_jobs();
                break;
            case 4:
                cout << "Are you sure you want to quit the program?! [y/n] ";
                cin.ignore();  
                getline(cin, choice);
                break;
            default:
                cout << "Enter choices between 1-4" << endl;
                break;
        }

        if (choice == "y" || choice == "Y") { // b18
            cout << "THANK YOU FOR USING OUR PROGRAM!" << endl;
            break;
        } // b18

        cout << "***************************************** JOB QUEUE PROGRAM *************************************************" << endl;
        option = menu(); 
    } // b16

    return 0;
} // b23

