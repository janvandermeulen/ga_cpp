# ga_cpp
In this repo I implement some genetic algorithms in c++ and/or c. 
Execute code with ```g++ -I ga_cc/include/my_project -o experiment1 ga_cc/src/*.cc```.

### Template for impelemtation
In this section I brainstorm my implementation of a genetic algorithm.
#### Individual Class 
An individual represents one solution, which is a vector of genes. 
<code>
DiscreteIndividual:  
    - genes: *vector\<int\>* of genes 
    - fitness: *double* fitness of the individual
</code>

#### Discrete Genetic Algorithm Class
This class contains all the information needed to execute the genetic algorithm. Hyperparameters / functions *and* the actual algorithm. 
<code>
DiscreteGeneticAlgorithm:
    # Basic Values:
    - Population_size: int  
    - lower_bounds: vector of lower bounds for each gene
    - upper_bounds: vector of upper bounds for each gene
    # Hyperparameters - This can be generalized later, to support different types of GAs
    - Mutation_rate: double
    - Crossover_rate: double
    - Selection_rate: double
    # Stopping Criteria 
    - Max_generations: int
    - Max_generations_no_improvement: int
    - Max_time: int
    - Max_evaluations: int (evaluation budget)
    - Max_evaluations_no_improvement: int
    # Functions
    - Population_initialization_function(population_size, lower_bounds, upper_bounds): function
    - Create_offspring(crossover_rate, mutation_rate): function, 
    - Selection_function(parents, children): function
    - Fitness_function(genes): function

    # Algorithm
    - Run: function, returns the best individual
      - Initialize population
      - Evaluate population
      - While not stopping criteria:
        - Create offspring
        - Evaluate offspring
        - Select and replace new population
        - Update best individual
</code>
