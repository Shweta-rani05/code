//Write a class ReservationSystem to manage flights and passengers.
// Implement methods to search for flights, make reservations, cancel reservations, and generate flight manifests.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Passenger {
public:
    int passengerID;
    string name;
    string seatNumber;

    Passenger(int id, string nm, string seat) : passengerID(id), name(nm), seatNumber(seat) {}
};

class Flight {
public:
    int flightID;
    string destination;
    vector<Passenger> passengers;

    Flight(int id, string dest) : flightID(id), destination(dest) {}

    void addPassenger(Passenger p) {
        passengers.push_back(p);
    }

    void removePassenger(int passengerID) {
        for (auto it = passengers.begin(); it != passengers.end(); ++it) {
            if (it->passengerID == passengerID) {
                passengers.erase(it);
                break;
            }
        }
    }

    void printManifest() {
        cout << "Flight ID: " << flightID << ", Destination: " << destination << endl;
        cout << "Passenger Manifest:" << endl;
        for (const auto& passenger : passengers) {
            cout << "Passenger ID: " << passenger.passengerID << ", Name: " << passenger.name << ", Seat Number: " << passenger.seatNumber << endl;
        }
    }
};

class ReservationSystem {
private:
    vector<Flight> flights;

public:
    void addFlight(Flight flight) {
        flights.push_back(flight);
    }

    Flight* searchFlight(int flightID) {
        for (auto& flight : flights) {
            if (flight.flightID == flightID) {
                return &flight;
            }
        }
        return nullptr;
    }

    void makeReservation(int flightID, Passenger passenger) {
        Flight* flight = searchFlight(flightID);
        if (flight) {
            flight->addPassenger(passenger);
            cout << "Reservation made successfully for Flight ID: " << flightID << endl;
        } else {
            cout << "Flight ID: " << flightID << " not found." << endl;
        }
    }

    void cancelReservation(int flightID, int passengerID) {
        Flight* flight = searchFlight(flightID);
        if (flight) {
            flight->removePassenger(passengerID);
            cout << "Reservation cancelled successfully for Passenger ID: " << passengerID << endl;
        } else {
            cout << "Flight ID: " << flightID << " not found." << endl;
        }
    }

    void generateFlightManifest(int flightID) {
        Flight* flight = searchFlight(flightID);
        if (flight) {
            flight->printManifest();
        } else {
            cout << "Flight ID: " << flightID << " not found." << endl;
        }
    }
};

int main() {
    ReservationSystem rs;

    // Adding flights
    rs.addFlight(Flight(101, "New York"));
    rs.addFlight(Flight(102, "London"));

    // Making reservations
    rs.makeReservation(101, Passenger(1, "Alice", "1A"));
    rs.makeReservation(102, Passenger(2, "Bob", "2B"));

    // Generating flight manifests
    rs.generateFlightManifest(101);
    rs.generateFlightManifest(102);

    // Canceling a reservation
    rs.cancelReservation(101, 1);

    // Generating flight manifest again
    rs.generateFlightManifest(101);

    return 0;
}
