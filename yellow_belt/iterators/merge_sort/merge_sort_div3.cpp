#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    if (distance(range_begin, range_end) > 1) {
        vector<typename RandomIt::value_type> elements(range_begin, range_end);

        MergeSort(elements.begin(), elements.begin() + elements.size()/3);
        MergeSort(elements.begin() + elements.size()/3, elements.begin() + 2 * elements.size()/3);
        MergeSort(elements.begin() + 2 * elements.size()/3, elements.end());

        vector<typename RandomIt::value_type> temp;
        merge(elements.begin(), elements.begin() + elements.size()/3, elements.begin() + elements.size()/3, elements.begin() + 2 * elements.size()/3, back_inserter(temp));
        merge(temp.begin(), temp.end(), elements.begin() + 2 * elements.size()/3, elements.end(), range_begin);
    }
}




int main() {
  vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1, 5};
  MergeSort(begin(v), end(v));
  for (int x : v) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}