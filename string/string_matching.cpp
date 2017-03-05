#include "string_matching.h"
#include <unordered_set>
#include <algorithm>

std::vector<int> naiveStringMatching(const std::string& T, const std::string& P) {
    int n = T.length(), m = P.length(), j = 0;
    std::vector<int> pos;
    for (int i = 0; i < n - m + 1; i++) {
        for (j = 0; j < m && T[i + j] == P[j]; j++);
        if (j == m) pos.push_back(i);
    }
    return pos;
}

std::vector<int> FAMatching(const std::string& T, const std::string& P) {
    FATable delta = computeTransitionFunction(P);
    std::vector<int> pos = FAMatching(T, P.length(), delta);
    return pos;
}

std::vector<int> FAMatching(const std::string& T, int m, FATable& delta) {
    int n = T.length(), state = 0;
    std::vector<int> pos; 
    for (int i = 0; i < n; i++) {
        state = delta[state].find(T[i]) == delta[state].end() ? 0 : delta[state][T[i]];
        if (state == m) pos.push_back(i - m + 1);
    }
    return pos;
}

/* auxiliary function */
inline bool isSuffix(const std::string& suffix, const std::string& text) {
    return suffix == text.substr(text.length() - suffix.length());  
}

/*
 * aab
 *    a   b
 * 0  1   0
 * 1  2   0
 * 2  2   3
 * 3  stop
 *
 * suffix function corresponding to P
 * \sigma(x) = max{k : P[1:k] is suffix of x} 
 * 
 * 
 * FA
 * states Q = {0,1,...,m}. start: 0, accepting: m
 * delta(q, a) = \sigma(P[1:q] + a). If not match, pick the longest matched suffix
 *
 * */
FATable computeTransitionFunction(const std::string& P) {
    int m = P.length(), k = 0;
    std::unordered_set<char> Sigma(P.begin(), P.end());
    std::string Pc;
    FATable delta(m + 1, std::unordered_map<char, int>());
    for (int i = 0; i < m + 1; i++) {  // O(m^3 * |S|) can be optimized
        for (auto& c: Sigma) {
            Pc = P.substr(0, i) + c;
            k = std::min(i + 1, m);
            while (!isSuffix(P.substr(0, k), Pc)) {
                k--;
            }
            delta[i][c] = k;
        }
    }
    return delta;
}


/**
 * prefix function for a pattern : encapsulates knowledge about how the pattern matches
 * example
 * b a c b a b a b a a b c b a b   | T
 *         a b a b a c a           | P
 *                   x
 *             a b a b a c a
 *
 * \pi[q] = max{k : k < q and P[1:k] is suffix of P[1:q]}
 *
 * a  b  a  b  a  c  a
 * -1                     k = -1
 * -1 -1                  k = -1
 * -1 -1 0                k = -1
 * -1 -1 0  1             k = 0
 * -1 -1 0  1  2          k = 1
 * -1 -1 0  1  2 -1       k = 2
 * -1 -1 0  1  2 -1  0    k = -1
 * */
std::vector<int> buildPrefixTable(const std::string& P) {
    int m = P.length(), k = -1;
    std::vector<int> pt(m, -1);
    for (int q = 1; q < m; q++) {
        while (-1 < k && P[k+1] != P[q]) {
            k = pt[k];
        }
        if (P[k+1] == P[q]) k++;
        pt[q] = k;
    }
    return pt;
}


std::vector<int> KMP(const std::string& T, const std::string& P) {
    std::vector<int> pt = buildPrefixTable(P);
    std::vector<int> pos;
    int j = -1, n = T.length(), m = P.length();
    for (int i = 0; i < n; i++) {
        while (-1 < j && T[i] != P[j + 1]) j = pt[j];
        if (T[i] == P[j + 1]) j++;
        if (j == m - 1) {
            pos.push_back(i - j);
            j = pt[j];
        }
    }
    return pos;
}


