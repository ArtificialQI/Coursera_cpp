#pragma once

#include <cstdlib>

// Реализуйте шаблон SimpleVector
template <typename T>
class SimpleVector {
public:
  SimpleVector() = default;
  explicit SimpleVector(size_t size);
  ~SimpleVector();

  T& operator[](size_t index);

  T* begin() {return data;};
  T* end() {return end_;};

  const T* begin() const {return data;};
  const T* end()  const {return end_;};

  size_t Size() const;
  size_t Capacity() const;
  void PushBack(const T& value);

private:
  T* data = nullptr;
  T* end_ = data;
  size_t size_ = 0;
  size_t capacity_ = 0;
};

template <class T>
SimpleVector<T>::SimpleVector(size_t size) {
  data = new T[size];
  end_ = data + size;
  size_ = size;
  capacity_ = size;
}

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
  if (data == nullptr) {
    data = new T[1];
    data[0] = value;
    ++size_;
    ++capacity_;
    end_ = data + size_;
  } else if (size_ == capacity_) {

    size_t new_capacity_ = 2 * capacity_;
    T* new_data = new T[new_capacity_];
    for (size_t i = 0; i < size_; ++i) {
      new_data[i] = data[i];
    }
    new_data[size_] = value;
    ++size_;
    capacity_ *= 2;
    delete[] data;
    data = new_data;
    end_ = data + size_;
  } else {
    data[size_] = value;
    ++size_;
    end_ = data + size_;
  }
}