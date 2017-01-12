#pragma once
#include "linkedlist.h"

template<typename T>
class Queue : public List<T> {
public:
    void push(const T& e) {List<T>::push_back(e);};
    T top() {return List<T>::front();};
    T pop() {return List<T>::pop_front();};
};
