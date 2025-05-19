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
    // Create new individuals with the swapped genes
    // Note: The original individuals are not modified
    DiscreteIndividual child1 = DiscreteIndividual(parent1_genes);
    DiscreteIndividual child2 = DiscreteIndividual(parent2_genes);
    return std::pair<DiscreteIndividual, DiscreteIndividual>(child1, child2);
}
crossover_function_type one_point_fn = one_point_crossover;