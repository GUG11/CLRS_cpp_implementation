#pragma once
#include <cstdlib>
#include <string>
#include <unordered_set>
#include <unordered_map>

struct HuffmanNode {
    char ch;
    int freq;
    HuffmanNode *left, *right;
    HuffmanNode(char c, int f, HuffmanNode* l = NULL, HuffmanNode *r = NULL) : ch(c), freq(f), left(l), right(r) {}
};

std::unordered_map<char, int> count(const std::string& text);
std::unordered_set<HuffmanNode*> genLeaves(const std::unordered_map<char, int>& freqTable);
HuffmanNode* construct(std::unordered_set<HuffmanNode*> C);
void generateTable(HuffmanNode* root, std::unordered_map<char, std::string>& tEnc);
std::string encode(std::unordered_map<char, std::string>& tEnc, const std::string& text);
std::string decode(HuffmanNode* root, const std::string& bin);
