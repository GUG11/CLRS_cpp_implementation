#include "lcs.h"
#include <vector>
#include <utility>
#include <algorithm>

enum Direction {LEFT, UP, LEFTUP};
/**
 DP[i][j] = max(DP[i-1][j], DP[i-1][j-1] + s[i] == t[j], DP[i][j-1])
 * */
std::string lcs(const std::string& s, const std::string& t) {
    int m = s.length(), n = t.length(), i = 0, j = 0;
    std::string lcsStr;
    std::vector<std::vector<std::pair<int, Direction>>> DP(m+1, std::vector<std::pair<int, Direction>>(n+1, {0, LEFT}));
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (s[i] == t[j]) DP[i+1][j+1] = {DP[i][j].first + 1, LEFTUP};
            else if (DP[i][j+1].first < DP[i+1][j].first) 
                DP[i+1][j+1] = {DP[i+1][j].first, LEFT};
            else DP[i+1][j+1] = {DP[i][j+1].first, UP};
        }
    }
    i = m, j = n;
    while (0 < i && 0 < j) {
        if (DP[i][j].second == LEFTUP) {
            lcsStr.push_back(s[i-1]);
            i--; j--;
        } else if (DP[i][j].second == LEFT) j--;
        else i--;
    }
    std::reverse(lcsStr.begin(), lcsStr.end());
    return lcsStr;
}
