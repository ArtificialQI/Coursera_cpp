#pragma once

#include <stdexcept>
using namespace std;

template <typename T, size_t N>
class StackVector {
public:
  explicit StackVector(size_t a_size = 0);

  T& operator[](size_t index);
  const T& operator[](size_t index) const;

  T* begin() {return data;};
  T* end() {return data + size;};
  const T* begin() const {return data;};
  const T* end() const {return data + size;};

  size_t Size() const;
  size_t Capacity() const;

  void PushBack(const T& value);
  T PopBack();

private:
  T data[N]; // array<T, N> data
  size_t size = 0;
};
template <class T, size_t N>
StackVector<T, N>::StackVector(size_t a_size) : size(a_size) {
  if (a_size > N)
    throw invalid_argument("inv_arg");
};

template <class T, size_t N>
T& StackVector<T, N>::operator[](size_t index) {
  return data[index];
}
template <class T, size_t N>
const T& StackVector<T, N>::operator[](size_t index) const {
  return data[index];
}
template <class T, size_t N>
size_t StackVector<T, N>::Size() const {
  return size;
}
template <class T, size_t N>
size_t StackVector<T, N>::Capacity() const {
  return N;
}
template <class T, size_t N>
void StackVector<T, N>::PushBack(const T& value) {
  if (size == N)
    throw overflow_error("over_er");
  data[size++] = value;
}
template <class T, size_t N>
T StackVector<T, N>::PopBack() {
  if (size == 0)
    throw underflow_error("under_er");
  --size;
  return data[size];
}
