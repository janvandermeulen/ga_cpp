#include <vector> 
#include <iostream>
#include <functional>
#include <random>
#include "datastructures.h"
#include "population.h"

/**
 * Generates offspring from the current population using crossover and mutation.
 * When used in the genetic algorithm, this function is first wrapped in a lambda. 
*/
template <typename T>
std::vector<Individual<T>> generate_offspring(
    const std::vector<Individual<T>>& population,
    const float mutation_rate,
    const std::function<int(const std::vector<T>&, const std::vector<T>&, std::vector<T>&, std::vector<T>&)>& crossover_function, // Crossover function that modifies child1 and child2 by reference
    const std::function<int(Individual<T>&)> mutation_function
) {
    std::vector<Individual<T>> shuffled_population = population;
    std::random_shuffle(shuffled_population.begin(), shuffled_population.end());
    std::vector<Individual<T>> offspring;

    for (size_t i = 0; i < shuffled_population.size(); i += 2) {
        if (i + 1 < shuffled_population.size()) {
            // Create empty child vectors for the crossover function to modify
            std::vector<T> child1_genotype, child2_genotype;
            
            // Perform crossover, which modifies child1_genotype and child2_genotype by reference
            crossover_function(shuffled_population[i].genotype, shuffled_population[i + 1].genotype, child1_genotype, child2_genotype);
            
            // Wrap the genotypes in Individual<T> objects
            Individual<T> child1(child1_genotype, shuffled_population[i].fitness_function);
            Individual<T> child2(child2_genotype, shuffled_population[i + 1].fitness_function);
            
            // Apply mutation to each child with the given mutation rate
            if (random_float(0.0, 1.0) < mutation_rate) {
                child1 = mutation_function(child1); // Assuming mutation_function returns a vector of mutated individuals
            }
            if (random_float(0.0, 1.0) < mutation_rate) {
                child2 = mutation_function(child2); // Same for mutation of child2
            }
            
            // Add the children to the offspring population
            offspring.push_back(child1);
            offspring.push_back(child2);
        }
    }
    return offspring;
}



template <typename T>
int ga(int population_size, int max_generations, 
    std::function<double(const std::vector<T>&)> fitness_function, 
    std::function<std::vector<Individual<T>>(const std::vector<Individual<T>>&)> generate_offspring, //Takes a population and returns a new population
    std::function<std::vector<Individual<T>>(const std::vector<Individual<T>>&, const std::vector<Individual<T>>&)> selection_function) //Given a population and its offspring, returns the best individuals
    {
    // Initialize the population randomly 
    std::vector<Individual<T>> population = initalize_binary_population(population_size, 10);
    Individual<T> best_solution = best_solution(population);
    curr_generation = 0;

    // Main loop
    while(curr_generation < max_generations) {
        // Generate offspring using crossover and mutation
        std::vector<Individual<T>> offspring = generate_offspring(population);
        // Evaluate fitness of offspring --> automatically done in the constructor
        // Select the best individuals from the combined population
        population = selection_function(population, offspring);
        best_solution = best_solution(population);
        cout << "Generation " << curr_generation << ": ";
        cout << "Best fitness: " << best_solution.fitness << endl;
        curr_generation++;
    }
    cout << "Best solution found: "; 
    cout << best_solution.fitness << endl;
    return 0;
}
