#pragma once

int random_int(int low, int high);
double random_double(double low, double high);
void shuffle_population(std::vector<DiscreteIndividual>& population);
DiscreteIndividual bestOfPopulation(std::vector<DiscreteIndividual>& population, bool minimize);