#include <iostream>
#include <vector>
#include <string>
using namespace std;
void MoveStrings(vector<string>& source, vector<string>& destination)
{
    destination.reserve(source.size());
    for(auto item: source)
        destination.push_back(item);
    source.clear();
}

int main()
{
    vector<string> source{"a", "b", "c"};
    vector<string> destination{"z"};
    MoveStrings(source, destination);
    for(auto item: destination)
        cout << item << endl;
    return 0;
}