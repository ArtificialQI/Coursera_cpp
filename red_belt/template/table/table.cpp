#include "test_runner.h"

using namespace std;


template <class T>
class Table {
  public:
    Table(size_t first, size_t second) {
      data.assign(first, vector<T>(second));
    }
    void Resize(size_t first, size_t second) {
      data.resize(first);
      for (auto& item : data)
        item.resize(second);
    }
    vector<T>& operator[](const size_t index) {
      return data[index];
    }
    const vector<T>& operator[](const size_t index) const {
      return data[index];
    }
      pair<size_t, size_t> Size() const {
        if (!data.empty() && !data[0].empty()) {
          return {data.size(), data[0].size()};
      }
      return  {0, 0};
    }

  private:
    size_t rows, columns = 0;
    vector<vector<T>> data;

};

void TestTable() {
  Table<int> t(1, 1);
  ASSERT_EQUAL(t.Size().first, 1u);
  ASSERT_EQUAL(t.Size().second, 1u);
  t[0][0] = 42;
  ASSERT_EQUAL(t[0][0], 42);
  t.Resize(3, 4);
  ASSERT_EQUAL(t.Size().first, 3u);
  ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestTable);
  return 0;
}
