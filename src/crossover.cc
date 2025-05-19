#include <crossover.h>
#include <discrete_individual.h>
#include <utility_functions.h>
#include <random> 
#include <functional> 

using crossover_function_type = std::function<std::pair<DiscreteIndividual, DiscreteIndividual>(
    DiscreteIndividual&, DiscreteIndividual&
)>;
// One point crossover
std::pair<DiscreteIndividual, DiscreteIndividual> one_point_crossover(
    DiscreteIndividual& parent1,
    DiscreteIndividual& parent2
) {
    std::vector<int> parent1_genes = parent1.get_genes();
    std::vector<int> parent2_genes = parent2.get_genes();
    int crossover_point = random_int(0, parent1_genes.size() - 1);
    for (int j = crossover_point; j < parent1_genes.size(); ++j) {
        std::swap(parent1_genes[j], parent2_genes[j]);
    }
    // Note: The original individuals are not modified
    DiscreteIndividual child1 = DiscreteIndividual(parent1_genes);
    DiscreteIndividual child2 = DiscreteIndividual(parent2_genes);
    return std::pair<DiscreteIndividual, DiscreteIndividual>(child1, child2);
}
// crossover_function_type one_point_fn = one_point_crossover;

// Two point crossover
std::pair<DiscreteIndividual, DiscreteIndividual> two_point_crossover(
    DiscreteIndividual& parent1,
    DiscreteIndividual& parent2
) {
    std::vector<int> parent1_genes = parent1.get_genes();
    std::vector<int> parent2_genes = parent2.get_genes();
    int crossover_point1 = random_int(0, parent1_genes.size() - 1);
    int crossover_point2 = random_int(crossover_point1, parent1_genes.size() - 1);
    if (crossover_point1 > crossover_point2) {
        std::swap(crossover_point1, crossover_point2);
    }
    for (int j = crossover_point1; j <= crossover_point2; ++j) {
        std::swap(parent1_genes[j], parent2_genes[j]);
    }
    DiscreteIndividual child1 = DiscreteIndividual(parent1_genes);
    DiscreteIndividual child2 = DiscreteIndividual(parent2_genes);
    return std::pair<DiscreteIndividual, DiscreteIndividual>(child1, child2);
}

// Uniform crossover
std::pair<DiscreteIndividual, DiscreteIndividual> uniform_crossover(
    DiscreteIndividual& parent1,
    DiscreteIndividual& parent2
) {
    std::vector<int> parent1_genes = parent1.get_genes();
    std::vector<int> parent2_genes = parent2.get_genes();
    std::vector<int> child1_genes = parent1_genes;
    std::vector<int> child2_genes = parent2_genes;
    for (int j = 0; j < parent1_genes.size(); ++j) {
        // Could make this a parameter, but not feel like making a struct for it
        // Will fix this when it is needed
        if (random_double(0.0, 1.0) < 0.5) { 
            std::swap(child1_genes[j], child2_genes[j]);
        }
    }
    DiscreteIndividual child1 = DiscreteIndividual(child1_genes);
    DiscreteIndividual child2 = DiscreteIndividual(child2_genes);
    return std::pair<DiscreteIndividual, DiscreteIndividual>(child1, child2);
}