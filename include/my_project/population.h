#pragma once
#include <vector>
#include "datastructures.h"

std::vector<Individual<int>> initalize_binary_population(int population_size, int size);

template <typename T>
Individual<T> best_solution(const std::vector<Individual<T>>& population);

#include "population.tpp"