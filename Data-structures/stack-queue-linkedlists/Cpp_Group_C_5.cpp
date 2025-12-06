#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

/*
    Appointment scheduling system for a day using a linked list.
    The program allows you to set a start and end time, specify the 
    minimum and maximum duration for appointment slots, and provides 
    functions to:
    a) Display free slots
    b) Book an appointment
    c) Cancel an appointment (check validity, time bounds, availability)
    d) Sort the list based on time
    e) Sort the list based on time using pointer manipulation
*/

// Appointment structure
struct Appointment {
    string title; // Appointment title
    int start; // Start time in minutes
    int duration; // Duration in minutes
    Appointment* next; // Pointer to the next appointment

    Appointment(string t, int s, int d) : title(t), start(s), duration(d), next(nullptr) {}
};

// Class to manage the appointment schedule
class AppointmentScheduler {
private:
    Appointment* head; // Head pointer of the linked list
    int startTime; // Start time of the day in minutes
    int endTime; // End time of the day in minutes
    int minDuration; // Minimum duration of appointments in minutes
    int maxDuration; // Maximum duration of appointments in minutes

public:
    AppointmentScheduler(int start, int end, int minDur, int maxDur)
        : startTime(start), endTime(end), minDuration(minDur), maxDuration(maxDur), head(nullptr) {}

    // Function to display free slots
    void displayFreeSlots() {
        int currentTime = startTime;
        Appointment* current = head;

        cout << "Free slots:" << endl;

        while (currentTime < endTime) {
            // Check if there's an appointment starting at currentTime
            if (current && current->start == currentTime) {
                // If there's an appointment, skip its duration
                currentTime += current->duration;
                current = current->next;
            } else {
                // Check for the next appointment
                Appointment* nextAppointment = current;
                while (nextAppointment && nextAppointment->start < currentTime) {
                    nextAppointment = nextAppointment->next;
                }

                // Determine free slot duration
                int freeSlotStart = currentTime;
                int freeSlotEnd = (nextAppointment) ? nextAppointment->start : endTime;

                if (freeSlotEnd > freeSlotStart) {
                    cout << "From " << freeSlotStart / 60 << ":" << setw(2) << setfill('0') << freeSlotStart % 60
                         << " to " << freeSlotEnd / 60 << ":" << setw(2) << setfill('0') << freeSlotEnd % 60 << endl;
                }
                currentTime++;
            }
        }
    }

    // Function to book an appointment
    bool bookAppointment(const string& title, int start, int duration) {
        if (duration < minDuration || duration > maxDuration) {
            cout << "Appointment duration must be between " << minDuration << " and " << maxDuration << " minutes." << endl;
            return false;
        }
        if (start < startTime || (start + duration) > endTime) {
            cout << "Appointment time is out of bounds." << endl;
            return false;
        }

        // Check for conflicts
        Appointment* current = head;
        while (current) {
            if ((start < current->start + current->duration) && (current->start < start + duration)) {
                cout << "Appointment conflicts with an existing appointment." << endl;
                return false;
            }
            current = current->next;
        }

        // Create new appointment and insert it into the list
        Appointment* newAppointment = new Appointment(title, start, duration);
        if (!head || head->start > start) { // Insert at the beginning
            newAppointment->next = head;
            head = newAppointment;
            cout << "Appointment booked successfully!" << endl;
            return true;
        }

        // Insert at the correct position
        current = head;
        while (current->next && current->next->start < start) {
            current = current->next;
        }
        newAppointment->next = current->next;
        current->next = newAppointment;
        cout << "Appointment booked successfully!" << endl;
        return true;
    }

    // Function to cancel an appointment
    bool cancelAppointment(const string& title) {
        Appointment* current = head;
        Appointment* previous = nullptr;

        while (current) {
            if (current->title == title) {
                if (previous) {
                    previous->next = current->next;
                } else {
                    head = current->next; // Canceling the head appointment
                }
                delete current;
                cout << "Appointment '" << title << "' canceled successfully." << endl;
                return true;
            }
            previous = current;
            current = current->next;
        }

        cout << "Appointment '" << title << "' not found." << endl;
        return false;
    }

    // Function to sort the list based on time
    void sortAppointments() {
        if (!head || !head->next) return; // No need to sort

        Appointment* sorted = nullptr; // New sorted list

        Appointment* current = head;
        while (current) {
            Appointment* next = current->next; // Store next appointment
            if (!sorted || sorted->start >= current->start) { // Insert at beginning or sorted list is empty
                current->next = sorted;
                sorted = current;
            } else {
                Appointment* temp = sorted;
                while (temp->next && temp->next->start < current->start) {
                    temp = temp->next; // Find the position to insert
                }
                current->next = temp->next;
                temp->next = current; // Insert current into the sorted list
            }
            current = next; // Move to the next appointment
        }
        head = sorted; // Update head to the sorted list
        cout << "Appointments sorted by time." << endl;
    }

    // Function to display appointments
    void displayAppointments() const {
        Appointment* current = head;
        if (!current) {
            cout << "No appointments scheduled." << endl;
            return;
        }

        cout << "Scheduled appointments:" << endl;
        while (current) {
            cout << "Title: " << current->title << ", Start: "
                 << current->start / 60 << ":" << setw(2) << setfill('0') << current->start % 60
                 << ", Duration: " << current->duration << " minutes" << endl;
            current = current->next;
        }
    }

    // Destructor to free memory
    ~AppointmentScheduler() {
        while (head) {
            Appointment* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    int startTime = 9 * 60; // Start time in minutes (9:00 AM)
    int endTime = 17 * 60; // End time in minutes (5:00 PM)
    int minDuration = 30; // Minimum appointment duration
    int maxDuration = 120; // Maximum appointment duration

    AppointmentScheduler scheduler(startTime, endTime, minDuration, maxDuration);
    int choice;
    string title;
    int start, duration;

    do {
        cout << "\nAppointment Scheduler Menu:" << endl;
        cout << "1. Display Free Slots" << endl;
        cout << "2. Book an Appointment" << endl;
        cout << "3. Cancel an Appointment" << endl;
        cout << "4. Sort Appointments" << endl;
        cout << "5. Display Appointments" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                scheduler.displayFreeSlots();
                break;

            case 2:
                cout << "Enter appointment title: ";
                cin >> ws; // Ignore leading whitespace
                getline(cin, title);
                cout << "Enter start time (in minutes): ";
                cin >> start;
                cout << "Enter duration (in minutes): ";
                cin >> duration;
                scheduler.bookAppointment(title, start, duration);
                break;

            case 3:
                cout << "Enter appointment title to cancel: ";
                cin >> ws; // Ignore leading whitespace
                getline(cin, title);
                scheduler.cancelAppointment(title);
                break;

            case 4:
                scheduler.sortAppointments();
                break;

            case 5:
                scheduler.displayAppointments();
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
