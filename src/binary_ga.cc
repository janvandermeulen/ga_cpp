#include "ga.h"
#include "population_binary.h"
#include "crossover.h"

int main(int argc, char** argv) {
    int nr_generations = 100;
    int population_size = 100;
    int size = 10;
    double mutation_rate = 0.01;

    // Your crossover function
    std::function<int(const std::vector<int>&, const std::vector<int>&, std::vector<int>&, std::vector<int>&)> crossover_function = one_point_crossover<int>;

    // Your mutation function (assumed)
    std::function<int(Individual<int>&)> mutation_function = mutate;

    // Lambda wrapping
    auto generate_offspring_lambda = [mutation_rate, crossover_function, mutation_function](const std::vector<Individual<int>>& population) {
        return generate_offspring<int>(population, mutation_rate, crossover_function, mutation_function);
    };

    // Run the ga
    ga<int>(population_size, nr_generations, fitness_function, generate_offspring_lambda, selection_function);
}