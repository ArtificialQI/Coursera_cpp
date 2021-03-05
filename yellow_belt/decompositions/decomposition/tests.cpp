#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query {
  QueryType type;
  string bus;
  string stop;
  vector<string> stops;
};
istream& operator >> (istream& is, Query& q) {
  string operation_code;
  is >> operation_code;
  if (operation_code == "NEW_BUS") {
    q.type = QueryType::NewBus;
    is >> q.bus;
    int stop_count;
    is >> stop_count;
    q.stops.resize(stop_count);
    for (string& stop : q.stops) {
      is >> stop;
    }
  }
  else if (operation_code == "BUSES_FOR_STOP") {
    q.type = QueryType::BusesForStop;
    is >> q.stop;
  }
  else if (operation_code == "STOPS_FOR_BUS") {
    q.type = QueryType::StopsForBus;
    is >> q.bus;
  }
  else if (operation_code == "ALL_BUSES") {
    q.type = QueryType::AllBuses;
  }
  return is;
}

struct BusesForStopResponse {
  map<string, vector<string>> stops_to_buses;
  string stop;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
  if (r.stops_to_buses.count(r.stop) == 0) {
        cout << "No stop" << endl;
      } else {
        for (const string& bus : r.stops_to_buses.at(r.stop)) {
          cout << bus << " ";
        }
        cout << endl;
      }
  return os;
}

  struct StopsForBusResponse {
  map<string, vector<string>> buses_to_stops, stops_to_buses;
  string bus;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
  if (r.buses_to_stops.count(r.bus) == 0) {
        cout << "No bus" << endl;
      } else {
        for (const string& stop : r.buses_to_stops.at(r.bus)) {
          cout << "Stop " << stop << ": ";
          if (r.stops_to_buses.at(stop).size() == 1) {
            cout << "no interchange";
          } else {
            for (const string& other_bus : r.stops_to_buses.at(stop)) {
              if (r.bus != other_bus) {
                cout << other_bus << " ";
              }
            }
          }
          cout << endl;
        }
      }
  return os;
}

struct AllBusesResponse {
  map<string, vector<string>> buses_to_stops;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
  if (r.buses_to_stops.empty()) {
        cout << "No buses" << endl;
      } else {
        for (const auto& bus_item : r.buses_to_stops) {
          cout << "Bus " << bus_item.first << ": ";
          for (const string& stop : bus_item.second) {
            cout << stop << " ";
          }
          cout << endl;
        }
      }
  return os;
}

class BusManager {
public:
  void AddBus(const string& bus, const vector<string>& stops) {
    buses_to_stops[bus] = stops;
    for (const string& stop : stops) 
        stops_to_buses[stop].push_back(bus);
  }

  BusesForStopResponse GetBusesForStop(const string& stop) const {
    return {stops_to_buses, stop};
  }

  StopsForBusResponse GetStopsForBus(const string& bus) const {
    StopsForBusResponse r;
    r.buses_to_stops = buses_to_stops;
    r.stops_to_buses = stops_to_buses;
    r.bus = bus;
    return r;
  }

  AllBusesResponse GetAllBuses() const {
    return {buses_to_stops};
  }
private:
  map<string, vector<string>> buses_to_stops, stops_to_buses;
};

int main() {
  int query_count;
  Query q;

  cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;
    switch (q.type) {
    case QueryType::NewBus:
      bm.AddBus(q.bus, q.stops);
      break;
    case QueryType::BusesForStop:
      cout << bm.GetBusesForStop(q.stop) << endl;
      break;
    case QueryType::StopsForBus:
      cout << bm.GetStopsForBus(q.bus) << endl;
      break;
    case QueryType::AllBuses:
      cout << bm.GetAllBuses() << endl;
      break;
    }
  }

  return 0;
}
