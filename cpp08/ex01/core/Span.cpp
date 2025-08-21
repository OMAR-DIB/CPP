#include "../includes/Span.hpp"
#include <limits>

Span::Span(unsigned int n) : _n(n) {
    _data.reserve(n);
}

Span::Span(const Span& other) : _n(other._n), _data(other._data) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _n = other._n;
        _data = other._data;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int value) {
    if (_data.size() >= _n)
        throw FullException();
    _data.push_back(value);
}

unsigned int Span::shortestSpan() const {
    if (_data.size() < 2)
        throw NoSpanException();

    std::vector<int> tmp(_data);
    std::sort(tmp.begin(), tmp.end());

    unsigned int minDiff = std::numeric_limits<unsigned int>::max();
    for (std::vector<int>::size_type i = 1; i < tmp.size(); ++i) {
        unsigned int diff = static_cast<unsigned int>(tmp[i] - tmp[i - 1]);
        if (diff < minDiff)
            minDiff = diff;
    }
    return minDiff;
}

unsigned int Span::longestSpan() const {
    if (_data.size() < 2)
        throw NoSpanException();

    std::vector<int>::const_iterator minIt = std::min_element(_data.begin(), _data.end());
    std::vector<int>::const_iterator maxIt = std::max_element(_data.begin(), _data.end());

    return static_cast<unsigned int>((*maxIt) - (*minIt));
}