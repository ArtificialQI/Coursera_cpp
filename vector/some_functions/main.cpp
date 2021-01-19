#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Reverse(vector<int>& v)
{
    reverse(v.begin(), v.end());
}
vector<int> Reversed(const vector<int>& v)
{
    vector<int> tmp;
    reverse_copy(v.begin(), v.end(), back_inserter(tmp));
    return tmp;
}

int main()
{
    vector<int> v{1, 2, 3, 4, 5};
    Reverse(v);
    for(auto item: v)
    cout << item << endl;
    Reversed(v);
    return 0;
}