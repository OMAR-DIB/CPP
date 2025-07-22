
#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

// # include "../core_tpp/Array.tpp"

template <typename T>
class Array {
private:
    T* arr;
    unsigned int _size;

public:
    Array() : arr(NULL), _size(0) {}

    Array(unsigned int n) : arr(new T[n]()), _size(n) {}

    Array(const Array& other) : arr(NULL), _size(0) {
        *this = other;
    }

    ~Array() {
        delete[] arr;
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] arr;

            _size = other._size;
            arr = (_size > 0) ? new T[_size]() : NULL;

            for (std::size_t i = 0; i < _size; i++) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }

    T& operator[](std::size_t index) {
        if (index >= _size) {
            throw std::out_of_range("Index out of bounds");
        }
        return arr[index];
    }

    const T& operator[](std::size_t index) const {
        if (index >= _size) {
            throw std::out_of_range("Index out of bounds");
        }
        return arr[index];
    }

    std::size_t size() const {
        return _size;
    }
};



#endif