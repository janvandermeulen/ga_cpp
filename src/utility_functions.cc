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
    if (minimize) {
        return *std::min_element(population.begin(), population.end(),
            [](const DiscreteIndividual& a, const DiscreteIndividual& b) {
                return a.get_fitness() < b.get_fitness();
            });
    } else {
        return *std::max_element(population.begin(), population.end(),
            [](const DiscreteIndividual& a, const DiscreteIndividual& b) {
                return a.get_fitness() < b.get_fitness();
            });
    }
}