#pragma once

#include <vector>
#include <functional>
#include <discrete_individual.h>

using selection_function_type = std::function<std::vector<DiscreteIndividual>(
    std::vector<DiscreteIndividual>&,
    std::vector<DiscreteIndividual>&
)>;

struct tournament_selection {
    int tournament_size;
    bool minimize; // Whether the fitness function minimizes or maximizes
    tournament_selection(int size, bool minimize);
    
    std::vector<DiscreteIndividual> operator()(
        std::vector<DiscreteIndividual>& population,
        std::vector<DiscreteIndividual>& offspring
    ) const;
};

// Declare the function object
extern selection_function_type tournament_fn;
