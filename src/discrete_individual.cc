#include <discrete_individual.h>
#include <vector>

DiscreteIndividual::DiscreteIndividual(std::vector<int> genes)
    : genes(genes) {
    // Initialize fitness to a default value
    fitness = 0.0;
}

void DiscreteIndividual::set_fitness(double fitness) {
    this->fitness = fitness;
}

double DiscreteIndividual::get_fitness() const {
    return fitness;
}

//Returns a reference to the genes vector
std::vector<int>& DiscreteIndividual::get_genes() {
    return genes;
}

void DiscreteIndividual::set_genes(std::vector<int>& genes) {
    this->genes = genes; 
}
