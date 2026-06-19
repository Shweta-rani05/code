/*
Program (02)-Create a time class where users may give hours, minutes and seconds or only
minutes at runtime. Provide the required constructor to support both types of inputs.
agrs - hours,minutes ,seconds
method - Class Time():normalizeTime(),display();
*/

#include <iostream>

using namespace std;

class Time {
private:
    int hours, minutes, seconds;

public:
    // Constructor when given hours, minutes, and seconds
    Time(int h, int m, int s) {
        hours = h;
        minutes = m;
        seconds = s;
        //normalizeTime(); // Adjust values if needed
    }

    // Constructor when given only minutes
    Time(int m) {
        hours = m / 60;
        minutes = m % 60;
        seconds = 0;
    }

    // Normalize time (adjust seconds/minutes if exceeding limits)
    void normalizeTime() {
        if (seconds >= 60) {
            minutes += seconds / 60;
            seconds %= 60;
        }
        if (minutes >= 60) {
            hours += minutes / 60;
            minutes %= 60;
        }
    }

    // Display formatted time
    void display() {
        cout << "Time: " << hours << "h " << minutes << "m " << seconds << "s" << endl;
    }
};

int main() {
    Time t1(2, 45, 75); // Example with hours, minutes, seconds
    Time t2(130); // Example with only minutes

    cout << "Time with (h, m, s): ";
    t1.display();

    cout << "Time with only minutes: ";
    t2.display();

    return 0;
}