/*
program :create a timekeeper class that stimulate a clock.the clock should be able to :set the current time(hours and minutes) ,increment the time by a specified number of minutes ,display the time in a 12-hours format .
args:hours,minutes
method: timekeeper(),incrementTime(),displayTime()
*/

#include <iostream>

using namespace std;

class Timekeeper {
private:
    int hours;
    int minutes;

public:
    Timekeeper(int h = 0, int m = 0) : hours(h), minutes(m) {}

    void setTime(int h, int m) {
        hours = h % 24;  // Ensure valid hours (0-23)
        minutes = m % 60; // Ensure valid minutes (0-59)
    }

    void incrementTime(int min) {
        minutes += min;
        hours += minutes / 60;
        minutes %= 60;
        hours %= 24;
    }

    void displayTime() const {
        int displayHours = (hours % 12 == 0) ? 12 : hours % 12;
        string period = (hours < 12) ? "AM" : "PM";

        cout << "Current Time: ";

        // Formatting manually by ensuring double-digit display
        if (displayHours < 10) cout << "0";
        cout << displayHours << ":";

        if (minutes < 10) cout << "0";
        cout << minutes << " " << period << endl;
    }
};

int main() {
    Timekeeper clock;
    clock.setTime(14, 30);
    clock.displayTime();

    clock.incrementTime(95);
    clock.displayTime();

    return 0;
}