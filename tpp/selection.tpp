#include <vector>
#include "datastructures.h"

template<typename T>
std::vector<Individual<T>> tournament_selection(const std::vector<Individual<T>>&, const std::vector<Individual<T>>&) {
    // Shuffle the population and its offspring
    std::vector<Individual<T>> selected_population;
    std::random_shuffle(population.begin(), population.end());
    std::random_shuffle(offspring.begin(), offspring.end());
    // Select the best individuals from the shuffled population and offspring
    int index_population = 0;
    int index_offspring = 0;
    while (selected_population.size() < population.size()) {
        // Pick the best two out of two parents and two children
        
    }
}
