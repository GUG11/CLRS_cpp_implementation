#include "huffman.h"
#include <queue>

struct Compare {
    bool operator() (const HuffmanNode* a, const HuffmanNode* b) {
        return a->freq > b->freq;
    }
};

std::unordered_map<char, int> count(const std::string& text) {
    std::unordered_map<char, int> freqTable;
    for (char c: text) {
        if (freqTable.find(c) == freqTable.end()) freqTable[c] = 1;
        else freqTable[c]++;
    }
    return freqTable;
}

std::unordered_set<HuffmanNode*> genLeaves(const std::unordered_map<char, int>& freqTable) {
    std::unordered_set<HuffmanNode*> leaves;
    for (auto& p: freqTable) leaves.emplace(new HuffmanNode(p.first, p.second));
    return leaves;
}

HuffmanNode* construct(std::unordered_set<HuffmanNode*> C) {
    std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, Compare> PQ;
    int n = C.size();
    for (auto& e: C) PQ.push(e);
    HuffmanNode* z = NULL, *x = NULL, *y = NULL;
    for (int i = 0; i < n-1; i++) {
        x = PQ.top(); PQ.pop();
        y = PQ.top(); PQ.pop();
        z = new HuffmanNode('\0', x->freq + y->freq, x, y);
        PQ.push(z);
    }
    return PQ.top();
}

void genHelper(HuffmanNode *cur, std::string& prefix, std::unordered_map<char, std::string>& tEnc) {
    if (cur->ch != '\0') {
        tEnc.emplace(cur->ch, prefix);
    } else {
        // no need to check NULL childrens. A Huffman tree is full complete.
        prefix.push_back('0');
        genHelper(cur->left, prefix, tEnc);
        prefix.back() = '1';
        genHelper(cur->right, prefix, tEnc);
        prefix.pop_back();
    }
}

void generateTable(HuffmanNode* root, std::unordered_map<char, std::string>& tEnc) {
    std::string prefix;
    genHelper(root, prefix, tEnc);
}

std::string encode(std::unordered_map<char, std::string>& tEnc, const std::string& text) {
    std::string bin;
    for (auto& c: text) bin.append(tEnc[c]);
    return bin;
}

char decodeHelper(HuffmanNode *root, const std::string& bin, int& i) {
    if (i < 0 || int(bin.size()) <= i) return '\0';
    HuffmanNode *cur = root;
    while (cur->ch == '\0') {
        if (bin[i++] == '0') cur = cur->left;
        else cur = cur->right;
    }
    return cur->ch;
}

std::string decode(HuffmanNode *root, const std::string& bin) {
    std::string text;
    int i = 0, n = bin.size();
    while (i < n)
        text.push_back(decodeHelper(root, bin, i));
    return text;
}
