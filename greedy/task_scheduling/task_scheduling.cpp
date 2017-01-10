#include "task_scheduling.h"
#include <algorithm>
#include <set>

bool independent(const std::vector<int>& count) {
    bool res = true;
    for (int t = 0; t < int(count.size()); t++) {
        if (count[t] > t) {
            res = false;
            break;
        }
    }
    return res;
}

/**
 * t starts at 0
 * deadline d[i] means the task must be latest scheduled at d[i]-1 and processed over [d[i]-1,d[i])
 * */
int schedule(std::vector<std::pair<int, int>>& tasks, std::vector<int>& schd) {
    int n = tasks.size();
    std::vector<int> count(n + 1, 0), selected, rejected, io2s(n), is2o(n);
    std::vector<std::pair<int, int>> tasksSorted(n);
    std::iota(io2s.begin(), io2s.end(), 0);
    int penalty = 0;
    std::sort(io2s.begin(), io2s.end(), [&tasks](const int i, const int j){return tasks[i].second > tasks[j].second;});
    for (int i = 0; i < n; i++) {
        tasksSorted[i] = tasks[io2s[i]];
        is2o[io2s[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        std::pair<int, int> task = tasksSorted[i];
        for (int t = task.first; t < n; t++) count[t]++;
        if (independent(count)) selected.push_back(is2o[i]);
        else {
            for (int t = task.first; t < n; t++) count[t]--;
            penalty += task.second;
            rejected.push_back(is2o[i]);
        }
    }

    // reconstruc the optimal schedule
    std::sort(selected.begin(), selected.end(), [&tasks](const int i, const int j){return tasks[i].first < tasks[j].first;});
    std::sort(rejected.begin(), rejected.end(), [&tasks](const int i, const int j){return tasks[i].first < tasks[j].first;});
    schd.assign(selected.begin(), selected.end());
    schd.insert(schd.end(), rejected.begin(), rejected.end());
    return penalty;
}
