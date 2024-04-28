#include <iostream>
using namespace std;

template <typename T>
class Iterator {
private:
    T* ptr;

public:
    Iterator(T* p) : ptr(p) {}

    T& operator*() const {
        return *ptr;
    }

    Iterator& operator++() {
        ++ptr;
        return *this;
    }

    Iterator operator++(int) {
        Iterator tmp = *this;
        ++ptr;
        return tmp;
    }

    bool operator!=(const Iterator& other) const {
        return ptr != other.ptr;
    }
};

template <typename T, int size>
class Array {
private:
    T arr[size];

public:
    Array() {}

    T& operator[](int index) {
        return arr[index];
    }

    Iterator<T> begin() {
        return Iterator<T>(arr);
    }

    Iterator<T> end() {
        return Iterator<T>(arr + size);
    }
};

int main() {
    Array<int, 5> arr;

    for (int i = 0; i < 5; ++i) {
        arr[i] = i * 2;
    }

    cout << "Array elements: ";
    for (Iterator<int> it = arr.begin(); it != arr.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
