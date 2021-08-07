#include "test_runner.h"
#include <string>
#include <string_view>
#include <deque>
#include <map>

using namespace std;

 class Translator {
public:
  void Add(string_view source, string_view target);
  string_view TranslateForward(string_view source) const;
  string_view TranslateBackward(string_view target) const;
  static string_view Translate(const map<string_view, string_view>& dict, string_view word);
  void ReWrite(map<string_view, string_view>& from, map<string_view, string_view>& to,
  string_view source, string_view target);

private:
  deque<string> data;
  map<string_view, string_view> source_;
  map<string_view, string_view> target_;
};

void Translator::Add(string_view source, string_view target) {
  if (source_.find(source) == source_.end() && target_.find(target) == target_.end()) {
    auto& ptr = data.emplace_back(string(source));
    source_[ptr] = data.emplace_back(string(target));
    target_[data.back()] = ptr;
  } else if (target_.find(target) == target_.end()) {
    ReWrite(target_, source_, target, source);
  } else if (source_.find(source) == source_.end()) {
    ReWrite(source_, target_, source, target);
  }
}

string_view Translator::TranslateForward(string_view source) const {
  return Translate(source_, source);
}

string_view Translator::TranslateBackward(string_view target) const {
  return Translate(target_, target);
}

  string_view Translator::Translate(const map<string_view, string_view>& dict, string_view word) {
  if (dict.find(word) != dict.end())
    return dict.at(word);
  return {};
}

void Translator::ReWrite(map<string_view, string_view>& from, map<string_view, string_view>& to,
  string_view source, string_view target) {
  data.emplace_back(string(source));
  auto& ptr = to.find(target)->first;
  from[data.back()] = ptr;
  to[ptr] = data.back();
}


void TestSimple() {
  Translator translator;
  translator.Add(string("okno"), string("window"));
  translator.Add(string("stol"), string("table"));

  ASSERT_EQUAL(translator.TranslateForward("okno"), "window");
  ASSERT_EQUAL(translator.TranslateBackward("table"), "stol"); 
  ASSERT_EQUAL(translator.TranslateBackward("stol"), "");
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestSimple);
  return 0;
}
