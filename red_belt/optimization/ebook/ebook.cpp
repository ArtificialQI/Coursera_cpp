#include <iomanip>
#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class ReadingManager {
public:
  ReadingManager() {}

  void Read(int user_id, int page_count) {
    if (user_to_page.find(user_id) != user_to_page.end()) {
      page_to_user.at(user_to_page[user_id]).erase(user_id);
      if (page_to_user.at(user_to_page[user_id]).empty())
        page_to_user.erase(user_to_page[user_id]);
    }
    user_to_page[user_id] = page_count;
    page_to_user[page_count].emplace(user_id);
  }
  double Cheer(int user_id) const {
    if (user_to_page.find(user_id) == user_to_page.end()) {
      return 0;
    }
    const int user_count = GetUserCount();
    if (user_count == 1) {
      return 1;
    }
    const int page_count = user_to_page.at(user_id);
    auto position = page_to_user.find(page_count);
    auto result = 0;
    for (;position != page_to_user.end(); ++position) {
      result += position->second.size();
    }
    // По умолчанию деление целочисленное, поэтому
    // нужно привести числитель к типу double.
    // Простой способ сделать это — умножить его на 1.0.
      return (user_count - result) * 1.0 / (user_count - 1);

  }

private:
  // Статическое поле не принадлежит какому-то конкретному
  // объекту класса. По сути это глобальная переменная,
  // в данном случае константная.
  // Будь она публичной, к ней можно было бы обратиться снаружи
  // следующим образом: ReadingManager::MAX_USER_COUNT.
  static const int MAX_USER_COUNT_ = 100'000;

  unordered_map<int, int> user_to_page;
  map<int, unordered_set<int>> page_to_user;


  int GetUserCount() const {
    return user_to_page.size();
  }
};


int main() {
  // Для ускорения чтения данных отключается синхронизация
  // cin и cout с stdio,
  // а также выполняется отвязка cin от cout
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ReadingManager manager;

  int query_count;
  cin >> query_count;

  for (int query_id = 0; query_id < query_count; ++query_id) {
    string query_type;
    cin >> query_type;
    int user_id;
    cin >> user_id;

    if (query_type == "READ") {
      int page_count;
      cin >> page_count;
      manager.Read(user_id, page_count);
    } else if (query_type == "CHEER") {
      cout << setprecision(6) << manager.Cheer(user_id) << "\n";
    }
  }

  return 0;
}