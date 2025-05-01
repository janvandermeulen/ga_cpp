#pragma once

#include <vector>
#include <functional>

template <typename T>
class Individual {
public:
    std::vector<T> genotype;
    double fitness;
    std::function<double(const std::vector<T>&)> fitness_function;

    Individual(std::vector<T> g, std::function<double(const std::vector<T>&)> ff)
        : genotype(g), fitness_function(ff)
    {
        fitness = fitness_function(genotype);
    }
};