#pragma once

#include <vector>
#include <functional>
#include <discrete_individual.h>

class DiscreteGeneticAlgorithm {
private:
    int population_size;
    std::vector<int> lower_bounds;
    std::vector<int> upper_bounds;
    std::vector<DiscreteIndividual> population;
    bool minimize;
    double mutation_rate;
    int max_generations;
    int max_generations_no_improvement;
    int max_evaluations;
    int max_evaluations_no_improvement;

public:
    using selection_function_type = std::function<std::vector<DiscreteIndividual>(
        std::vector<DiscreteIndividual>&,
        std::vector<DiscreteIndividual>&
    )>;

    using crossover_function_type = std::function<std::pair<DiscreteIndividual, DiscreteIndividual>(
        DiscreteIndividual&,
        DiscreteIndividual&
    )>;

private:
    selection_function_type selection_fn;
    crossover_function_type crossover_fn;
    std::function<double(std::vector<int>&)> fitness_function;
    int evaluations = 0;
public:
    DiscreteGeneticAlgorithm(
        int population_size,
        const std::vector<int>& lower_bounds,
        const std::vector<int>& upper_bounds,
        bool minimize,
        double mutation_rate,
        int max_generations,
        int max_generations_no_improvement,
        int max_evaluations,
        int max_evaluations_no_improvement,
        selection_function_type selection_fn,
        crossover_function_type crossover_fn,
        std::function<double(std::vector<int>&)> fitness_function
    );
    std::vector<DiscreteIndividual> initialize_population();
    void mutate(DiscreteIndividual& individual, double mutation_rate);
    std::vector<DiscreteIndividual> create_offspring();
    void run();
};
