#include <vector>
#include <utility>
#include <algorithm>

bool cmp(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.second < b.second;
}

std::vector<int> activity_selection(std::vector<std::pair<int, int>>& intervals) {
    // intervals is sorted by the finishing time
    std::vector<int> S;
    int n = intervals.size(), i = 0;
    while (i < n) {
       if (S.empty() || intervals[S.back()].second <= intervals[i].first) {
           S.push_back(i);
       }
       i++;
    }
    return S;
}
