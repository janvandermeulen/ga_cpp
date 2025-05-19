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

    tournament_selection(int size = 4);

    std::vector<DiscreteIndividual> operator()(
        std::vector<DiscreteIndividual>& population,
        std::vector<DiscreteIndividual>& offspring
    ) const;
};

// Declare the function object
extern selection_function_type tournament_fn;
