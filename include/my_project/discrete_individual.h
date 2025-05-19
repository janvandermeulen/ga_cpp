#pragma once
#include <vector>

class DiscreteIndividual {
private:
    std::vector<int> genes;
    double fitness;

public:
    DiscreteIndividual(std::vector<int> genes);

    double get_fitness() const;
    void set_fitness(double fitness);

    std::vector<int>& get_genes();
    void set_genes(std::vector<int>& genes);
};
