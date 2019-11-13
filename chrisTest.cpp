#include <iostream>
#include <vector>
#include <list>

// print conatiners with signature Container<char,Allocator> to the ostream
// of choosing, which is std::cout by default
template<template<class,class>typename Container, typename Allocator>
void printContainer(const Container<char, Allocator> &container,
                             std::ostream &os= std::cout) {
  for(const auto &element : container) {
    os << element;
  }
  os << std::endl;
}

int main() {
 std::vector<char> vect{10,'c'};
 std::list<char> lst{10,'c'};
 printContainer(vect);
 printContainer(lst);
}
