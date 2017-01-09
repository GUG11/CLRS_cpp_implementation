#include "huffman.h"
#include <cxxtest/TestSuite.h>
#include <algorithm>

class TestHuffman : public CxxTest::TestSuite {
public:
    void test_count1() {
        std::string text;
        text = constructStr({{'a',1000}, {'b',1}, {'c',500}, {'l',1250}, {'x',800}});
        
        std::unordered_map<char, int> freqTable = count(text);
        TS_ASSERT_EQUALS(freqTable.size(), 5);
        TS_ASSERT_EQUALS(freqTable['a'], 1000);
        TS_ASSERT_EQUALS(freqTable['b'], 1);
        TS_ASSERT_EQUALS(freqTable['c'], 500);
        TS_ASSERT_EQUALS(freqTable['l'], 1250);
        TS_ASSERT_EQUALS(freqTable['x'], 800);
    }

    void test_count2() { // Textbook
        std::string text = constructStr({{'a',45000}, {'b',13000}, {'c',12000}, {'d',16000}, {'e',9000}, {'f',5000}});
        std::unordered_map<char, int> freqTable = count(text);
        TS_ASSERT_EQUALS(freqTable.size(), 6);
        TS_ASSERT_EQUALS(freqTable['a'], 45000);
        TS_ASSERT_EQUALS(freqTable['b'], 13000);
        TS_ASSERT_EQUALS(freqTable['c'], 12000);
        TS_ASSERT_EQUALS(freqTable['d'], 16000);
        TS_ASSERT_EQUALS(freqTable['e'], 9000);
        TS_ASSERT_EQUALS(freqTable['f'], 5000);
    }

    void test_leaves1() {
        std::string text;
        text = constructStr({{'a',1000}, {'b',1}, {'c',500}, {'l',1250}, {'x',800}});
        
        std::unordered_map<char, int> freqTable = count(text);
        std::unordered_set<HuffmanNode*> C = genLeaves(freqTable);

        TS_ASSERT_EQUALS(C.size(), 5);
        for (auto ptr: C) {
            TS_ASSERT(ptr);
            TS_ASSERT_EQUALS(freqTable[ptr->ch], ptr->freq);
        }
    }

    void test_leaves2() {
        std::string text;
        text = constructStr({{'a',45000}, {'b',13000}, {'c',12000}, {'d',16000}, {'e',9000}, {'f',5000}});
        
        std::unordered_map<char, int> freqTable = count(text);
        std::unordered_set<HuffmanNode*> C = genLeaves(freqTable);

        TS_ASSERT_EQUALS(C.size(), 6);
        for (auto ptr: C) {
            TS_ASSERT(ptr);
            TS_ASSERT_EQUALS(freqTable[ptr->ch], ptr->freq);
        }
    }

    /**
     *                          3551
     *                     /            \
     *                 1301              2250
     *               /      \          /        \
     *             501     x:800    a:1000   l:1250
     *            /   \     01       10        11
     *          b:1   c:500
     *          000   001
     * */
    void test_huffman_tree1() {
        std::string text;
        text = constructStr({{'a',1000}, {'b',1}, {'c',500}, {'l',1250}, {'x',800}});
        
        std::unordered_map<char, int> freqTable = count(text);
        std::unordered_set<HuffmanNode*> C = genLeaves(freqTable);
        HuffmanNode* root = construct(C);
        TS_ASSERT(root); 
        TS_ASSERT_EQUALS(root->ch, '\0');
        TS_ASSERT_EQUALS(root->freq, 3551);
        TS_ASSERT(root->left);
        TS_ASSERT_EQUALS(root->left->ch, '\0');
        TS_ASSERT_EQUALS(root->left->freq, 1301);
        TS_ASSERT(root->right);
        TS_ASSERT_EQUALS(root->right->ch, '\0');
        TS_ASSERT_EQUALS(root->right->freq, 2250);
        TS_ASSERT(root->left->left);
        TS_ASSERT_EQUALS(root->left->left->ch, '\0');
        TS_ASSERT_EQUALS(root->left->left->freq, 501);
        TS_ASSERT(root->left->right);
        TS_ASSERT_EQUALS(root->left->right->ch, 'x');
        TS_ASSERT_EQUALS(root->left->right->freq, 800);
        TS_ASSERT(root->right->left);
        TS_ASSERT_EQUALS(root->right->left->ch, 'a');
        TS_ASSERT_EQUALS(root->right->left->freq, 1000);
        TS_ASSERT(root->right->right);
        TS_ASSERT_EQUALS(root->right->right->ch, 'l');
        TS_ASSERT_EQUALS(root->right->right->freq, 1250);
        TS_ASSERT(root->left->left->left);
        TS_ASSERT_EQUALS(root->left->left->left->ch, 'b');
        TS_ASSERT_EQUALS(root->left->left->left->freq, 1);
        TS_ASSERT(root->left->left->right);
        TS_ASSERT_EQUALS(root->left->left->right->ch, 'c');
        TS_ASSERT_EQUALS(root->left->left->right->freq, 500);
    }
    
    /**
     *           100000
     *      /             \
     * a:45000           55000
     *           /                 \
     *       25000                 30000
     *     /       \             /        \
     * c:12000   b:13000      14000      d:16000
     *                      /       \
     *                   f:5000  e:9000
     * */
    void test_huffman_tree2() {
        std::string text;
        text = constructStr({{'a',45000}, {'b',13000}, {'c',12000}, {'d',16000}, {'e',9000}, {'f',5000}});
        
        std::unordered_map<char, int> freqTable = count(text);
        std::unordered_set<HuffmanNode*> C = genLeaves(freqTable);
        HuffmanNode* root = construct(C);
        TS_ASSERT_EQUALS(root->left->ch, 'a');
        TS_ASSERT_EQUALS(root->left->freq, 45000);
        TS_ASSERT_EQUALS(root->right->left->left->ch, 'c');
        TS_ASSERT_EQUALS(root->right->left->left->freq, 12000);
        TS_ASSERT_EQUALS(root->right->left->right->ch, 'b');
        TS_ASSERT_EQUALS(root->right->left->right->freq, 13000);
        TS_ASSERT_EQUALS(root->right->right->left->left->ch, 'f');
        TS_ASSERT_EQUALS(root->right->right->left->left->freq, 5000);
        TS_ASSERT_EQUALS(root->right->right->left->right->ch, 'e');
        TS_ASSERT_EQUALS(root->right->right->left->right->freq, 9000);
        TS_ASSERT_EQUALS(root->right->right->right->ch, 'd');
        TS_ASSERT_EQUALS(root->right->right->right->freq, 16000);
    }

    void test_encode_table1() {
        std::string text;
        std::unordered_map<char, std::string> tEnc;
        text = constructStr({{'a',1000}, {'b',1}, {'c',500}, {'l',1250}, {'x',800}});
        
        std::unordered_map<char, int> freqTable = count(text);
        std::unordered_set<HuffmanNode*> C = genLeaves(freqTable);
        HuffmanNode* root = construct(C);
        generateTable(root, tEnc);
        TS_ASSERT_EQUALS(tEnc.size(), 5);
        TS_ASSERT_EQUALS(tEnc['x'], "01");
        TS_ASSERT_EQUALS(tEnc['a'], "10");
        TS_ASSERT_EQUALS(tEnc['l'], "11");
        TS_ASSERT_EQUALS(tEnc['b'], "000");
        TS_ASSERT_EQUALS(tEnc['c'], "001");
    }

    void test_encode_table2() {
        std::string text;
        std::unordered_map<char, std::string> tEnc;
        text = constructStr({{'a',45000}, {'b',13000}, {'c',12000}, {'d',16000}, {'e',9000}, {'f',5000}});
        
        std::unordered_map<char, int> freqTable = count(text);
        std::unordered_set<HuffmanNode*> C = genLeaves(freqTable);
        HuffmanNode* root = construct(C);
        generateTable(root, tEnc);
        TS_ASSERT_EQUALS(tEnc.size(), 6);
        TS_ASSERT_EQUALS(tEnc['a'], "0");
        TS_ASSERT_EQUALS(tEnc['b'], "101");
        TS_ASSERT_EQUALS(tEnc['c'], "100");
        TS_ASSERT_EQUALS(tEnc['d'], "111");
        TS_ASSERT_EQUALS(tEnc['e'], "1101");
        TS_ASSERT_EQUALS(tEnc['f'], "1100");
    }

    void test_encode_decode() {
        std::string text, decText;
        std::unordered_map<char, std::string> tEnc;
        text = constructStr({{'a',45000}, {'b',13000}, {'c',12000}, {'d',16000}, {'e',9000}, {'f',5000}});
        
        std::unordered_map<char, int> freqTable = count(text);
        std::unordered_set<HuffmanNode*> C = genLeaves(freqTable);
        HuffmanNode* root = construct(C);
        generateTable(root, tEnc);
        std::string bin = encode(tEnc, text);
        TS_ASSERT_EQUALS(bin.size(), 224000);
        decText = decode(root, bin);
        TS_ASSERT_EQUALS(decText, text);
    }

    std::string constructStr(const std::unordered_map<char, int>& freqTable) {
        std::string text;
        for (auto p: freqTable) text.append(p.second, p.first);
        std::random_shuffle(text.begin(), text.end());
        return text;
    }
};
