#include <iostream>
#include <vector>
#include <random> 
using namespace std;

// Pass by value:        void foo(std::vector<int> v)       // copies the vector
// Pass by reference:    void foo(std::vector<int>& v)      // modifies original
// Pass by const ref:    void foo(const std::vector<int>& v)// read-only, efficient
// Pass by pointer:      void foo(std::vector<int>* v)      // optional/nullable

/**
 * @brief Performs one-point crossover on two parent vectors to produce two child vectors.
 * @param parent1 The first parent vector.
 * @param parent2 The second parent vector.
 * @param child1 The first child vector (output).
 * @param child2 The second child vector (output).
 * @return 0 on success, -1 if the parent vectors are not of the same size or empty.
*/
template <typename T>
int one_point_crossover (const std::vector<T>& parent1, const std::vector<T>& parent2, std::vector<T>& child1, std::vector<T>& child2) {
    if (parent1.size() != parent2.size() || parent1.size() == 0) {
        std::cerr << "Error: Parent arrays must be of the same size." << std::endl;
        return -1;
    }
    int size = parent1.size();
    // Redefine child arrays to the same size as parent arrays
    child1 = std::vector<int>(size);
    child2 = std::vector<int>(size);
    // Generate a random crossover point
    int crossover_point = rand() % size;
    for (int i = 0; i < size; ++i) {
        if (i < crossover_point) {
            child1[i] = parent1[i];
            child2[i] = parent2[i];
        } else {
            child1[i] = parent2[i];
            child2[i] = parent1[i];
        }
    }
    return 0; // Return 0 to indicate success
}

template<typename T>
int two_point_crossover(const std::vector<T>& parent1, const std::vector<T>& parent2, std::vector<T>& child1, std::vector<T>& child2) {
    if (parent1.size() != parent2.size() || parent1.size() == 0) {
        std::cerr << "Error: Parent arrays must be of the same size." << std::endl;
        return -1;
    }
    int size = parent1.size();
    // Redefine child arrays to the same size as parent arrays
    child1 = std::vector<int>(size);
    child2 = std::vector<int>(size);
    // Generate two random crossover points
    int crossover_point1 = rand() % size;
    int crossover_point2 = rand() % size;
    if (crossover_point1 > crossover_point2) {
        std::swap(crossover_point1, crossover_point2);
    }
    for (int i = 0; i < size; ++i) {
        if (i < crossover_point1 || i >= crossover_point2) {
            child1[i] = parent1[i];
            child2[i] = parent2[i];
        } else {
            child1[i] = parent2[i];
            child2[i] = parent1[i];
        }
    }
    return 0; // Return 0 to indicate success
}

template<typename T>
int uniform_crossover(const std::vector<T>& parent1, const std::vector<T>& parent2, std::vector<T>& child1, std::vector<T>& child2, const float p = 0.5f) {
    if (parent1.size() != parent2.size() || parent1.size() == 0) {
        std::cerr << "Error: Parent arrays must be of the same size." << std::endl;
        return -1;
    }
    int size = parent1.size();
    // Redefine child arrays to the same size as parent arrays
    child1 = std::vector<int>(size);
    child2 = std::vector<int>(size);
    // Generate a random mask for crossover
    for (int i = 0; i < size; ++i) {
        if (random_float(0.0f, 1.0f) < p) {
            child1[i] = parent1[i];
            child2[i] = parent2[i];
        } else {
            child1[i] = parent2[i];
            child2[i] = parent1[i];
        }
    }
    return 0; // Return 0 to indicate success
}


int main ()
{
    // Example usage of the one_point_crossover function
    std::vector<int> parent1 = {1, 2, 3, 4, 5};
    std::vector<int> parent2 = {6, 7, 8, 9, 10};
    std::vector<int> child1;
    std::vector<int> child2;

    int result = uniform_crossover(parent1, parent2, child1, child2);
    if (result == 0) {
        std::cout << "Child 1: ";
        for (int i : child1) {
            std::cout << i << " ";
        }
        std::cout << "\nChild 2: ";
        for (int i : child2) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    } else {
        std::cerr << "Crossover failed." << std::endl;
    }
return 0;
}