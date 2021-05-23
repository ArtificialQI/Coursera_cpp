#include <vector>
#include <iostream>
#include "test_runner.h"
using namespace std;

template <class T>
class Deque {

    public:
        Deque() = default;

        bool Empty() const {return (front.empty() && back.empty());}

        size_t Size() const {return front.size() + back.size();}

        T& operator[](size_t index) {
            if (index < front.size())
                return front.at(front.size() - index - 1);
            return back.at(index - front.size());
        }
        const T& operator[](size_t index) const {
            if (index < front.size())
                return front.at(front.size() - index - 1);
            return back.at(index - front.size());
        }
        T& At(size_t index) {
            if (index < front.size())
                return front.at(front.size() - index - 1);
            return back.at(index - front.size());
        }
        const T& At(size_t index) const {
            if (index < front.size())
                return front.at(front.size() - index - 1);
            return back.at(index - front.size());
        }
        T& Front() {
            if (!front.empty())
                return front.back();
            return back.front();
        }
        const T& Front() const {
            if (!front.empty())
                return front.back();
            return back.front();
        }
        T& Back() {
            if (!back.empty())
                return back.back();
            return front.front();
        }
        const T& Back() const {
            if (!back.empty())
                return back.back();
            return front.front();
        }

        void PushFront(const T& item) {front.push_back(item);}

        void PushBack(const T& item) {back.push_back(item);}


    private:
        vector<T> front, back;
};

int main() {
    Deque<int> dq;
    return 0;
}