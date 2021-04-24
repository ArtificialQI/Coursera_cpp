#pragma once

#include "date.h"

#include <string>
#include <set>
#include <map>

using namespace std;

class Database {
public:
    void Add(const Date& date, const string& event);

    bool DeleteEvent(const Date& date, const string& event);

    int DeleteDate(const Date& date);

    set<string> Find(const Date& date) const;

    void Print(ostream&) const;

    int RemoveIf(const Date date, char pred) {
        if date/event pred  date/event
    }
private:
    map<Date, set<string>> storage;
};