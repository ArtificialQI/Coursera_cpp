#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <set>
using namespace std;

class Date {
public:
    Date() {
    this->year = 0;
    this->month = 0;
    this->day = 0;
  }
  explicit Date(int day, int month, int year) {
    this->year = year;
    this->month = month;
    this->day = day;
  }
  int GetYear() const { return year; };
  int GetMonth() const { return month; };
  int GetDay() const { return day; };

private:
  int year;
  int month;
  int day;
};

bool operator<(const Date& lhs, const Date& rhs) {
  if(lhs.GetYear() == rhs.GetYear()) 
    if (lhs.GetMonth() == rhs.GetMonth())
      return lhs.GetDay() < rhs.GetDay();
    else
      return lhs.GetMonth() < rhs.GetMonth();
  return lhs.GetYear() < rhs.GetYear();
}
istream& operator>>(istream& stream, Date& date) {
  int year, month, day;
  stream >> year;
  stream.ignore(1);
  stream >> month;
  stream.ignore(1);
  stream >> day;
  date = Date(day, month, year);
  return stream;
}
ostream& operator<<(ostream& stream, const Date& date) {
  stream << date.GetYear() << date.GetMonth() << date.GetDay() << endl;
  return stream;
}


class Database {
public:
  void AddEvent(const Date& date, const string& event) {
    data[date].insert(event);
  }
  void DeleteEvent(const Date& date, const string& event) {
    if (data[date].erase(event)) {
      data[date].erase(event);
      cout << "Deleted successfully" << endl;
    }
    else
      cout << "Event not found" << endl;
  }
  void DeleteDate(const Date& date) {
    data[date].clear();
    cout << "Deleted " << data[date].size() << " events" << endl;
  }

  void Find(const Date& date) const {
    for (const auto item : data.at(date))
      cout << item << endl;
  }
  
  void Print() const {
    for (const auto item : data) {
      cout << item.first;
      Find(item.first);
    }
  }

private:
  map<Date, set<string>> data;
};

int main() {
  Database db;
  string command;
  while (getline(cin, command)) {
    if (command == "Add") {
      string event;
      Date date;
      cin >> date;
      cin >> event;
      db.AddEvent(date, event);
    }
    else if (command == "Del") {
      string event;
      Date date;
      cin >> date;
      cin >> event;
      if (event != "")
        db.AddEvent(date, event);
      else 
        db.DeleteDate(date);
    }
    else if (command == "Find") {
      Date date;
      db.Find(date);
    }
    else if (command == "Print") {
      db.Print();
    }


  }

  return 0;
}