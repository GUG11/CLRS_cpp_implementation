#pragma once
#include <cstdlib>
#include <stack>
#include "visitor.h"

enum NodeColor {RED, BLACK};

template<typename Key>
struct BSTNode {
    Key key;
    NodeColor color;
    BSTNode<Key> *left, *right, *parent;
    BSTNode(Key k, BSTNode<Key> *p = NULL, BSTNode<Key> *l = NULL, BSTNode<Key> *r = NULL, NodeColor c = BLACK): key(k), left(l), right(r), parent(p), color(c) {}
};

template<typename Key>
class BST {
protected:
    BSTNode<Key> *root;
    BSTNode<Key> *hot; // for insert

    void transplant(BSTNode<Key>* u, BSTNode<Key>* v);  // move subtree(v) to the location of u

public:
    // Constructors
    BST(BSTNode<Key>* r = NULL): root(r) {}
    // ~BST() {release(root);}
    // traverse
    void inorderTreeWalk(BSTNode<Key>* x, Visitor<Key>& visitor);
    void inorderTreeWalk(Visitor<Key>& visitor) {inorderTreeWalk(root, visitor);}
    void inorderIteratively(BSTNode<Key>* x, Visitor<Key>& visitor);
    void inorderIteratively(Visitor<Key>& visitor) {inorderIteratively(root, visitor);}
    // Accessors
    BSTNode<Key>* getRoot() {return root;}
    BSTNode<Key>* search(Key key);
    BSTNode<Key>* search(BSTNode<Key> *x, Key key);
    BSTNode<Key>* minimum() {return minimum(root);}
    BSTNode<Key>* minimum(BSTNode<Key> *subroot);
    BSTNode<Key>* maximum() {return maximum(root);}
    BSTNode<Key>* maximum(BSTNode<Key> *subroot);
    BSTNode<Key>* predecessor(BSTNode<Key>* x);
    BSTNode<Key>* successor(BSTNode<Key>* x);
    // Modifiers
    virtual BSTNode<Key>* insert(Key key);    // if return NULL, the key already exists.
    virtual BSTNode<Key>* deleteNode(Key key);  // if return NULL, the key does not exists.
    void release(BSTNode<Key>* x);
};

template<typename Key>
void BST<Key>::inorderTreeWalk(BSTNode<Key>* x, Visitor<Key>& visitor) {
    if (x) {
        inorderTreeWalk(x->left, visitor);
        visitor(x->key);
        inorderTreeWalk(x->right, visitor);
    }
}

template<typename Key>
void BST<Key>::inorderIteratively(BSTNode<Key>* x, Visitor<Key>& visitor) {
    std::stack<BSTNode<Key>*> S;
    if (x) {
        do {
            while (x) {
                S.push(x);
                x = x->left;
            }
            x = S.top(); S.pop();
            visitor(x->key);
            x = x->right;
        } while (!S.empty() || x);
    }
}

template<typename Key>
BSTNode<Key>* BST<Key>::search(BSTNode<Key> *x, Key key) {
    hot = x ? x->parent : NULL;    // always the parent of x
    while (x) {
        hot = x;
        if (x->key == key) break;
        else if (x->key < key) x = x->right;
        else x = x->left;
    }
    return x;
}

template<typename Key>
BSTNode<Key>* BST<Key>::search(Key key) {
    return search(root, key);
}

template<typename Key>
BSTNode<Key>* BST<Key>::minimum(BSTNode<Key> *subroot) {
    BSTNode<Key>* x = subroot;
    if (x) {
        while (x->left) x = x->left;
    }
    return x;
}

template<typename Key>
BSTNode<Key>* BST<Key>::maximum(BSTNode<Key> *subroot) {
    BSTNode<Key>* x = subroot;
    if (x) {
        while (x->right) x = x->right;
    }
    return x;
}

template<typename Key>
BSTNode<Key>* BST<Key>::predecessor(BSTNode<Key>* x) {
    BSTNode<Key>* prev = NULL;
    if (x->left) prev = maximum(x->left);
    else {
        prev = x->parent;
        while (prev && prev->left == x) {
            x = prev;
            prev = x->parent;
        }
    }
    return prev;
}

template<typename Key>
BSTNode<Key>* BST<Key>::successor(BSTNode<Key>* x) {
    BSTNode<Key>* succ = NULL;
    if (x->right) succ = minimum(x->right);
    else {
        succ = x->parent;
        while (succ && succ->right == x) {
            x = succ;
            succ = x->parent;
        }
    }
    return succ;
}

// Modifiers
template<typename Key>
BSTNode<Key>* BST<Key>::insert(Key key) {
    BSTNode<Key> *x = search(key), *z = NULL;
    if (!x) {
        z = new BSTNode<Key>(key, hot);
        if (!hot) root = z;
        else if (hot->key < z->key) hot->right = z;
        else hot->left = z;
    }
    return z;
}

template<typename Key>
void BST<Key>::transplant(BSTNode<Key>* u, BSTNode<Key>* v) {
    BSTNode<Key> *pa = u->parent;
    if (!pa) root = v;
    else if (pa->left == u) pa->left = v;
    else pa->right = v; 
    if (v) v->parent = pa;
}

template<typename Key>
BSTNode<Key>* BST<Key>::deleteNode(Key key) {
    BSTNode<Key>* x = search(key), *tmp = NULL;
    if (x) {
        if (!x->left) transplant(x, x->right);
        else if (!x->right) transplant(x, x->left);
        else {
            tmp = minimum(x->right);  // no left child
            if (x->right != tmp) {
                transplant(tmp, tmp->right);
                tmp->right = x->right;
                x->right->parent = tmp;
            }
            transplant(x, tmp);
            tmp->left = x->left;
            tmp->left->parent = tmp;
        }
    }
    return x;
}

template<typename Key>
void BST<Key>::release(BSTNode<Key>* x) {
    if (x) {
        release(x->left);
        release(x->right);
        if (x == root) root = NULL;
        delete x;
    }
}
