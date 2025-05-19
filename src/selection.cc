#include <selection.h>
#include <discrete_individual.h>
#include <algorithm> 
#include <vector> 
#include <functional>
#include <iostream>
#include <utility_functions.h>

tournament_selection::tournament_selection(int size, bool minimize)
    : tournament_size(size), minimize(minimize) {}

std::vector<DiscreteIndividual> tournament_selection::operator()(
    std::vector<DiscreteIndividual>& population,
    std::vector<DiscreteIndividual>& offspring
) const {
    std::vector<DiscreteIndividual> selected_individuals;
    std::vector<DiscreteIndividual> combined = population;
    combined.insert(combined.end(), offspring.begin(), offspring.end());
    shuffle_population(combined);
    int j = 0; int i = 0;
    std::vector<DiscreteIndividual> tournament_bracket;
    while (j < population.size() && i < combined.size()) {
        for (int i = 0; i < tournament_size; ++i) {
            tournament_bracket.push_back(combined[(j*2 + i)% combined.size()]);
        }
        if (minimize) {
            std::sort(tournament_bracket.begin(), tournament_bracket.end(),
                [](const DiscreteIndividual& a, const DiscreteIndividual& b) {
                    return a.get_fitness() < b.get_fitness();
                });
        } else {
            std::sort(tournament_bracket.begin(), tournament_bracket.end(),
                [](const DiscreteIndividual& a, const DiscreteIndividual& b) {
                    return a.get_fitness() > b.get_fitness();
                });
        }
        if (tournament_bracket.size() >= 2) {
            selected_individuals.push_back(tournament_bracket[0]);
            selected_individuals.push_back(tournament_bracket[1]);
            j += 2;
        } else if (tournament_bracket.size() == 1) {
            selected_individuals.push_back(tournament_bracket[0]);
            j++;
        }
        tournament_bracket.clear();
    }
    return selected_individuals;
}

// Define the function object
// selection_function_type tournament_fn = tournament_selection(4, true);