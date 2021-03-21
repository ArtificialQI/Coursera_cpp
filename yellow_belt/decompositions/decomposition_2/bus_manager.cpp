#include "bus_manager.h"

void BusManager::AddBus(const std::string& bus, const std::vector<std::string>& stops) {
    buses_to_stops[bus] = stops;
    for (const std::string& stop : stops) 
        stops_to_buses[stop].push_back(bus);
  }

  BusesForStopResponse BusManager::GetBusesForStop(const std::string& stop) const {
    BusesForStopResponse r;
    r.stops_to_buses = stops_to_buses;
    r.stop = stop;
    return r;
  }

  StopsForBusResponse BusManager::GetStopsForBus(const std::string& bus) const {
    StopsForBusResponse r;
    r.buses_to_stops = buses_to_stops;
    r.stops_to_buses = stops_to_buses;
    r.bus = bus;
    return r;
  }

  AllBusesResponse BusManager::GetAllBuses() const {
    return {buses_to_stops};
  }