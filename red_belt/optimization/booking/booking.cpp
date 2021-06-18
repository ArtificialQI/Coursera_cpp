#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>

#include "test_runner.h"
using namespace std;


class BookingManager;

class event {
public:
    event() = default;
    explicit event(const int64_t& time, const string& name, uint32_t client, uint32_t count) :
    time_(time), hotel_name(name), client_id(client), room_count(count) {}
private:
    int64_t time_ {0};
    string hotel_name;
    uint32_t client_id {0};
    uint32_t room_count {0};
    friend BookingManager;
};

class BookingManager {
public:
    void Book(const int64_t& time, const string& hotel_name, uint32_t client_id, uint32_t room_count) {
      event event_{time, hotel_name, client_id, room_count};
      if (!events_.empty()) {
        auto first = events_.front();
        while (!(first.time_ > time - day && first.time_ <= time)) {
          hotel_to_clients[first.hotel_name].erase(first.client_id);
          hotel_to_rooms[first.hotel_name] -= first.room_count;
          events_.pop();
          if (events_.empty())
            break;
          first = events_.front();
        }
      } 
      events_.emplace(event_);
      hotel_to_clients[hotel_name].emplace(client_id);
      hotel_to_rooms[hotel_name] += room_count;
    }
    size_t Clients(const string& hotel_name) {
      if (hotel_to_clients.count(hotel_name) == 0) {
        return 0;
      }
      return hotel_to_clients[hotel_name].size();
    }
    size_t Rooms(const string& hotel_name) {
      if (hotel_to_rooms.count(hotel_name) == 0)
        return 0;
      return hotel_to_rooms[hotel_name];
    }

private:
    static const int64_t day = 86400;
    int64_t current_time_;
    queue<event> events_;
    unordered_map<string, unordered_set<uint32_t>> hotel_to_clients;
    unordered_map<string, uint32_t> hotel_to_rooms;

};

void TestManager();

int main() {
    TestManager();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    BookingManager bm;

    int query_count;
    cin >> query_count;

    for (int query_id = 0; query_id < query_count; ++query_id) {
      string query_type;
      cin >> query_type;
      string hotel_name;

      if (query_type == "BOOK") {
        int64_t time;
        uint32_t client_id, room_count;
        cin >> time >> hotel_name >> client_id >> room_count;
        bm.Book(time, hotel_name, client_id, room_count);
      } else if (query_type == "CLIENTS") {
        cin >> hotel_name;
        cout << bm.Clients(hotel_name) << '\n';
      } else if (query_type == "ROOMS") {
        cin >> hotel_name;
        cout << bm.Rooms(hotel_name) << '\n';
      }
    }

    return 0;
}

 void Test() {
	BookingManager manager;

	// Test empty bookings
	ASSERT_EQUAL(manager.Clients("mariott"), 0);
	ASSERT_EQUAL(manager.Rooms("mariott"), 0);

	manager.Book(0, "mariott", 1, 10);
	manager.Book(0, "mariott", 2, 1);
	manager.Book(0, "mariott", 3, 1);
	manager.Book(0, "mariott", 4, 1);
	manager.Book(0, "hilton", 1, 1);
	manager.Book(1, "hilton", 2, 1);

	// Test correctness
	ASSERT_EQUAL(manager.Clients("mariott"), 4);
	ASSERT_EQUAL(manager.Rooms("mariott"), 13);
	ASSERT_EQUAL(manager.Clients("hilton"), 2);
	ASSERT_EQUAL(manager.Rooms("hilton"), 2);

	// Test event past 1 day resets statics
	manager.Book(86400, "mariott", 1, 1);
	ASSERT_EQUAL(manager.Clients("mariott"), 1);
	ASSERT_EQUAL(manager.Rooms("mariott"), 1);
	ASSERT_EQUAL(manager.Clients("hilton"), 1);
	ASSERT_EQUAL(manager.Rooms("hilton"), 1);

	// Test no clients and room for the last day
	manager.Book(86401, "mariott", 5, 1);
	ASSERT_EQUAL(manager.Clients("mariott"), 2);
	ASSERT_EQUAL(manager.Rooms("mariott"), 2);
	ASSERT_EQUAL(manager.Clients("hilton"), 0);
	ASSERT_EQUAL(manager.Rooms("hilton"), 0);

	manager = BookingManager();
	manager.Book(1, "A", 1, 1);
	manager.Book(2, "A", 1, 1);
	manager.Book(3, "A", 1, 1);
	ASSERT_EQUAL(manager.Clients("A"), 1);
	ASSERT_EQUAL(manager.Rooms("A"), 3);

    // Test from example
	manager = BookingManager();
	ASSERT_EQUAL(manager.Clients("Marriott"), 0);
	ASSERT_EQUAL(manager.Rooms("Marriott"), 0);
	manager.Book(10, "FourSeasons", 1, 2);
	manager.Book(10, "Marriott", 1, 1);
	manager.Book(86409, "FourSeasons", 2, 1);
	ASSERT_EQUAL(manager.Clients("FourSeasons"), 2);
	ASSERT_EQUAL(manager.Rooms("FourSeasons"), 3);
	ASSERT_EQUAL(manager.Clients("Marriott"), 1);
	manager.Book(86410, "Marriott", 2, 10);
	ASSERT_EQUAL(manager.Rooms("FourSeasons"), 1);
	ASSERT_EQUAL(manager.Rooms("Marriott"), 10);
}


void TestManager()
{
	TestRunner tr;

	RUN_TEST(tr, Test);
} 