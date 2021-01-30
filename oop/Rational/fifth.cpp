#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int gcd(int x, int y)
{
    x = abs(x);
    y = abs(y);
    while (x > 0 && y > 0)
        x > y ? x %= y : y %= x;
    return x + y;
}
class Rational {
public:
    Rational() {
        this->numerator = 0;
        this->denominator = 1;
    }

    Rational(int numerator, int denominator) {
        int divider = gcd(numerator, denominator);
        this->numerator = numerator / divider;
        this->denominator = denominator / divider;

        if (numerator * denominator < 0) {
            this->numerator = -abs(this->numerator);
            this->denominator = abs(this->denominator);
        }
        else {
            this->numerator = abs(this->numerator);
            this->denominator = abs(this->denominator);
        }
    }

    int Numerator() const {
        return numerator;
    }
    int Denominator() const {
        return denominator;
    }

private:
    int numerator;
    int denominator;
};

bool operator==(const Rational& object, const Rational& other) {
    return ((object.Numerator() == other.Numerator() && object.Denominator() == other.Denominator())
        || object.Numerator() * other.Denominator() == other.Denominator() * object.Denominator());
}

bool operator>(const Rational& object, const Rational& other) {
    return (object.Numerator() / (double)object.Denominator() > other.Numerator() / (double)other.Denominator());
}
bool operator<(const Rational& object, const Rational& other) {
    return (object.Numerator() / (double)object.Denominator() < other.Numerator() / (double)other.Denominator());
}
int main() {
    {
        const set<Rational> rs = { {1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2} };
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }
        Rational r(1, 2);
        set<Rational> sr;
        sr.insert(r);

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{ {1, 25}, { 1, 2 }, { 3, 4 }}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
