#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int64_t> days(N);
    for (auto& item : days)
        cin >> item;
    int64_t sum = 0;
    for (const auto& item : days)
        sum += item;
    int64_t avg = sum / static_cast<int64_t>(days.size());
    int count = 0;
    for (const auto& item : days)
        if (item > avg)
            count++;
    cout << count << endl;
    for (size_t i = 0; i < days.size(); i++)
        if (days[i] > avg)
            cout << i << ' ';

    return 0;
}