#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

/*
    The ticket booking system of Cinemax theater implemented using C++. 
    There are 10 rows and 7 seats in each row. A doubly circular linked list 
    is maintained to keep track of free seats at rows. 
    On demand:
    a) The list of available seats is to be displayed
    b) The seats are to be booked
    c) The booking can be cancelled.
*/

const int NUM_ROWS = 10;
const int NUM_SEATS = 7;

// Node structure for the doubly linked list
struct Seat {
    char seatNumber; // Seat identifier (A-G)
    bool isBooked; // Booking status
    Seat* next; // Pointer to the next seat
    Seat* prev; // Pointer to the previous seat

    Seat(char number) : seatNumber(number), isBooked(false), next(nullptr), prev(nullptr) {}
};

// Class to represent a row of seats
class Row {
public:
    Seat* head; // Head pointer of the circular linked list

    Row() : head(nullptr) {
        createSeats(); // Initialize the row with seats
    }

    // Function to create seats in the row
    void createSeats() {
        Seat* last = nullptr;
        for (char c = 'A'; c < 'A' + NUM_SEATS; ++c) {
            Seat* newSeat = new Seat(c);
            if (!head) {
                head = newSeat;
                head->next = head; // Circular link
                head->prev = head; // Circular link
            } else {
                last->next = newSeat;
                newSeat->prev = last;
                newSeat->next = head; // Link to head
                head->prev = newSeat; // Link from head to new last
            }
            last = newSeat;
        }
    }

    // Function to display available seats
    void displayAvailableSeats() {
        Seat* current = head;
        if (!current) {
            cout << "No seats available." << endl;
            return;
        }

        cout << "Available seats: ";
        do {
            if (!current->isBooked) {
                cout << current->seatNumber << " ";
            }
            current = current->next;
        } while (current != head);
        cout << endl;
    }

    // Function to book a seat
    bool bookSeat(char seatNumber) {
        Seat* current = head;
        if (!current) return false;

        do {
            if (current->seatNumber == seatNumber && !current->isBooked) {
                current->isBooked = true;
                cout << "Seat " << seatNumber << " booked successfully." << endl;
                return true;
            }
            current = current->next;
        } while (current != head);

        cout << "Seat " << seatNumber << " is either invalid or already booked." << endl;
        return false;
    }

    // Function to cancel a booking
    bool cancelBooking(char seatNumber) {
        Seat* current = head;
        if (!current) return false;

        do {
            if (current->seatNumber == seatNumber && current->isBooked) {
                current->isBooked = false;
                cout << "Booking for seat " << seatNumber << " cancelled successfully." << endl;
                return true;
            }
            current = current->next;
        } while (current != head);

        cout << "Booking for seat " << seatNumber << " is either invalid or not booked." << endl;
        return false;
    }

    // Destructor to free memory
    ~Row() {
        if (!head) return;

        Seat* current = head;
        do {
            Seat* temp = current;
            current = current->next;
            delete temp;
        } while (current != head);
    }
};

// Class to represent the cinema hall
class CinemaHall {
private:
    Row rows[NUM_ROWS]; // Array of rows

public:
    // Function to display available seats in all rows
    void displayAvailableSeats() {
        for (int i = 0; i < NUM_ROWS; ++i) {
            cout << "Row " << i + 1 << ": ";
            rows[i].displayAvailableSeats();
        }
    }

    // Function to book a seat
    void bookSeat(int row, char seatNumber) {
        if (row < 1 || row > NUM_ROWS) {
            cout << "Invalid row number!" << endl;
            return;
        }
        rows[row - 1].bookSeat(seatNumber);
    }

    // Function to cancel a booking
    void cancelBooking(int row, char seatNumber) {
        if (row < 1 || row > NUM_ROWS) {
            cout << "Invalid row number!" << endl;
            return;
        }
        rows[row - 1].cancelBooking(seatNumber);
    }
};

int main() {
    CinemaHall cinema;
    int choice, row;
    char seatNumber;

    // Randomly book some seats to start with
    cinema.bookSeat(1, 'A');
    cinema.bookSeat(1, 'B');
    cinema.bookSeat(2, 'C');
    cinema.bookSeat(2, 'D');

    do {
        cout << "\nCinemax Ticket Booking System Menu:" << endl;
        cout << "1. Display Available Seats" << endl;
        cout << "2. Book a Seat" << endl;
        cout << "3. Cancel a Booking" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cinema.displayAvailableSeats();
                break;

            case 2:
                cout << "Enter row number (1-10): ";
                cin >> row;
                cout << "Enter seat number (A-G): ";
                cin >> seatNumber;
                cinema.bookSeat(row, seatNumber);
                break;

            case 3:
                cout << "Enter row number (1-10): ";
                cin >> row;
                cout << "Enter seat number (A-G): ";
                cin >> seatNumber;
                cinema.cancelBooking(row, seatNumber);
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
