#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;

enum class Lang {
    DE, FR, IT
};

struct Region {
    string std_name;
    string parent_std_name;
    map<Lang, string> names;
    int64_t population;
};
bool operator<(const Region& region, const Region& other) {
    return tie(region.names, region.parent_std_name, region.population, region.std_name)
        < tie(other.names, other.parent_std_name, other.population, other.std_name);
}
int FindMaxRepetitionCount(const vector<Region>& regions) {
    if (regions.empty())
        return 0;
    map<Region, int> index;
    for (const auto& item : regions)
        ++index[item];
    return max_element(index.begin(), index.end(), [](auto lhs, auto rhs) {return lhs.second < rhs.second; })->second;
}

int main() {
    cout << FindMaxRepetitionCount({
        {
            "Moscow",
            "Russia",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
            89
        }, {
            "Russia",
            "Eurasia",
            {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
            89
        }, {
            "Moscow",
            "Russia",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
            89
        }, {
            "Moscow",
            "Russia",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
            89
        }, {
            "Russia",
            "Eurasia",
            {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
            89
        },
        }) << endl;

    cout << FindMaxRepetitionCount({
        
        }) << endl;

    return 0;
}
