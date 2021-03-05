#include <iostream>
#include <vector>
using namespace std;

int main() {

    int N;
    int16_t R;
    cin >> N >> R;
    vector<uint64_t> blocks(N);
    for (auto& item: blocks) {
        int H, D;
        int64_t W;
        cin >> W >> H >> D;
        int64_t tmp = W * H;
        item = tmp * D;
    }
    uint64_t v = 0;
    for (const auto& item : blocks)
        v += item;
    cout << v * R << endl;

    return 0;
}