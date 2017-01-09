/**
 * BST tests
 * Unit test using CxxTest
 * cxxtestgen --error-printer -o runner.cpp bst_tests.h
 * g++ -o runner runner.cpp
 * ./runner
 * */


#include <cxxtest/TestSuite.h>
#include "bst.h"
#include "visitor.h"
#include <vector>

class BSTTestSuite : public CxxTest::TestSuite {
private:
    BST<int> completeTree, emptyTree, generalTree;   
public:
    void setUp() {
        std::vector<int> A{8,4,12,2,6,10,14,1,3,5,7,9,11,13,15};       
        std::vector<int> B{8,4,12,2,6,14,3,5,15};       
        for (int e: A) completeTree.insert(e);
        for (int e: B) generalTree.insert(e);
    }

    void tearDown() {
        completeTree.release(completeTree.getRoot());
        generalTree.release(generalTree.getRoot());
    }
    /*
     *         4
     *     2      5
     *   1   3
     * */
    void testNodeConstructor(void) {
        BSTNode<int> *root = new BSTNode<int>(4);
        BSTNode<int> *ll = new BSTNode<int>(1), *lr = new BSTNode<int>(3);
        BSTNode<int> *left = new BSTNode<int>(2, root, ll, lr);
        BSTNode<int> *right = new BSTNode<int>(5, root);
        root->left = left;
        root->right = right;
        TS_ASSERT(!root->parent);
        TS_ASSERT_EQUALS(root->left, left);
        TS_ASSERT_EQUALS(root->right, right);
        TS_ASSERT_EQUALS(left->parent, root);
        TS_ASSERT_EQUALS(right->parent, root);
        TS_ASSERT_EQUALS(left->left, ll);
        TS_ASSERT_EQUALS(left->right, lr);
        TS_ASSERT(!right->left);
        TS_ASSERT(!right->right);
        delete root;
        delete left;
        delete right;
        delete ll;
        delete lr;
    }
    
    void testDefaultConstructor(void) {
        BST<int> tree;
        BSTNode<int> *root = tree.getRoot();
        TS_ASSERT(!root);
    }

    void testConstructorWithArgs(void) {
        BSTNode<int> root(4);
        BST<int> tree(&root);
        TS_ASSERT(tree.getRoot());
        TS_ASSERT_EQUALS(tree.getRoot()->key, 4);
    }

    /**
     *               8
     *         4            12
     *      2    6      10       14      
     *     1 3  5 7   9   11   13  15
     * */
    void testInorder1(void) {
        BufferVisitor<int> bv;
        completeTree.inorderTreeWalk(bv);
        TS_ASSERT_EQUALS(bv.buf.size(), 15);
        for (int i = 0; i < int(bv.buf.size()) - 1; i++) {
            TS_ASSERT(bv.buf[i] < bv.buf[i+1]);
        }
    }

    void testInorder2(void) { // null tree
        BufferVisitor<int> bv;
        emptyTree.inorderTreeWalk(bv);
        TS_ASSERT(bv.buf.empty());
    }

    /**
     *               8
     *         4            12
     *      2    6             14      
     *       3  5                 15
     * */
    void testInorder3(void) {
        BufferVisitor<int> bv;
        generalTree.inorderTreeWalk(bv);
        TS_ASSERT_EQUALS(bv.buf.size(), 9);
        for (int i = 0; i < int(bv.buf.size()) - 1; i++) {
            TS_ASSERT(bv.buf[i] < bv.buf[i+1]);
        }
    }

    void testSearch1(void) {
        BSTNode<int> *key4 = completeTree.search(4);
        BSTNode<int> *keym1 = completeTree.search(-1);
        BSTNode<int> *key8 = completeTree.search(8);
        BSTNode<int> *key13 = completeTree.search(13);
        BSTNode<int> *key16 = completeTree.search(16);
        TS_ASSERT(key4);
        TS_ASSERT_EQUALS(key4->key, 4);
        TS_ASSERT(!keym1);
        TS_ASSERT(key8);
        TS_ASSERT_EQUALS(key8->key, 8);
        TS_ASSERT(key13);
        TS_ASSERT_EQUALS(key13->key, 13);
        TS_ASSERT(!key16);
    }

    void testSearch2(void) {
        BSTNode<int> *key4 = emptyTree.search(4);
        TS_ASSERT(!key4);
    }

    void testSearch3(void) {
        BSTNode<int> *key4 = generalTree.search(4);
        BSTNode<int> *keym1 = generalTree.search(-1);
        BSTNode<int> *key8 = generalTree.search(8);
        BSTNode<int> *key13 = generalTree.search(13);
        BSTNode<int> *key16 = generalTree.search(16);
        TS_ASSERT(key4);
        TS_ASSERT_EQUALS(key4->key, 4);
        TS_ASSERT(!keym1);
        TS_ASSERT(key8);
        TS_ASSERT_EQUALS(key8->key, 8);
        TS_ASSERT(!key13);
        TS_ASSERT(!key16);
    }

    void testMimimum(void) {
        BSTNode<int> *nm1 = completeTree.minimum();
        BSTNode<int> *nm2 = emptyTree.minimum();
        BSTNode<int> *nm3 = generalTree.minimum();
        TS_ASSERT(nm1);
        TS_ASSERT_EQUALS(nm1->key, 1);
        TS_ASSERT(!nm2);
        TS_ASSERT(nm3);
        TS_ASSERT_EQUALS(nm3->key, 2);
    }

    void testMaximum(void) {
        BSTNode<int> *nm1 = completeTree.maximum();
        BSTNode<int> *nm2 = emptyTree.maximum();
        BSTNode<int> *nm3 = generalTree.maximum();
        TS_ASSERT(nm1);
        TS_ASSERT_EQUALS(nm1->key, 15);
        TS_ASSERT(!nm2);
        TS_ASSERT(nm3);
        TS_ASSERT_EQUALS(nm3->key, 15);
    }

    void testPrecedessor(void) {
        BSTNode<int> *x = completeTree.maximum();
        BSTNode<int> *prev = NULL;
        while (x) {
            prev = completeTree.predecessor(x);
            if (prev) { TS_ASSERT_EQUALS(prev->key + 1, x->key); }
            else {TS_ASSERT_EQUALS(1, x->key);}
            x = prev;
        }
    }

    void testSuccessor(void) {
        BSTNode<int> *x = completeTree.minimum();
        BSTNode<int> *succ = NULL;
        while (x) {
            succ = completeTree.successor(x);
            if (succ) { TS_ASSERT_EQUALS(succ->key - 1, x->key); }
            else {TS_ASSERT_EQUALS(15, x->key);}
            x = succ;
        }
    }

    void testDelete1(void) {
        BSTNode<int> *x = completeTree.deleteNode(11);
        TS_ASSERT(x);
        TS_ASSERT_EQUALS(x->key, 11);
        x = completeTree.search(11);
        TS_ASSERT(!x);
    }

    void testDelete2(void) {
        BSTNode<int> *x = generalTree.deleteNode(11);
        TS_ASSERT(!x);
        x = generalTree.deleteNode(12);
        TS_ASSERT(x);
        TS_ASSERT_EQUALS(x->key, 12);
        x = generalTree.search(12);
        TS_ASSERT(!x);
    }
};
