#pragma once
#include <discrete_individual.h>

std::pair<DiscreteIndividual, DiscreteIndividual> one_point_crossover(
    DiscreteIndividual& parent1,
    DiscreteIndividual& parent2
);