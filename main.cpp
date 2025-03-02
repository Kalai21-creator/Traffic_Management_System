#include <iostream>
#include "TrafficManagement.h"
using namespace std;

int main() {
    TrafficManagement trafficSystem;
    int choice;
    string number, type, time;
    const string filename = "traffic_data.txt"; // File to store data

    // Load data from file at the start
    trafficSystem.loadFromFile(filename);

    do {
        cout << "\nTraffic Management System\n";
        cout << "1. Add Vehicle\n";
        cout << "2. Display All Vehicles\n";
        cout << "3. Search Vehicle\n";
        cout << "4. Remove Vehicle\n";
        cout << "5. Save and Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter vehicle number: ";
                cin >> number;
                cout << "Enter vehicle type (Car/Bike/Truck): ";
                cin >> type;
                cout << "Enter entry time (HH:MM): ";
                cin >> time;
                trafficSystem.addVehicle(Vehicle(number, type, time));
                break;

            case 2:
                trafficSystem.displayAllVehicles();
                break;

            case 3:
                cout << "Enter vehicle number to search: ";
                cin >> number;
                trafficSystem.searchVehicle(number);
                break;

            case 4:
                cout << "Enter vehicle number to remove: ";
                cin >> number;
                trafficSystem.removeVehicle(number);
                break;

            case 5:
                trafficSystem.saveToFile(filename);
                cout << "Exiting Traffic Management System. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
