/**
 * CLRS 15.5 Optimal binary search trees
 * k[0] < k[1] < ... < k[n-1]
 * probability p[i] that a search will be for k[i]
 *
 * d[0], d[1], ... d[n] values not in K
 * d[0] < k[0]
 * d[i] = (k[i-1], k[i])
 * d[n] > k[n-1]
 * P(search d[i]) = q[i]
 *
 *               k[1]
 *            /        \
 *          k[0]      k[4]
 *          /  \     /      \
 *        d[0] d[1] k[3]   d[5]
 *                 /   \
 *               k[2]  d[4]
 *               /   \
 *             d[2] d[3]
 *
 * sum(p) + sum(q) = 1
 * E[cost] = \sum_{i=0}^{n-1} (depth(k[i]) + 1) * p[i] + \sum_{i=0}^n (depth(d[i]) + 1) * q[i]
 *         = 1 + \sum_{i=0}^{n-1} depth(k[i]) * p[i] + \sum_{i=0}^n depth(d[i]) * q[i] 
 *
 * any subtree containing keys (k[i:j]) and dummy keys d[i:j+1]
 *                         
 *                             k[r]
 *                      /               \
 *              k[i:r], d[i:r+1]   k[r+1:j], d[r:j+1]
 *
 * w(i,j) = \sum_{l=i}^j p[l] + \sum_{l=i}^{j+1} q[l]   0 <= i,j < n 
 * w[i][j] = w[i][j-1] + p[j-1] + q[j]
 * E[i][j] = min_{i <= r < j} (p[r] + E[i][r] + w(i,r-1) + E[r+1][j], w(r+1,j-1))  
 *         = min_{i <= r < j} w(i, j-1) + E[i][r] + E[r+1][j] if i < j
 * E[i][j] = q[i-1] if j == i
 * */

#include "optimal_bst.h"
#include <cfloat>

double optimalBST(const std::vector<double>& p, const std::vector<double>& q) {
    int n = p.size();
    std::vector<std::vector<double>> E(n+1, std::vector<double>(n+1, DBL_MAX));
    std::vector<std::vector<double>> w(n+1, std::vector<double>(n+1, 0));
    std::vector<std::vector<int>> root(n, std::vector<int>(n, 0));
    for (int i = 0; i <= n; i++) w[i][i] = E[i][i] = q[i];
    for (int len = 1; len <= n; len++) {
        for (int l = 0; l + len <= n; l++) {
            int r = l + len;
            w[l][r] = w[l][r-1] + p[r-1] + q[r];
            for (int k = l; k < r; k++) {
                double tmp = E[l][k] + E[k+1][r] + w[l][r];
                if (tmp < E[l][r]) {
                    E[l][r] = tmp;
                    root[l][r] = k;
                }
            }
        }
    }
    return E[0][n];
}
