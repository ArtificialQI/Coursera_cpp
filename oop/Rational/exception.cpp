#include <iostream>
#include <exception>
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
            throw invalid_argument("invalid_argument");
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

Rational operator/(const Rational& object, const Rational& other) {
    if (other.Numerator() == 0)
        throw domain_error("domain_error");
    Rational result(object.Numerator() * other.Denominator(), object.Denominator() * other.Numerator());
    return result;
}

int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    }
    catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    }
    catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}
