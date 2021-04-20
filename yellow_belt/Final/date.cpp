#include "date.h"
#include <sstream>
#include <stdexcept>
#include <iomanip>
#include <vector>
using namespace std;

Date ParseDate(istream& is) {
    string date;
    is >> date;
    istringstream date_stream(date);
    bool ok = true;

    int year;
    ok = ok && (date_stream >> year);
    ok = ok && (date_stream.peek() == '-');
    date_stream.ignore(1);

    int month;
    ok = ok && (date_stream >> month);
    ok = ok && (date_stream.peek() == '-');
    date_stream.ignore(1);

    int day;
    ok = ok && (date_stream >> day);
    ok = ok && date_stream.eof();

    if (!ok) {
        throw std::logic_error("Wrong date format: " + date);
    }
    return Date(year, month, day);
}

Date::Date(int year, int month, int day) {
    this->year = year;
    if (month > 12 || month < 1) {
        throw std::logic_error("Month value is invalid: " + to_string(month));
    }
    this->month = month;
    if (day > 31 || day < 1) {
        throw std::logic_error("Day value is invalid: " + to_string(day));
    }
    this->day = day;
}

int Date::GetYear() const { return year; }
int Date::GetMonth() const { return month; }
int Date::GetDay() const { return day; }

bool operator<(const Date& lhs, const Date& rhs) {
    return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} <
        vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

ostream& operator<<(ostream& stream, const Date& date) {
    stream << setfill('0');
    stream << setw(4) << date.GetYear() << '-';
    stream << setw(2) << date.GetMonth() << '-';
    stream << setw(2) << date.GetDay();
    return stream;
}