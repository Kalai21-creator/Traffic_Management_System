#include "TrafficManagement.h"
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

void TrafficManagement::addVehicle(const Vehicle& vehicle) {
    vehicles.push_back(vehicle);
    cout << "Vehicle added successfully!\n";
}

void TrafficManagement::displayAllVehicles() const {
    if (vehicles.empty()) {
        cout << "No vehicles in the system.\n";
        return;
    }
    for (const auto& vehicle : vehicles) {
        cout << "-------------------------\n";
        vehicle.displayVehicleDetails();
    }
}

void TrafficManagement::searchVehicle(const string& vehicleNumber) const {
    auto it = find_if(vehicles.begin(), vehicles.end(), [&](const Vehicle& v) {
        return v.getVehicleNumber() == vehicleNumber;
    });

    if (it != vehicles.end()) {
        cout << "Vehicle found:\n";
        it->displayVehicleDetails();
    } else {
        cout << "Vehicle not found.\n";
    }
}

void TrafficManagement::removeVehicle(const string& vehicleNumber) {
    auto it = remove_if(vehicles.begin(), vehicles.end(), [&](const Vehicle& v) {
        return v.getVehicleNumber() == vehicleNumber;
    });

    if (it != vehicles.end()) {
        vehicles.erase(it, vehicles.end());
        cout << "Vehicle removed successfully!\n";
    } else {
        cout << "Vehicle not found.\n";
    }
}

// Save all vehicle data to a file
void TrafficManagement::saveToFile(const string& filename) const {
    ofstream file(filename);
    if (!file) {
        cout << "Error: Could not open file for saving.\n";
        return;
    }

    for (const auto& vehicle : vehicles) {
        file << vehicle.getVehicleNumber() << " "
             << vehicle.getVehicleType() << " "
             << vehicle.getEntryTime() << endl;
    }

    file.close();
    cout << "Data saved to file successfully!\n";
}

// Load all vehicle data from a file
void TrafficManagement::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Error: Could not open file for loading.\n";
        return;
    }

    vehicles.clear(); // Clear existing data
    string number, type, time;

    while (file >> number >> type >> time) {
        vehicles.emplace_back(number, type, time);
    }

    file.close();
    cout << "Data loaded from file successfully!\n";
}
