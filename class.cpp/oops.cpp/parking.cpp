//write a code for parking system using dsa (2darray)

#include <iostream>
using namespace std;

#define ROWS 5 // Number of rows in the parking lot
#define COLS 5 // Number of columns in the parking lot

class ParkingSystem {
private:
    int parkingLot[ROWS][COLS]; // 2D array representing parking spaces

public:
    ParkingSystem() {
        // Initialize parking lot with -1 (empty spaces)
        for (int i = 0; i < ROWS; i++)
            for (int j = 0; j < COLS; j++)
                parkingLot[i][j] = -1;
    }

    void parkVehicle(int id) {
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (parkingLot[i][j] == -1) { // Empty spot found
                    parkingLot[i][j] = id;
                    cout << "Vehicle " << id << " parked at [" << i << "][" << j << "]\n";
                    return;
                }
            }
        }
        cout << "Parking Lot is Full!\n";
    }

    void removeVehicle(int id) {
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (parkingLot[i][j] == id) {
                    parkingLot[i][j] = -1; // Remove vehicle
                    cout << "Vehicle " << id << " removed from [" << i << "][" << j << "]\n";
                    return;
                }
            }
        }
        cout << "Vehicle not found!\n";
    }

    void displayLot() {
        cout << "Parking Lot Status:\n";
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (parkingLot[i][j] == -1)
                    cout << "[ ] "; // Empty space
                else
                    cout << "[" << parkingLot[i][j] << "] "; // Occupied space
            }
            cout << endl;
        }
    }
};

int main() {
    ParkingSystem parking;
    parking.parkVehicle(101);
    parking.parkVehicle(102);
    parking.displayLot();
    parking.removeVehicle(101);
    parking.displayLot();
    return 0;
}