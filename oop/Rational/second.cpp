#include <iostream>
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
    int numerator;
    int denominator;
};

bool operator==(const Rational& object, const Rational& other) {
    return ((object.Numerator() == other.Numerator() && object.Denominator() == other.Denominator())
        || object.Numerator() * other.Denominator() == other.Numerator() * object.Denominator());
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
int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
