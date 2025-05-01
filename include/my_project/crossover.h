#pragma once

#include <vector>
#include <iostream>  // Needed for std::cerr

template <typename T>
int one_point_crossover(const std::vector<T>& parent1, const std::vector<T>& parent2, std::vector<T>& child1, std::vector<T>& child2);
template <typename T>
int two_point_crossover(const std::vector<T>& parent1, const std::vector<T>& parent2, std::vector<T>& child1, std::vector<T>& child2);
template <typename T>
int uniform_crossover(const std::vector<T>& parent1, const std::vector<T>& parent2, std::vector<T>& child1, std::vector<T>& child2, const float p = 0.5f);


#include "crossover.tpp"  // Include the template implementation