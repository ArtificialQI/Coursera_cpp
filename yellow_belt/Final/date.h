#pragma once
#include <string>
using namespace std;

Date ParseDate(istream& is);

class Date
{
public:
	Date(int year, int month, int day);

	int GetYear() const;
	int GetMonth() const;
	int GetDay() const;

private:
	int year, month, day;
};

bool operator <(const Date& lhs, const Date& rhs);

ostream& operator<<(ostream& stream, const Date& date);
