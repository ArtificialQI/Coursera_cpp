#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int gcd(int x, int y)
{
    x = abs(x);
    y = abs(y);
    while (x > 0 && y > 0)
        x > y ? x %= y : y %= x;
    return x + y;
}
int lcm(int x, int y) {
    return x / gcd(x, y) * y;
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
    long long int numerator;
    long long int denominator;
};

bool operator==(const Rational& object, const Rational& other) {
    return ((object.Numerator() == other.Numerator() && object.Denominator() == other.Denominator())
        || object.Numerator() * other.Denominator() == other.Numerator() * object.Denominator());
}

ostream& operator<<(ostream& stream, const Rational object) {
    stream << object.Numerator() << '/' << object.Denominator();
    return stream;
}
istream& operator>>(istream& stream, Rational& object) {
    int numerator = -1000;
    int denominator = 0;
    char symbol;
    stream >> numerator >> symbol >> denominator;
    if (numerator == 0) {
        object = { numerator, 1 };
        return stream;
    }

    if (symbol == '/' && numerator != -1000 && denominator != 0)
        object = { numerator, denominator };
    return stream;
}

int main() {
    {

        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("");
        Rational r;
        bool correct = !(input >> r);
        if (!correct) {
            cout << "Read from empty stream works incorrectly" << endl;
            return 3;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 4;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 5;
        }
    }

    {
        istringstream input1("1*2"), input2("1/"), input3("/4");
        Rational r1, r2, r3;
        input1 >> r1;
        input2 >> r2;
        input3 >> r3;
        bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
        if (!correct) {
            cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
                << r1 << " " << r2 << " " << r3 << endl;

            return 6;
        }
    }

    cout << "OK" << endl;
    return 0;
}
