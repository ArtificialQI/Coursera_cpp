#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
    ifstream input("input.txt");

    int first;
    int second;
    input >> first;
    input >> second;
    vector<int> numbers(first * second);
    for (int& item : numbers) {
        input >> item;
        input.ignore(1);
    }
    
    for (int i = 0; i < numbers.size(); ++i) {
            if ((i + 1) % second == 0) {
                cout << setw(10) << numbers[i];
                cout << endl;
            }
            else if (i != numbers.size() - 1)
                cout << setw(10) << numbers[i] << " ";
            else
                cout << setw(10) << numbers[i];
    }

    return 0;
}