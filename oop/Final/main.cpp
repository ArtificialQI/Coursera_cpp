#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <set>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <exception>
using namespace std;
void check(stringstream& stream, int& value, const string& fail) {
    if (stream.peek() > 47 && stream.peek() < 58)
        stream >> value;
    else if (stream.peek() == '+') {
        stream.ignore(1);
        if (stream.peek() > 47 && stream.peek() < 58)
            stream >> value;
        else
            throw invalid_argument(fail);
    }
    else if (stream.peek() == '-') {
        stream.ignore(1);
        if (stream.peek() > 47 && stream.peek() < 58) {
            stream >> value;
            value *= -1;
        }
        else
            throw invalid_argument(fail);
    }
    else
        throw invalid_argument(fail);
}

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
    explicit Date(const string& data) {
        stringstream stream(data);
        int year, month, day;
        string fail = "Wrong date format: " + data;

        check(stream, year, fail);

        if (stream.peek() == '-')
            stream.ignore(1);
        else
            throw invalid_argument(fail);

        check(stream, month, fail);


        if (stream.peek() == '-')
            stream.ignore(1);
        else
            throw invalid_argument(fail);


        check(stream, day, fail);

        if (!stream.eof())
            throw invalid_argument(fail);

        if (stream.eof()) {
            if (month < 1 || month > 12)
                throw invalid_argument("Month value is invalid: " + to_string(month));
            else if (day < 1 || day > 31)
                throw invalid_argument("Day value is invalid: " + to_string(day));
            else {
                this->year = year;
                this->month = month;
                this->day = day;
            }
        }


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
    if (lhs.GetYear() == rhs.GetYear()) {
        if (lhs.GetMonth() == rhs.GetMonth())
            return lhs.GetDay() < rhs.GetDay();
        else
            return lhs.GetMonth() < rhs.GetMonth();
    }
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
    stream << setfill('0');
    stream << setw(4) << date.GetYear() << '-';
    stream << setw(2) << date.GetMonth() << '-';
    stream << setw(2) << date.GetDay();
    return stream;
}


class Database {
public:
    void AddEvent(const Date& date, const string& event) {
        data[date].insert(event);
    }
    void DeleteEvent(const Date& date, const string& event) {
        if (data.find(date) != data.end()) {
            if (data.at(date).find(event) != data.at(date).end()) {
                data.at(date).erase(event);
                cout << "Deleted successfully" << endl;
            }
            else cout << "Event not found" << endl;
        }
        else cout << "Event not found" << endl;
    }
    void DeleteDate(const Date& date) {
        if (data.find(date) != data.end()) {
            cout << "Deleted " + to_string(data.at(date).size()) + " events" << endl;
            data.at(date).clear();
            data.erase(date);
        }
        else cout << "Deleted 0 events" << endl;
    }

    void Find(const Date& date) const {
        if (data.find(date) != data.end())
            for (const auto item : data.at(date))
                cout << item << endl;
    }

    void Print() const {
        for (const auto item : data) {
            for (const auto i : item.second) {
                cout << item.first << ' ' << i << endl;
            }
        }
    }

private:
    map<Date, set<string>> data;
};

int main() {
    Database db;
    string command;
    while (getline(cin, command)) {
        try {
            string::iterator first = find(command.begin(), command.end(), ' ');
            string::iterator second = command.end();
            if (first != command.end())
                second = find(first + 1, command.end(), ' ');
            string operation(command.begin(), first);

            if (operation == "Add") {
                string data(first + 1, second);
                string event(second + 1, command.end());
                Date date(data);
                db.AddEvent(date, event);
            }
            else if (operation == "Del") {
                string data(first + 1, second);
                Date date(data);
                if (second != command.end()) {
                    string event(second + 1, command.end());
                    db.DeleteEvent(date, event);
                }
                else
                    db.DeleteDate(date);
            }
            else if (operation == "Find") {


                string data(first + 1, command.end());

                Date date(data);
                db.Find(date);


            }
            else if (operation == "Print") {

                db.Print();
            }
            else if (operation != "Add" && operation != "Del" && operation != "Find" && operation != "Print" && operation != "")
                cout << "Unknown command: " << operation << endl;
        }
        catch (exception& ex) {
            cout << ex.what();
            break;
        }
    }

    return 0;
}