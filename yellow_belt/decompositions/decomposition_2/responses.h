#pragma once
#include <map>
#include <vector>
#include <string>

struct BusesForStopResponse {
  std::map<std::string, std::vector<std::string>> stops_to_buses;
  std::string stop;
};

struct StopsForBusResponse {
  std::map<std::string, std::vector<std::string>> buses_to_stops, stops_to_buses;
  std::string bus;
};

struct AllBusesResponse {
  std::map<std::string, std::vector<std::string>> buses_to_stops;
};

std::ostream& operator << (std::ostream& os, const BusesForStopResponse& r);

std::ostream& operator << (std::ostream& os, const StopsForBusResponse& r);

std::ostream& operator << (std::ostream& os, const AllBusesResponse& r);