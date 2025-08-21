#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <iterator>


class Span
{
private:
    unsigned int _n;
    std::vector<int> _data;

public:
    explicit Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();
    // add a single number to the span
    void addNumber(int value);

    // find longest and shortest Span and between all the numbers stored , if no number stored ot only one no span can be found .thus throw an exception
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

    class FullException : public std::exception {
    public:
        const char* what() const throw() { return "Span is full"; }
    };
    class NoSpanException : public std::exception {
    public:
        const char* what() const throw() { return "Not enough numbers to find a span"; }
    };




    // add numbers from an iterator range (e.g. vector.begin(), vector.end())
    template<typename InputIt>
    void addNumber(InputIt first, InputIt last) {
        while (first != last) {
            if (_data.size() >= _n)
                throw FullException();
            _data.push_back(*first++);
        }
    }
};




#endif