#pragma once

#include "bst.h"
#include <cassert>

/**
 * Red-black tree
 * properties:
 * 1. Every node is either red or black
 * 2. The root is black
 * 3. Every leaf (NIL) is black
 * 4. If a node is red, then both its children are black
 * 5. For each node, all simple paths from the node to descendant leaves contain the same number of black nodes
 * */
template<typename Key>
class RBTree : public BST<Key> {
public:
    RBTree() : BST<Key>() {}
    virtual BSTNode<Key>* insert(Key key);    // if return NULL, the key already exists.
    virtual BSTNode<Key>* deleteNode(Key key);  // if return NULL, the key does not exists.
protected:
    BSTNode<Key>* leftRotate(BSTNode<Key>* x);
    BSTNode<Key>* rightRotate(BSTNode<Key>* x);
    void insertFixup(BSTNode<Key>* z);
    void deleteFixup(BSTNode<Key>* z);
};

/**
 *    x                   y
 *  /   \               /   \
 * a     y    --->     x     c
 *      / \           / \
 *     b   c         a   b
 * case 1: x is root
 * case 2: x is not root
 * */
template<typename Key>
BSTNode<Key>* RBTree<Key>::leftRotate(BSTNode<Key>* x) {
    BSTNode<Key>* y = x->right;
    assert(y); // assume x->right is not nil
    if( (x->right = y->left) ) x->right->parent = x;
    BST<Key>::transplant(x, y);
    y->left = x;
    x->parent = y;
    return y;
}

/**
 *    y                   x
 *  /   \               /   \
 * a     x    <---     y     c
 *      / \           / \
 *     b   c         a   b
 * case 1: x is root
 * case 2: x is not root (left child or right child)
 * */
template<typename Key>
BSTNode<Key>* RBTree<Key>::rightRotate(BSTNode<Key>* x) {
    BSTNode<Key>* y = x->left;
    assert(y);
    if ((x->left = y->right)) x->left->parent = x;
    BST<Key>::transplant(x, y);
    y->right = x;
    x->parent = y;
    return y;
}


template<typename Key>
void RBTree<Key>::insertFixup(BSTNode<Key>* z) {
    BSTNode<Key> *y = NULL;
    while (z->parent && z->parent->color == RED) {   // z's parent is not the root
        if (z->parent == z->parent->parent->left) {
            y = z->parent->parent->right;   // z's uncle
            if (y->color == RED) {  // Case 1: z's uncle is red
                /**
                 * all lower letter are subtree with a black root
                 *    z = B  (right)                z = C
                 *        C(B)                       C(R)                       
                 *      /    \                     /      \
                 *     A(R)  D(R)   ---->        A(B)     D(B)
                 *    / \     / \               /  \      / \ 
                 *   a  B(R) d   e             a   B(R)  d   e
                 *     / \                        / \
                 *    b   c                      b   c
                 *
                 *
                 *    z = A (left)                 z = C
                 *        C(B)                       C(R)
                 *     /        \                  /      \
                 *    B(R)     D(R)   ----->     B(B)     D(B)
                 *   /  \     /   \             /   \    /  \
                 *  A(R) c   d    e           A(R)  c   d    e
                 * /  \                      /  \
                 *a    b                    a    b
                 * */
                z->parent->color = y->color = BLACK;
                z = z->parent->parent;
                z->color = RED;
            } else if (z == z->parent->right) {
                // Case 2: z's uncle is black and z is a right child
                /**
                 *   z = B                          z = A            
                 *     C(B)                          C(B)                   C(R)
                 *   /     \                        /   \                 /      \
                 *  A(R)    d                      B(R)  d              B(B)      d
                 * /  \               ---->       /  \         --->    /   \        --->
                 *a   B(R)                      A(R) c                A(R)  c
                 *   /  \                      /  \                  /  \       
                 *  b    c                    a    b                a    b
                 *  Case 2                      Case 3 
                 *
                 *     B(B)
                 *   /     \
                 *  A(R)   C(R)
                 * /  \   /  \
                 * a  b   c  d
                 * */
                z = z->parent;
                leftRotate(z);
            } else { // Case 3: z's uncle is black and z is a left child
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(z->parent->parent);
            }
        } else {
            y = z->parent->parent->left;   // z's uncle
            if (y->color == RED) {   // Case 1: z's uncle is red
                /**
                 *    z = D                       z = B
                 *     B(B)                        B(R)
                 *   /      \                     /    \
                 *  A(R)    C(R)   ---->        A(B)   C(B)
                 *  / \    /   \               /  \   /   \
                 *  a b   D(R)  e              a  b  D(R)  e
                 *       /  \                       / \
                 *       c  d                      c   d
                 *
                 *       z = D                    z = B
                 *        B(B)                      B(R)
                 *      /      \                   /    \
                 *    A(R)    C(R)  ---->        A(B)  C(B)
                 *    / \    /    \              /  \  /   \
                 *   a   b  c    D(R)           a    b c  D(R)
                 *              /   \                     /  \
                 *              d   e                    d    e 
                 */
                z->parent->color = y->color = BLACK;
                z = z->parent->parent;
                z->color = RED;
            } else if (z == z->parent->left) {
                // Case 2: z's uncle is black and z is a right child
                /**
                 *    z = B           z = C
                 *     A(B)           A(B)              A(R)                 B(B)
                 *    /   \          /    \             /  \                /    \
                 *   a   C(R)       a    B(R)          a   B(B)           A(R)   C(R)
                 *      /   \  -->      /    \   -->      /   \  -->     /  \    /  \
                 *     B(R)  d         b     C(R)        b   C(R)       a   b   c   d
                 *    /  \                  /  \             / \
                 *    b  c                  c  d             c d 
                 *    Case 2         Case 3
                 * */
                z = z->parent;
                rightRotate(z);
            } else { // Case 3: z's uncle is black and z is a left child
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(z->parent->parent);
            }
        }
    }
    this->root->color = BLACK;
}

template<typename Key>
void RBTree<Key>::deleteFixup(BSTNode<Key>* z) {
    BSTNode<Key> *w = NULL;
    while (z != this->root && z->color == BLACK) {
        if (z == z->parent->left) {
            w = z->parent->right;   // z's sibling
            if (w->color == RED) { // Case 1: z's sibling w is red. Prop 5 gaurantee w is not nil
                /**
                 *    z = A, w = D             w = C
                 *      B(B)                   D(B)
                 *    /      \               /      \
                 *  A(B)    D(R)           B(R)    E(B)
                 *  / \    /    \    -->  /   \    / \
                 *  a b  C(B)  E(B)     A(B) C(B)  e f
                 *       / \   / \      / \  / \
                 *       c d   e f      a b  c d 
                 * */
                w->color = BLACK;
                z->parent->color = RED;
                leftRotate(z->parent);
                w = z->parent->right;
            } 
            if ((!w->left || w->left->color == BLACK) && (!w->right || w->right->color == BLACK)) { // Case 2 : z's sibling w is black, and both of w's children are black. Case 2 can be entered from Case 1.
                /**
                 *  z = A, w = D                z = B  (the goal is make new z uncolored)
                 *       B                        B
                 *    /     \                  /     \
                 *  A(B)   D(B)              A(B)   D(R)
                 *  / \   /    \  --->       / \   /    \
                 *  a b  C(B) E(B)           a b  C(B) E(B)
                 *       / \  / \                 / \  / \
                 *       c d  e f                 c d  e f
                 * */
                w->color = RED;
                z = z->parent;
            } else if ((!w->right || w->right->color == BLACK)) { 
                // Case 3: z's sibling w is black, w's left child is red and w's right child is black
                /**
                 *   z = A, w = D                    w = C
                 *        B                            B
                 *    /       \                    /       \
                 *  A(B)     D(B)   --->         A(B)     C(B)
                 *  / \     /    \               / \      /  \
                 *  a b   C(R)  E(B)             a b     c  D(R)
                 *        / \   / \                         /  \
                 *        c d   e f                        d  E(B)
                 *                                            / \
                 *                                            e f
                 * */
                w->left->color = BLACK;
                w->color = RED;
                rightRotate(w);
                w = z->parent->right;
                // Case 4  <-- Case 3
                /**
                 *  z = A, w = D
                 *        B                         B(B)                  D
                 *    /       \                 /       \             /       \
                 *  A(B)     D(B)  -->         A(B)     D    -->     B(B)    E(B)
                 *  / \     /    \            / \      /  \         /    \   /  \
                 *  a b    C    E(R)          a b     C  E(B)      A(B)  C   e  f
                 *        / \   / \                  / \  / \     / \   / \
                 *        c d   e f                  c d  e f     a b   c d
                 * */
                w->color = z->parent->color;
                z->parent->color = w->right->color = BLACK;
                leftRotate(z->parent);
                z = this->root;
            }
        } else {
            w = z->parent->left;   // z's sibling
            if (w->color == RED) {
                // Case 1
                /**
                 *  z = E, w = B                   w = C
                 *       D(B)                     B(B)
                 *     /      \                /        \
                 *    B(R)    E(B)           A(B)      D(R)
                 *   /   \    / \  -->       / \     /      \
                 *  A(B) C(B) e f            a b    C(B)   E(B)
                 * / \   / \                       / \     / \
                 * a b   c d                       c d     e f
                 * */
                w->color = BLACK;
                z->parent->color = RED;
                rightRotate(z->parent);
                w = z->parent->left;
            } else if ((!w->right || w->right->color == BLACK) && (!w->left || w->left->color == BLACK)) { // Case 2
                /**
                 *    z = E, w = B              z = D
                 *        D                        D
                 *    /       \                /       \
                 *   B(B)    E(B)            B(R)    E(B)
                 *  /    \   / \   --->     /    \    / \
                 * A(B) C(B) e f          A(B)  C(B)  e f
                 * / \  / \               / \   / \
                 * a b  c d               a b   e f
                 * */
                w->color = RED;
                z = z->parent;
            } else if (!w->left || w->left->color == BLACK) { // Case 3
                /**
                 *    z = E, w = B              w = C
                 *        D                        D
                 *    /       \                /       \
                 *   B(B)    E(B)            C(B)    E(B)
                 *  /    \   / \   --->     /   \    / \
                 * A(B) C(R) e f          B(R)  d    e f
                 * / \  / \              /   \   
                 * a b  c d             A(B)  c
                 *                      / \
                 *                      a b
                 * */
                w->right->color = BLACK;
                w->color = RED;
                leftRotate(w);
                w = z->parent->left;
            } else { // Case 4
                /**
                 *    z = E, w = B              z = root
                 *        D                        B  
                 *    /       \                /       \
                 *   B(B)    E(B)            A(B)      D(B)
                 *  /    \   / \   --->     /  \      /    \
                 * A(R)  C   e f            a  b     C    E(B)
                 * / \  / \                         / \    / \
                 * a b  c d                         c d    e f
                 * */
                w->color = z->parent->color;
                z->parent->color = w->left->color = BLACK;
                leftRotate(z->parent);
                z = this->root;
            }
        }
    }
    if(z) z->color = BLACK;
}

template<typename Key>
BSTNode<Key>* RBTree<Key>::insert(Key key) {
    BSTNode<Key>* z = BST<Key>::insert(key);
    insertFixup(z);
    return z;
}

template<typename Key>
BSTNode<Key>* RBTree<Key>::deleteNode(Key key) {
    BSTNode<Key> *z = BST<Key>::search(key);
    BSTNode<Key> *y = z, *x = NULL;
    NodeColor yOriginalColor = y->color;
    if (!z->left) BST<Key>::transplant(z, x = z->right);
    else if (!z->right) BST<Key>::transplant(z, x = z->left);
    else {
        y = BST<Key>::minimum(z->right);
        yOriginalColor = y->color;
        x = y->right;
        if (y->parent != z) {
            BST<Key>::transplant(y, x);
            y->right = z->right;
            y->right->parent = y;
        }
        BST<Key>::transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    if (yOriginalColor == BLACK) deleteFixup(x);
    return z;
}
