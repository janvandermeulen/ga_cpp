// ga.h
#pragma once
#include <vector>
#include <functional>
#include "datastructures.h"

template <typename T>
int ga(int population_size, int max_generations, 
    std::function<double(const std::vector<T>&)> fitness_function, 
    std::function<std::vector<Individual<T>>(const std::vector<Individual<T>>&)> generate_offspring,
    std::function<std::vector<Individual<T>>(const std::vector<Individual<T>>&, const std::vector<Individual<T>>&)> selection_function);
template <typename T>
std::vector<Individual<T>> generate_offspring(
    const std::vector<Individual<T>>& population,
    const float mutation_rate,
    const std::function<int(const std::vector<T>&, const std::vector<T>&, std::vector<T>&, std::vector<T>&)>& crossover_function, // Crossover function that modifies child1 and child2 by reference
    const std::function<int(Individual<T>&)> mutation_function
)

#include "ga.tpp"