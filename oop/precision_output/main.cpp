#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ifstream input("input.txt");
    vector<double> values;
    string number;
    if (input)
        while (getline(input, number))
            values.push_back(stod(number));

    cout << fixed << setprecision(3);
    for (double value : values)
        cout << value << endl;
    

    return 0;
}
/* 
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    ifstream input("input.txt");

    double a;

    cout << fixed << setprecision(3);

    while (input >> a) {
        cout << a << endl;
    }

    return 0;
} */
