#pragma once

#include <random>
#include "fitness.h"
#include "datastructures.h"

std::vector<Individual<int>> initalize_binary_population(int population_size, int size);
Individual<int> best_solution(const std::vector<Individual<int>>& population);
int mutate(Individual<int>& individual);