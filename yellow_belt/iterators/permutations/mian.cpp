#include <algorithm>
#include <vector>
#include <iostream>
#include <numeric>
using namespace std;
int main() {
    
    int N;
    cin >> N;
    vector<int> vec(N);
    iota(vec.rbegin(), vec.rend(), 1);

  do{
      for(int num : vec)
        cout << num << ' ';
    cout << endl;
    } while (prev_permutation(vec.begin(), vec.end()));

    return 0;
}