// #include "utility_functions.h"
#include <random>
#include <chrono>
#include <algorithm>
#include <discrete_individual.h>

// From low to high inclusive range
int random_int(int low, int high) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(low, high);
    return distr(gen);
}

double random_double(double low, double high) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> distr(low, high);
    return distr(gen);
}

void shuffle_population(std::vector<DiscreteIndividual>& population) {
    static std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    std::shuffle(population.begin(), population.end(), rng);
}

DiscreteIndividual bestOfPopulation(std::vector<DiscreteIndividual>& population, bool minimize) {
    DiscreteIndividual best_individual = population[0];
    for (const auto& individual : population) {
        if ((minimize && individual.get_fitness() < best_individual.get_fitness()) ||
            (!minimize && individual.get_fitness() > best_individual.get_fitness())) {
            best_individual = individual;
        }
    }
    return best_individual;
}