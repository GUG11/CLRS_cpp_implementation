#pragma once 
#include <iostream>
#include <vector>

// base class
template<typename T>
class Visitor { 
public:
    virtual bool operator() (T& e) = 0;
};

template<typename T>
class NilVisitor: public Visitor<T> {   // does not do anything
public:
    virtual bool operator() (T& e) {}
};

// print visitor
template<typename T>
class PrintVisitor: public Visitor<T> {
public:
    virtual bool operator() (T& e) {
        std::cout << e << ' ';
    }
};

// buffer visitor
template <typename T>
class BufferVisitor: public Visitor<T> {
public:
    std::vector<T> buf;
    virtual bool operator() (T& e) {
        buf.push_back(e);
    }
};
