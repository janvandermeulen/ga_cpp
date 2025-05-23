#include <discrete_ga.h>
#include <vector>
#include <discrete_individual.h>
#include <utility_functions.h>
#include <crossover.h>
#include <selection.h>
#include <functional>

// Example fitness function
double fitness_function(std::vector<int>& genes) {
    double fitness = 0.0;
    for (int gene : genes) {
        fitness += gene;  // Example: sum of genes as fitness
    }
    return fitness;
}

int main() {
    using selection_function_type = std::function<std::vector<DiscreteIndividual>(
    std::vector<DiscreteIndividual>&,   // Current population
    std::vector<DiscreteIndividual>&    // Offspring
    )>;
    using crossover_function_type = std::function<std::pair<DiscreteIndividual, DiscreteIndividual>(
        DiscreteIndividual&, DiscreteIndividual&
    )>;
    bool minimize = true;
    selection_function_type tournament_fn = tournament_selection(4, minimize);
    crossover_function_type crossover_fn = uniform_crossover;

    DiscreteGeneticAlgorithm ga(
        40,
        {0, 0, 0},
        {1000, 1000, 1000},
        minimize,
        0.01,
        50,
        10,
        10000,
        1000,
        tournament_fn,
        crossover_fn,
        fitness_function
    );

    ga.run();

    return 0;
}