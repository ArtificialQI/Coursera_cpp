#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <set>

using namespace std;

class Learner {
 private:
  set<string> dict;

 public:
  int Learn(const vector<string>& words) {
    size_t count = 0;
    for (const auto& word : words) {
      if (dict.count(word) == 0) {
        dict.emplace(word);
        ++count;
      }

    }
    return count;
  }

  vector<string> KnownWords() {
    vector<string> result;
    copy(dict.begin(), dict.end(), back_inserter(result));
    return result;
  }
};

int main() {
  Learner learner;
  string line;
  while (getline(cin, line)) {
    vector<string> words;
    stringstream ss(line);
    string word;
    while (ss >> word) {
      words.push_back(word);
    }
    cout << learner.Learn(words) << "\n";
  }
  cout << "=== known words ===\n";
  for (auto word : learner.KnownWords()) {
    cout << word << "\n";
  }
}
