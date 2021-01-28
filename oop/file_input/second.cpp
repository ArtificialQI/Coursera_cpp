#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main ()
{
    fstream input("input.txt");
    ofstream output("output.txt");
    string line;
    if (input)
        while (getline(input, line))
            output << line << endl;
    return 0;
}