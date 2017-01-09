#include <vector>
#include <algorithm>
#include <utility>
#include <climits>

/**
 * DP[i][j] = max_{i <= k < j} DP[i][k] + DP[k+1][j] + n_rows(i) * n_cols(k) * n_cols(j) 
 *
 * */
int matrix_chain(const std::vector<std::pair<int, int>>& matrix_sizes) {
    int n = matrix_sizes.size(), r = 0;
    std::vector<std::vector<int>> DP(n, std::vector<int>(n, INT_MAX)); 
    for (int i = 0; i < n; i++) DP[i][i] = 0;
    for (int len = 1; len < n; len++) {
        for (int l = 0; l + len < n; l++) {
            r = l + len;
            for (int k = l; k < r; k++) {
                DP[l][r] = std::min(DP[l][r], DP[l][k] + DP[k+1][r] + matrix_sizes[l].first * matrix_sizes[k].second * matrix_sizes[r].second);
            }
        }
    }
    return DP[0][n-1];
}

std::string reconstruct_solution(std::vector<std::vector<std::pair<int, int>>> DP, int l, int r) {
    std::string res, left, right;
    if (l == r) res = std::to_string(l+1);
    else if (l < r) {
        int m = DP[l][r].second;
        left = reconstruct_solution(DP, l, m);
        right = reconstruct_solution(DP, m+1, r);
        res = "(" + left + right + ")";
    }
    return res;
}

int matrix_chain(const std::vector<std::pair<int, int>>& matrix_sizes, std::string& solution) {
    int n = matrix_sizes.size(), r = 0, tmp = 0;
    std::vector<std::vector<std::pair<int, int>>> DP(n, std::vector<std::pair<int,int>>(n, {INT_MAX, -1})); 
    for (int i = 0; i < n; i++) DP[i][i].first = 0;
    for (int len = 1; len < n; len++) {
        for (int l = 0; l + len < n; l++) {
            r = l + len;
            for (int k = l; k < r; k++) {
                tmp = DP[l][k].first + DP[k+1][r].first + matrix_sizes[l].first * matrix_sizes[k].second * matrix_sizes[r].second;
                if (tmp < DP[l][r].first) {
                    DP[l][r].first = tmp;
                    DP[l][r].second = k;
                }
            }
        }
    }
    solution = reconstruct_solution(DP, 0, n-1);
    return DP[0][n-1].first;
}
