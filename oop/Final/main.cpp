#include <iostream>
#include <sstream>
#include <map>
#include <set>
using namespace std;

// –еализуйте функции и методы классов и при необходимости добавьте свои

class Date {
public:
    int GetYear() const { return year; };
    int GetMonth() const { return month; };
    int GetDay() const { return day; };
private:
    int year;
    int month;
    int day;
};

bool operator<(const Date& lhs, const Date& rhs);

class Database {
public:
    void AddEvent(const Date& date, const string& event);
    bool DeleteEvent(const Date& date, const string& event);
    int  DeleteDate(const Date& date);

    /* ??? */ //Find(const Date& date) const;

    void Print() const;
public:
    map<Date, set<string>> Data;
};

int main() {
    Database db;
    string command;
    while (getline(cin, command)) {
        // —читайте команды с потока ввода и обработайте каждую
    }

    return 0;
}