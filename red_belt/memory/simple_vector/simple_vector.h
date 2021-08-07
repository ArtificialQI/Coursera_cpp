#pragma once

#include <algorithm>
using namespace std;
// Реализуйте шаблон SimpleVector
template <typename T>
class SimpleVector {
public:
  SimpleVector() = default;
  explicit SimpleVector(size_t size);
  ~SimpleVector();

  T& operator[](size_t index);

  T* begin() {return data;};
  T* end() {return data + size_;};

  const T* begin() const {return data;};
  const T* end()  const {return data + size_;};

  size_t Size() const;
  size_t Capacity() const;
  void PushBack(const T& value);

private:
  T* data = nullptr;
  size_t size_ = 0;
  size_t capacity_ = 0;
};

template <typename T>
SimpleVector<T>::SimpleVector(size_t size): data(new T[size]), size(size), capacity(size) {}

template<class T>
SimpleVector<T>::~SimpleVector() {
  delete[] data;
}

template<class T>
T& SimpleVector<T>::operator[](size_t index) {
  return data[index];
}

template<class T>
size_t SimpleVector<T>::Size() const {
  return size_;
}

template<class T>
size_t SimpleVector<T>::Capacity() const {
  return capacity_;
}

template<class T>
void SimpleVector<T>::PushBack(const T& value) {
 if (size_ == capacity_) {
    auto new_cap = capacity_ == 0 ? 1 : 2 * capacity_;
    auto new_data = new T[new_cap];
    copy(begin(), end(), new_data);
    delete[] data;
    data = new_data;
    capacity_ = new_cap;
  }
  data[size_++] = value;
}