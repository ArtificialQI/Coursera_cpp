#include <iostream>
#include <string>
#include <utility>
#include <map>
using namespace std;
int main()
{
    map<string, string> list;
    list["One"] = "Two";
    for (auto item : list)
        cout << item.first << " " << item.second << endl;
    return 0;
}