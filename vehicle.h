#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class Vehicle {
private:
    std::string vehicleNumber;
    std::string vehicleType;
    std::string entryTime;

public:
    Vehicle(std::string number, std::string type, std::string time);
    std::string getVehicleNumber() const;
    std::string getVehicleType() const;
    std::string getEntryTime() const;
    void displayVehicleDetails() const;
};

#endif // VEHICLE_H
