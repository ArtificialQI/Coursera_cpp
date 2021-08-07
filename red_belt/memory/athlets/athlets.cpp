#include <iostream>
#include <vector>
#include <list>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAX_COUNT = 100'000;
    vector<list<uint32_t>::iterator> index;
    list<uint32_t> sportsmens;
    index.assign(MAX_COUNT + 1, sportsmens.end());

    size_t Q;
    cin >> Q;
    for (size_t i = 0; i < Q; i++) {
        uint32_t first, second;
        cin >> first >> second;
        index[first] = sportsmens.insert(index[second], first);
    }
    for (const auto& item : sportsmens)
        cout << item << '\n';
    return 0;
}