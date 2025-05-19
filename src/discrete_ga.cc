#include <discrete_ga.h>
#include <discrete_individual.h>
#include <vector>
#include <functional>
#include <iostream>
#include <crossover.h>
#include <selection.h>
#include <utility_functions.h>
#include <limits>

DiscreteGeneticAlgorithm::DiscreteGeneticAlgorithm(
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
    ) : population_size(population_size),
        lower_bounds(lower_bounds),
        upper_bounds(upper_bounds),
        mutation_rate(mutation_rate),
        minimize(minimize),
        max_generations(max_generations),
        max_generations_no_improvement(max_generations_no_improvement),
        max_evaluations(max_evaluations),
        max_evaluations_no_improvement(max_evaluations_no_improvement),
        fitness_function(fitness_function),
        selection_fn(selection_fn),
        crossover_fn(crossover_fn) {
        population = initialize_population();
    }

    void DiscreteGeneticAlgorithm::mutate(DiscreteIndividual& individual, double mutation_rate) {
        if(random_double(0.0, 1.0) < mutation_rate) {
            std::vector<int> genes = individual.get_genes();
            int mutation_point = random_int(0, genes.size() - 1);
            int new_value = random_int(lower_bounds[mutation_point], upper_bounds[mutation_point]);
            genes[mutation_point] = new_value;
            individual.set_genes(genes);
        }
    }

    std::vector<DiscreteIndividual> DiscreteGeneticAlgorithm::create_offspring() {
        std::vector<DiscreteIndividual> offspring;
        for (size_t i = 0; i < population_size; i += 2) {
            std::cout << "Creating offspring from individuals " << i << " and " << i + 1 << std::endl;
            auto children = crossover_fn(population[i], population[i + 1]);
            mutate(children.first, mutation_rate);
            mutate(children.second, mutation_rate);
            // Evaluate the fitness of the offspring
            children.first.set_fitness(fitness_function(children.first.get_genes()));
            children.second.set_fitness(fitness_function(children.second.get_genes()));
            offspring.push_back(children.first);
            offspring.push_back(children.second);
        }
        return selection_fn(population, offspring);
    }

    std::vector<DiscreteIndividual> DiscreteGeneticAlgorithm::initialize_population() {
        std::vector<DiscreteIndividual> initial_population;
        std::cout << "Initializing population" << std::endl;
        for (int i = 0; i < population_size; ++i) {
            std::vector<int> genes;
            for (size_t j = 0; j < lower_bounds.size(); ++j) {
                genes.push_back(random_int(lower_bounds[j], upper_bounds[j]));
            }
            initial_population.push_back(DiscreteIndividual(genes));
            initial_population.back().set_fitness(fitness_function(initial_population.back().get_genes()));
        }
        return initial_population;
    }

    void DiscreteGeneticAlgorithm::run() {
        std::cout << "===========================" << std::endl;
        std::cout << "Starting GA" << std::endl;
        std::cout << "===========================" << std::endl;
        int generation = 0;
        int evaluations = 0;
        int generations_no_improvement = 0;
        double best_fitness;
        if (minimize) {
            best_fitness = std::numeric_limits<double>::max();
        } else {
            best_fitness = std::numeric_limits<double>::lowest();
        }
        if (population.size() % 2 != 0) {
            throw std::invalid_argument("Population size must be even.");
        }
        while (generation < max_generations && evaluations < max_evaluations) {
            for (auto& individual : population) {
                double fitness = fitness_function(individual.get_genes());
                if ((minimize && fitness < best_fitness) || (!minimize && fitness > best_fitness)) {
                    best_fitness = fitness;
                    generations_no_improvement = 0;
                } else {
                    generations_no_improvement++;
                }
                individual.set_fitness(fitness);
                evaluations++;
            }
            auto offspring = create_offspring();
            population = selection_fn(population, offspring);
            generation++;
            DiscreteIndividual best_of_population = bestOfPopulation(population, minimize);
            std::cout << "Generation: " << generation << ", Best fitness: " << best_of_population.get_fitness() << std::endl;
        }
        std::cout << "===========================" << std::endl;
        std::cout << "GA terminated after " << generation << " generations and " << evaluations << " evaluations." << std::endl;
        std::cout << "Best fitness: " << best_fitness << std::endl;
        std::cout << "===========================" << std::endl;

    }


// // Example fitness function
// double fitness_function(std::vector<int>& genes) {
//     double fitness = 0.0;
//     for (int gene : genes) {
//         fitness += gene;  // Example: sum of genes as fitness
//     }
//     return fitness;
// }


// int main() {
//     using selection_function_type = std::function<std::vector<DiscreteIndividual>(
//     std::vector<DiscreteIndividual>&,   // Current population
//     std::vector<DiscreteIndividual>&    // Offspring
//     )>;
//     using crossover_function_type = std::function<std::pair<DiscreteIndividual, DiscreteIndividual>(
//         DiscreteIndividual&, DiscreteIndividual&
//     )>;
//     selection_function_type tournament_fn = tournament_selection(4);
//     crossover_function_type one_point_fn = one_point_crossover;

//     DiscreteGeneticAlgorithm ga(
//         100,
//         {0, 0, 0},
//         {10, 10, 10},
//         true,
//         0.01,
//         50,
//         10,
//         10000,
//         1000,
//         tournament_fn,
//         one_point_fn,
//         fitness_function
//     );

//     ga.run();

//     return 0;
// }
