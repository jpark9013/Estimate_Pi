#include <chrono>
#include <iostream>
#include <numeric>
#include <random>

// between interval [0, ceil]
double get_rand(std::mt19937_64 &rng, std::int64_t ceil) {
  return double(rng()) / double(std::mt19937_64::max()) * double(ceil);
}

double calculate_pi(std::int64_t trials) {
  std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
  std::int64_t hits = 0;
  for (std::int64_t i = 0; i < trials; i++) {
    // float x = get_rand(rng, 2);
    // float y = get_rand(rng, 2);
    double x = get_rand(rng, 2);
    double y = get_rand(rng, 2);
    // center is (1, 1)
    // cannot be more than distance 1 from center
    // distance formula is sqrt((x - 1)² + (y - 1)²)
    // float distance = (x - 1) * (x - 1) + (y - 1) * (y - 1);
    double distance = (x - 1) * (x - 1) + (y - 1) * (y - 1);
    if (distance <= 1) {
      hits++;
    }
  }
  // double(hits) / double(trials) represents area of circle / area of square
  // thus (pi * r²) / 4 = pi / 4 since r = 1
  // thus if ratio ~ pi / 4, then pi ~ ratio * 4
  double ratio = double(hits) / double(trials);
  return ratio * 4;
}

int main() {
  std::int64_t trials;
  std::cout << "How many trials would you like to do? ";
  std::cin >> trials;
  std::cout << "The approximate value of π from the trials is " << calculate_pi(trials) << '\n';
}