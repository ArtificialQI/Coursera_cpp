#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <set>
using namespace std;

class SortedStrings
{
public:
void AddString (const string& s)
{
    uni.insert(s);
}
vector<string> GetSortedStrings()
{
    v.clear();
    for (auto item: uni)
        v.push_back(item);
    return v;
}
private:
multiset<string> uni;
vector<string> v;

};

void PrintSortedStrings(SortedStrings& strings) {
  for (const string& s : strings.GetSortedStrings()) {
    cout << s << " ";
  }
  cout << endl;
}

int main() {
  SortedStrings strings;
  
  strings.AddString("first");
  strings.AddString("third");
  strings.AddString("second");
  PrintSortedStrings(strings);
  
  strings.AddString("second");
  PrintSortedStrings(strings);

  return 0;
}