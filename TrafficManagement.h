#ifndef TRAFFICMANAGEMENT_H
#define TRAFFICMANAGEMENT_H



#include "Vehicle.h"
#include <vector>

class TrafficManagement {
private:
    std::vector<Vehicle> vehicles;

public:
    void addVehicle(const Vehicle& vehicle);
    void displayAllVehicles() const;
    void searchVehicle(const std::string& vehicleNumber) const;
    void removeVehicle(const std::string& vehicleNumber);
    void saveToFile(const std::string& filename) const;
void loadFromFile(const std::string& filename);
};

#endif // TRAFFICMANAGEMENT_H
