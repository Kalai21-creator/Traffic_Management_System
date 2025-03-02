#include "Vehicle.h"
#include <iostream>
using namespace std;

Vehicle::Vehicle(string number, string type, string time)
    : vehicleNumber(number), vehicleType(type), entryTime(time) {}

string Vehicle::getVehicleNumber() const {
    return vehicleNumber;
}

string Vehicle::getVehicleType() const {
    return vehicleType;
}

string Vehicle::getEntryTime() const {
    return entryTime;
}

void Vehicle::displayVehicleDetails() const {
    cout << "Vehicle Number: " << vehicleNumber << endl;
    cout << "Vehicle Type  : " << vehicleType << endl;
    cout << "Entry Time    : " << entryTime << endl;
}
