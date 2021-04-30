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

    template<class Function>
    int RemoveIf(Function predicate) {
        for (auto [key, value] : storage) {
            if (predicate(storage))
        }       storage.erase();
    }
private:
    map<Date, set<string>> storage;
};