#include <iostream>
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

bool operator==(const Rational& object, const Rational& other) {
    return ((object.Numerator() == other.Numerator() && object.Denominator() == other.Denominator())
        || object.Numerator() * other.Denominator() == other.Numerator() * object.Denominator());
}
Rational  operator*(const Rational& object, const Rational& other) {
    Rational result(object.Numerator() * other.Numerator(), object.Denominator() * other.Denominator());
    return result;
}
Rational operator/(const Rational& object, const Rational& other) {
    Rational result(object.Numerator() * other.Denominator(), object.Denominator() * other.Numerator());
    return result;
}

int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}
