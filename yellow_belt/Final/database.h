#pragma once

#include "date.h"

#include <vector>
#include <string>
#include <set>
#include <map>
#include <functional>

using namespace std;

class Database {
public:
    void Add(const Date& date, const string& event);

    bool DeleteEvent(const Date& date, const string& event);

    int DeleteDate(const Date& date);

    set<string> Find(const Date& date) const;

    void Print(ostream&) const;

    int RemoveIf(const function<bool(const Date& date, const string& event)>& predicate);
  
    vector<string> FindIf(const function<bool(const Date& date, const string& event)>& predicate) const;

    string Last(const Date& date) const;

private:
    map<Date, set<string>> storage;
    map<Date, vector<string>> data;
};