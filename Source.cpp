//Name: Neomi Merced
//Date: 5/25/2024
//Project One - Clock

#include <iostream>
#include <iomanip>

using namespace std;

// Define a class Time to handle time-related operations
class Time {
private:
    int hour;
    int minute;
    int second;

public:
    // Constructor to initialize the time with default values
    Time(int h = 0, int m = 0, int s = 0) : hour(h), minute(m), second(s) {}

    // Setters to update hour, minute, and second
    void setHour(int h) { hour = h; }
    void setMinute(int m) { minute = m; }
    void setSecond(int s) { second = s; }

    // Display the time in both 12-hour and 24-hour formats
    void displayTime() {
        string period = (hour < 12) ? "AM" : "PM"; // Determine AM/PM
        int displayHour = (hour == 0 || hour == 12) ? 12 : hour % 12; // Convert to 12-hour format

        // Display in 12-hour format
        cout << "\n12-Hour Format: " << setw(2) << setfill('0') << displayHour << ":" << setw(2) << setfill('0') << minute << ":" << setw(2) << setfill('0') << second << " " << period;
        // Display in 24-hour format
        cout << "\n24-Hour Format: " << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minute << ":" << setw(2) << setfill('0') << second << endl;
    }

    // Increment hour by 1, ensuring it stays within 0-23 range
    void addHour() {
        hour = (hour + 1) % 24;
    }

    // Increment minute by 1, resetting to 0 and incrementing hour if it reaches 60
    void addMinute() {
        minute = (minute + 1) % 60;
        if (minute == 0) {
            addHour(); // Call addHour if minute reaches 60
        }
    }

    // Increment second by 1, resetting to 0 and incrementing minute if it reaches 60
    void addSecond() {
        second = (second + 1) % 60;
        if (second == 0) {
            addMinute(); // Call addMinute if second reaches 60
        }
    }
};

int main() {
    int initialHour, initialMinute, initialSecond;
    char choice;

    // Get initial time input from the user
    cout << "Enter initial time in 24-hour format (HH MM SS): ";
    cin >> initialHour >> initialMinute >> initialSecond;

    // Create a Time object with the initial time
    Time time(initialHour, initialMinute, initialSecond);

    do {
        // Display menu options
        cout << "\nMenu:\n";
        cout << "1. Add an hour\n";
        cout << "2. Add a minute\n";
        cout << "3. Add a second\n";
        cout << "4. Display Time\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Perform actions based on user choice
        switch (choice) {
        case '1':
            time.addHour(); // Increment hour
            break;
        case '2':
            time.addMinute(); // Increment minute
            break;
        case '3':
            time.addSecond(); // Increment second
            break;
        case '4':
            time.displayTime(); // Display the time in both formats
            break;
        case '5':
            cout << "Exiting...\n"; // Exit the program
            break;
        default:
            cout << "Invalid choice. Please try again.\n"; // Handle invalid input
        }
    } while (choice != '5'); // Repeat until user chooses to exit

    return 0;
}
