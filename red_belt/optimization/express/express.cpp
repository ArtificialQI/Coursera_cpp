#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <set>

#include "profile.h"
#include "test_runner.h"

using namespace std;

class RouteManager {
public:
  void AddRoute(int start, int finish) {
    reachable_lists_[start].emplace(finish);
    reachable_lists_[finish].emplace(start);
  }
  int FindNearestFinish(int start, int finish) const {
    int result = abs(start - finish);
    if (reachable_lists_.count(start) < 1) {
        return result;
    }
    const set<int>& reachable_stations = reachable_lists_.at(start);
    if (!reachable_stations.empty()) {

      auto point = reachable_stations.upper_bound(finish);
      auto value = --reachable_stations.upper_bound(finish);

      if (point == reachable_stations.begin()) 
        result = min(result, abs(finish - *point));
      else if (point == reachable_stations.end()) 
        result = min(result, abs(finish - *value));
      else if (abs(*value - finish) < abs(*point - finish)) 
        result = min(result, abs(finish - *value));
      else result = min(result, abs(finish - *point));
    }
    return result;
  }
private:
  map<int, set<int>> reachable_lists_;
};

void Test() {
  RouteManager routes;
  routes.AddRoute(1, 3);
  routes.AddRoute(1, 6);
  routes.AddRoute(1, 7);
  routes.AddRoute(1, 9);
  routes.AddRoute(1, 10);
  ASSERT_EQUAL(routes.FindNearestFinish(1, 5), 1);
}


int main() {
  TestRunner tr;
  RUN_TEST(tr, Test);

  RouteManager routes;

  int query_count;
  cin >> query_count;

  for (int query_id = 0; query_id < query_count; ++query_id) {
    string query_type;
    cin >> query_type;
    int start, finish;
    cin >> start >> finish;
    if (query_type == "ADD") {
      routes.AddRoute(start, finish);
    } else if (query_type == "GO") {
      cout << routes.FindNearestFinish(start, finish) << "\n";
    }
  }

  return 0;
}
