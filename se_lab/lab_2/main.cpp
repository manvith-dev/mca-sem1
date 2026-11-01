#include <iostream>
#include <vector>
#include <regex>

struct Vehicle
{
    std::string number;
    std::string name;
    std::string type;
    int entryHour;
    int exitHour;
};

std::vector<Vehicle> vehicles;
const int chargePerHour = 50;

void lineBreaker()
{
    std::cout << "-------------------------------------------------" << std::endl;
}

std::string toLower(std::string str)
{
    for (char &c : str)
        c = static_cast<char>(tolower(c));

    return str;
}

void appendVehicle(const Vehicle &vehicle)
{
    vehicles.push_back(vehicle);
}

int validateNumber(const std::string &number)
{
    std::regex pattern("^[A-Z]{2}[0-9]{2}[A-Z]{2}[0-9]{4}$");
    if (!regex_match(number, pattern))
    {
        std::cout << "Invalid vehicle number." << std::endl;
        return -1;
    }
    return 0;
}

int validateVehicleType(const std::string &type)
{
    if (!(type == "car" || type == "bus" || type == "truck" || type == "bike"))
    {
        std::cout << "Invalid vehicle type. You entered :" << type << std::endl;
        return -1;
    }
    return 0;
}

int validateEntryTime(int entryHour)
{
    if (entryHour > 23 || entryHour < 0)
    {
        std::cout << "Invalid entry time." << std::endl;
        return -1;
    }
    return 0;
}

int validateExitTime(int entryHour, int exitHour)
{
    if (exitHour - entryHour <= 0 || exitHour > 23 || exitHour < 0)
    {
        std::cout << "Invalid exit time." << std::endl;
        return -1;
    }
    return 0;
}

int takeVehicleInput(int idx)
{
    Vehicle vehicle;

    std::cout << "Vehicle " << idx + 1 << " :" << std::endl;

    std::cout << "Vehicle number (ex.MH01WA0889):";
    std::cin >> vehicle.number;
    if (validateNumber(vehicle.number) == -1)
        return -1;

    std::cout << "Vehicle owner name :";
    std::cin >> vehicle.name;

    std::cout << "Vehicle type (car / bus / truck / bike):";
    std::cin >> vehicle.type;
    vehicle.type = toLower(vehicle.type);
    if (validateVehicleType(vehicle.type) == -1)
        return -1;

    std::cout << "Entry Hour (0 - 23):";
    std::cin >> vehicle.entryHour;
    if (validateEntryTime(vehicle.entryHour) == -1)
        return -1;

    std::cout << "Exit Hour (0 - 23):";
    std::cin >> vehicle.exitHour;
    if (validateExitTime(vehicle.entryHour, vehicle.exitHour) == -1)
        return -1;

    appendVehicle(vehicle);
    return 0;
}

void displayVehicleLog()
{
    lineBreaker();
    std::cout << "===== VEHICLE LOG =====" << std::endl;
    lineBreaker();
    if (vehicles.empty())
    {
        std::cout << "0 records in log." << std::endl;
    }

    for (Vehicle vehicle : vehicles)
    {
        lineBreaker();
        std::cout << vehicle.number << " | " << vehicle.name << " | " << vehicle.type << std::endl;
        std::cout << "Duration :" << vehicle.exitHour - vehicle.entryHour << std::endl;
        std::cout << "Fee: Rs." << (vehicle.exitHour - vehicle.entryHour) * chargePerHour << std::endl;
        lineBreaker();
    }
}

unsigned int totalTypesParked(const std::string &type)
{
    unsigned int res = 0;
    for (const Vehicle vehicle : vehicles)
    {
        if (vehicle.type == type)
        {
            res++;
        }
    }
    return res;
}

unsigned int getTotalParkingRevenue(const std::string &type)
{
    int totalParkedHours = 0;

    if (type == "car" || type == "bus" || type == "truck" || type == "bike" || type == "all")
    {
        for (const Vehicle vehicle : vehicles)
        {
            if (type == "all" || type == vehicle.type)
            {
                totalParkedHours += (vehicle.exitHour - vehicle.entryHour);
            }
        }
    }

    return totalParkedHours * chargePerHour;
}

void displayParkingInsights()
{
    lineBreaker();
    std::cout << "===== PARKING INSIGHTS =====" << std::endl;
    lineBreaker();
    std::cout << "Total vehicles parked :" << vehicles.size() << std::endl;
    std::cout << "Cars parked :" << totalTypesParked("car") << std::endl;
    std::cout << "Buses parked :" << totalTypesParked("bus") << std::endl;
    std::cout << "Trucks parked :" << totalTypesParked("truck") << std::endl;
    std::cout << "Bikes parked :" << totalTypesParked("bike") << std::endl;
    lineBreaker();
    std::cout << "Total Parking Revenue :Rs." << getTotalParkingRevenue("all") << std::endl;
    if (vehicles.empty())
    {
        std::cout << "Average Parking Fee :Rs.0" << std::endl;
    }
    else
    {
        std::cout << "Average Parking Fee :Rs." << getTotalParkingRevenue("all") / vehicles.size() << std::endl;
    }
    std::cout << "Revenue generated from parked cars :Rs." << getTotalParkingRevenue("car") << std::endl;
    std::cout << "Revenue generated from parked buses :Rs." << getTotalParkingRevenue("bus") << std::endl;
    std::cout << "Revenue generated from parked trucks :Rs." << getTotalParkingRevenue("truck") << std::endl;
    std::cout << "Revenue generated from parked bikes :Rs." << getTotalParkingRevenue("bike") << std::endl;
    lineBreaker();
}

int main()
{
    int count;
    std::cout << "Enter no. of vehicles :";
    std::cin >> count;

    int i = 0;

    while (i < count)
    {
        if (takeVehicleInput(i) == 0)
            i++;
        lineBreaker();
    }

    system("cls");

    std::cout << "===== Campus Parking/Vehicle Log System =====" << std::endl;
    displayVehicleLog();
    displayParkingInsights();

    return 0;
}