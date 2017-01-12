#pragma once
#include <cstdlib>

/** Doubly linked list */
template<typename T>
struct ListNode {
   T val;
   ListNode *prev, *next;
   ListNode(const T& v, ListNode<T> *p = NULL, ListNode<T> *n = NULL) : val(v), prev(p), next(n) {}
};

template<typename T>
class List {
protected:
    ListNode<T> *head, *tail;
    int n;
    ListNode<T>* insert(ListNode<T>* prev, ListNode<T>* x);
    ListNode<T>* remove(ListNode<T>* x);
public:
    List() : head(NULL), tail(NULL), n(0) {}
    ~List();
    void push_front(const T& e);
    T front() const {return head->val;}
    T pop_front();
    void push_back(const T& e);
    T back() const {return tail->val;}
    T pop_back();
    int size() const {return n;}
    bool empty() const {return n == 0;}
};

template<typename T>
List<T>::~List() {
    ListNode<T> *tmp;
    while (!empty()) {
        tmp = remove(head);
        delete tmp;
    }
}

template<typename T>
ListNode<T>* List<T>::remove(ListNode<T>* x) {
    if (!x) return NULL;
    if (x == head) {
        head = head->next;       
        if(x->next) x->next->prev = NULL;
        x->next = NULL;
        if (x == tail) tail = NULL;
    } else if (x == tail) {
        tail = tail->prev;
        x->prev->next = NULL;
        x->prev = NULL;
    } else {
        x->prev->next = x->next;
        x->next->prev = x->prev;
        x->prev = x->next = NULL;
    }
    n--;
    return x;
}

template<typename T>
ListNode<T>* List<T>::insert(ListNode<T>* prev, ListNode<T>* x) {
    if (!prev) { // first
        x->next = head;
        if (head) head->prev = x;
        x->prev = NULL;
        head = x;
        if (!tail) tail = x;
    } else if (prev == tail) {
        x->next = prev->next;
        x->prev = prev;
        prev->next = x;
        tail = x;
    } else {
        x->next = prev->next;
        x->next->prev = x;
        x->prev = prev;
        prev->next = x;
    }
    n++;
    return x;
}

template<typename T>
void List<T>::push_front(const T& e) {
    insert(NULL, new ListNode<T>(e));
}

template<typename T>
T List<T>::pop_front() {
    ListNode<T> *tmp = remove(head);
    T val = tmp->val;
    delete tmp;
    return val;
}

template<typename T>
void List<T>::push_back(const T& e) {
    insert(tail, new ListNode<T>(e));
}

template<typename T>
T List<T>::pop_back() {
    ListNode<T> *tmp = remove(tail);
    T val = tmp->val;
    delete tmp;
    return val;
}
