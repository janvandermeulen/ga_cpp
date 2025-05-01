#include "fitness.h"
double fitness_function(const std::vector<int>& genotype) {
    double fitness = 0.0;
    for (int val : genotype) fitness += val;
    return fitness;
}