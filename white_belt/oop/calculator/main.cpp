#include <iostream>
#include <exception>
#include <string>
using namespace std;

long long int gcd(long long int x, long long int y)
{
    x = abs(x);
    y = abs(y);
    while (x > 0 && y > 0)
        x > y ? x %= y : y %= x;
    return x + y;
}
long long int lcm(long long int x, long long int y) {
    return x / gcd(x, y) * y;
}
class Rational {
public:
    Rational() {
        this->numerator = 0;
        this->denominator = 1;
    }

    Rational(long long int numerator, long long int denominator) {
        if (denominator == 0)
            throw invalid_argument("Invalid argument");
        long long int divider = gcd(numerator, denominator);
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

Rational  operator*(const Rational& object, const Rational& other) {
    Rational result(object.Numerator() * other.Numerator(), object.Denominator() * other.Denominator());
    return result;
}
Rational operator/(const Rational& object, const Rational& other) {
    if (other.Numerator() == 0)
        throw domain_error("Division by zero");
    Rational result(object.Numerator() * other.Denominator(), object.Denominator() * other.Numerator());
    return result;
}
Rational operator+(const Rational& object, const Rational& other) {
    int denominator = lcm(object.Denominator(), other.Denominator());
    int numerator = (denominator / object.Denominator()) * object.Numerator() + (denominator / other.Denominator()) * other.Numerator();
    Rational result(numerator, denominator);
    return result;
}
Rational operator-(const Rational& object, const Rational& other) {
    int denominator = lcm(object.Denominator(), other.Denominator());
    int numerator = (denominator / object.Denominator()) * object.Numerator() - (denominator / other.Denominator()) * other.Numerator();
    Rational result(numerator, denominator);
    return result;
}
istream& operator>>(istream& stream, Rational& object) {
    int numerator = -1000;
    int denominator = -1000;
    char symbol;
    stream >> numerator >> symbol >> denominator;
    if (numerator == 0) {
        object = { 0, 1 };
        return stream;
    }

    if (symbol == '/' && numerator != -1000 && denominator != -1000)
        object = { numerator, denominator };
    return stream;
}
ostream& operator<<(ostream& stream, const Rational object) {
    stream << object.Numerator() << '/' << object.Denominator();
    return stream;
}


int main() {
    try {
        Rational r1, r2;
        char operation;
        cin >> r1 >> operation >> r2;
        if (operation == '+')
            cout << r1 + r2 << endl;
        else if (operation == '-')
            cout << r1 - r2 << endl;
        else if (operation == '*')
            cout << r1 * r2 << endl;
        else if (operation == '/')
            cout << r1 / r2 << endl;
    }
    catch (exception& ex) {
        cout << ex.what() << endl;
    }
    return 0;
}
