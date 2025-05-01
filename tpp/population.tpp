#include "population.h"

template <typename T>
Individual<T> best_solution(const std::vector<Individual<T>>& population) {
    Individual<T> best = population[0];
    for (int i = 1; i < population.size(); ++i) {
        if (population[i].fitness > best.fitness) {
            best = population[i];
        }
    }
    return best;
}