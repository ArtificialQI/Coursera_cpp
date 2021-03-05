#include <iostream>
#include <utility>
#include <map>
#include <stdexcept>
#include <exception>
using namespace std;

template<class K, class V>
V& GetRefStrict(map<K, V>& m, K k) {
    if (m.count(k) > 0)
        return m[k];
    throw runtime_error("runtime");
}

int main() {
map<int, string> m = {{0, "value"}};
string& item = GetRefStrict(m, 0);
item = "newvalue";
cout << m[0] << endl; // выведет newvalue
    return 0;
}