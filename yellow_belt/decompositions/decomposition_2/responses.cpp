#include "responses.h"
#include <iostream>

std::ostream& operator << (std::ostream& os, const BusesForStopResponse& r) {
  if (r.stops_to_buses.count(r.stop) == 0) {
        std::cout << "No stop" << std::endl;
      } else {
        for (const std::string& bus : r.stops_to_buses.at(r.stop)) {
          std::cout << bus << " ";
        }
        std::cout << std::endl;
      }
  return os;
}

std::ostream& operator << (std::ostream& os, const StopsForBusResponse& r) {
  if (r.buses_to_stops.count(r.bus) == 0) {
        std::cout << "No bus" << std::endl;
      } else {
        for (const std::string& stop : r.buses_to_stops.at(r.bus)) {
          std::cout << "Stop " << stop << ": ";
          if (r.stops_to_buses.at(stop).size() == 1) {
            std::cout << "no interchange";
          } else {
            for (const std::string& other_bus : r.stops_to_buses.at(stop)) {
              if (r.bus != other_bus) {
                std::cout << other_bus << " ";
              }
            }
          }
          std::cout << std::endl;
        }
      }
  return os;
}

std::ostream& operator << (std::ostream& os, const AllBusesResponse& r) {
  if (r.buses_to_stops.empty()) {
        std::cout << "No buses" << std::endl;
      } else {
        for (const auto& bus_item : r.buses_to_stops) {
          std::cout << "Bus " << bus_item.first << ": ";
          for (const std::string& stop : bus_item.second) {
            std::cout << stop << " ";
          }
          std::cout << std::endl;
        }
      }
  return os;
}