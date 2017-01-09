#pragma once

#include <vector>
#include <utility>
#include <string>

std::string reconstruct_solution(std::vector<std::vector<std::pair<int, int>>> DP, int l, int r); 
int matrix_chain(const std::vector<std::pair<int, int>>& matrix_sizes);
int matrix_chain(const std::vector<std::pair<int, int>>& matrix_sizes, std::string& solution); 
