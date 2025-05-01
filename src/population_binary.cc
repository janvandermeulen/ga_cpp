#include "population_binary.h"

std::vector<Individual<int>> initalize_binary_population(int population_size, int size) {
    std::vector<Individual<int>> population;
    population = std::vector<Individual<int>>(population_size);
    for (int i = 0; i < population_size; ++i) {
        std::vector<int> genotype(size);
        for (int j = 0; j < size; ++j) {
            genotype[j] = rand() % 2;
        }
        population[i] = Individual<int>(genotype, fitness_function);
    }
    return population;
}

Individual<int> best_solution(const std::vector<Individual<int>>& population) {
    Individual<int> best = population[0];
    for (int i = 1; i < population.size(); ++i) {
        if (population[i].fitness > best.fitness) {
            best = population[i];
        }
    }
    return best;
}

/**
 * This function flips a random bit of the genotype of the individual.
*/
int mutate(Individual<int>& individual) {
    int index = rand() % individual.genotype.size();
    individual.genotype[index] = 1 - individual.genotype[index]; // Flip the bit
    individual.fitness = fitness_function(individual.genotype); // Recalculate fitness
    return 0; // Return 0 to indicate success
}
