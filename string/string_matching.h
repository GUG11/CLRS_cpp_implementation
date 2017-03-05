/**
 * Pattern P[m]
 * Text T[n]
 * finite alphabet S
 * find all valid shift s: such that T[s + j] = P[j] for 1 <= j <= m
 *
 * Algorithm    Preprocessing time   Matching time
 * Naive        0                       O((n-m+1)m)
 * Finite automation    O(m |S|)        Theta(n)
 * KMP              Theta(m)            Theta(n)
 */

#pragma once
#include <vector>
#include <string>
#include <unordered_map>

typedef std::vector<std::unordered_map<char, int>> FATable;

std::vector<int> naiveStringMatching(const std::string& T, const std::string& P);

std::vector<int> FAMatching(const std::string& T, const std::string& P);
std::vector<int> FAMatching(const std::string& T, int m, FATable& delta);
FATable computeTransitionFunction(const std::string& P);

std::vector<int> buildPrefixTable(const std::string& P);
std::vector<int> KMP(const std::string& T, const std::string& P); // Knuth-Morris-Pratt
