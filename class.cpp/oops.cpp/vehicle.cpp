/* 
-- Author: Shweta Rani

Problem: Design a program where the base class 'Vehicle' contains attributes like type and max speed. A derived class 'Car' adds properties like fuel type and number of doors. Another derived class 'ElectricCar' includes battery capacity and charging time. Implement a program to display details of an 'ElectricCar'.

Solution : code for implementing multilevel inheritance .
classes :
-vehicle :type,maxspeed;
-Car :fueltype,no.of doors;
-Electric car: batterycapacity,charging time;
methods: 
-display():to display the details 
*/

#include <iostream>
using namespace std;

class Vehicle {
    public:
    string type;
    int maxspeed;
    //constructor call 
    Vehicle(string t,int max_speed){ 
        type =t;
        maxspeed = max_speed;
    }
};

class Car : public Vehicle{
    public :
    string fueltype;
    int noofdoors;
    //constructor for car class
    Car(string t,int max_speed,string ft,int nd):Vehicle(t,max_speed){
        fueltype = ft;
        noofdoors = nd;
    }
};


class ElectricCar : public Car{
    public:
    int batterycapacity;
    float chargingtime;
    //constructor 
    ElectricCar(string t,int max_speed,string ft,int nd,int btc,float ct):Car(t,max_speed,ft,nd){
        batterycapacity = btc;
        chargingtime = ct;
    }
    //display method call
    void display(){
        cout << "Information of the ElectricCar:" << endl;
        cout << "Type: " << type << endl;
        cout << "Max Speed: " << maxspeed << " km/h" << endl;
        cout << "Fuel Type: " << fueltype << endl;
        cout << "Number of Doors: " << noofdoors << endl;
        cout << "Battery Capacity: " << batterycapacity << " kWh" << endl;
        cout << "Charging Time: " << chargingtime << " hours" << endl;
    }
};

int main(){
    ElectricCar ecd("SUV",180,"Electric",5,42,8.4);
    ecd.display();
    return 0;
}