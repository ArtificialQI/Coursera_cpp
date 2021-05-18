#include "database.h"
#include "node.h"

#include <iostream>
#include <sstream>
#include <algorithm>

void Database::Add(const Date& date, const string& event) {
    storage[date].insert(event);
    data[date].emplace_back(event);
}

bool Database::DeleteEvent(const Date& date, const string& event) {
    if (storage.count(date) > 0 && storage[date].count(event) > 0) {
        storage[date].erase(event);
        return true;
    }
    return false;
}

int Database::DeleteDate(const Date& date) {
    if (storage.count(date) == 0) {
        return 0;
    }
    else {
        const int event_count = storage[date].size();
        storage.erase(date);
        return event_count;
    }
}

set<string> Database::Find(const Date& date) const {
    if (storage.count(date) > 0) {
        return storage.at(date);
    }
    else {
        return {};
    }
}

void Database::Print(ostream& stream) const {
    for (const auto& item : storage) {
        for (const string& event : item.second) {
            stream << item.first << " " << event << endl;
        }
    }
}

int Database::RemoveIf(const function<bool(const Date& date_, const string& event_)>& predicate) {
    int count = 0;
    for (auto first = data.begin(); first != data.end();) {
        auto point = stable_partition(first->second.begin(), first->second.end(), [&](const string& item) {return !predicate(first->first, item); });

        for (const auto& item : first->second) {
            if (predicate(first->first, item)) {
                storage[first->first].erase(item);
                ++count;
            }
        }
        first->second.erase(point, first->second.end());
        if (data.at(first->first).empty()) {
            storage.erase(first->first);
            first = data.erase(first);
        }
        else
            ++first;
    }
    return count;
}

vector<string> Database::FindIf(const function<bool(const Date& date, const string& event)>& predicate) const {
    vector<string> entries;
    for (const auto& [date, events] : storage) {
        for (const auto& event : events) {
            if (predicate(date, event)) {
                ostringstream out;
                out << date;
                entries.emplace_back(out.str() + ' ' + event);
            }
        }
    }
    return entries;
}

string Database::Last(const Date& date) const {
    auto it = storage.upper_bound(date);
    if (it == storage.begin())
        throw invalid_argument("invalid_argument");
    --it;
    ostringstream out;
    out << it->first;
    return out.str() + ' ' + data.at(it->first).back();
}