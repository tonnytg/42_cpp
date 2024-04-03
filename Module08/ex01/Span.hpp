#ifndef __SPAN__HPP
#define __SPAN__HPP

#include <limits>
#include <iostream>
#include <exception>
#include <list>
#include <algorithm>

class Span {
 public:
  Span(unsigned int N);
  Span(const Span &span);
  ~Span();
  Span &operator=(const Span &span);

  void addNumber(int number);
  int shortestSpan();
  int longestSpan();
  void addRange(std::list<int>::iterator begin, std::list<int>::iterator end);
  void print();

  class SpanFullException : public std::exception {
   public:
    const char *what() const throw() {
      return "Span is full";
    }
  };

  class SpanEmptyException : public std::exception {
   public:
    const char *what() const throw() {
      return "Span is empty";
    }
  };

 private:
  Span();
  unsigned int N;
  std::list<int> numbers;
};

#endif
