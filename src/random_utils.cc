#include <random>
float random_float(float min, float max) {
    static std::random_device rd;
    static std::mt19937 eng(rd());
    std::uniform_real_distribution<> distr(min, max);
    return distr(eng);
}
