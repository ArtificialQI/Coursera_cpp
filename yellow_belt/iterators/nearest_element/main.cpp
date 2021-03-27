#include <iostream>
#include <set>
using namespace std;


std::set<int>::const_iterator FindNearestElement(const std::set <int>& st, int border) {

    if (st.empty())
        return st.end();

    auto it = st.lower_bound(border);
    auto pv = prev(it);

    if (it == st.end())
        return (--st.end());
     if (abs(border - *it) < abs(border - *pv))
        return it;
    else
        return pv;
}

int main() {
  set<int> numbers = {1, 4, 6};
  cout <<
      *FindNearestElement(numbers, 0) << " " <<
      *FindNearestElement(numbers, 3) << " " <<
      *FindNearestElement(numbers, 5) << " " <<
      *FindNearestElement(numbers, 6) << " " <<
      *FindNearestElement(numbers, 100) << endl;
      
  set<int> empty_set;
  
  cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
  return 0;
}