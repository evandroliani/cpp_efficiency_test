#include <vector>
#include <string>
#include <chrono>
#include <iostream>

const int num_iterations = 100000;

// Test function for copying a vector
void test_copy(const std::vector<std::string>& source) {
    for (int i = 0; i < num_iterations; ++i) {
        std::vector<std::string> destination = source; // Copy operation
    }
}

// Test function for moving a vector
void test_move(std::vector<std::string>& source) {
    for (int i = 0; i < num_iterations; ++i) {
        std::vector<std::string> destination = std::move(source); // Move operation
        source = std::move(destination); // Move back to re-use source
    }
}

int main() {
    std::vector<std::string> large_vector;
    for (int i = 0; i < 1000; ++i) {
        large_vector.push_back(std::string(1024, 'a')); // Fill with large strings
    }

    // Copy test
    auto start_copy = std::chrono::high_resolution_clock::now();
    test_copy(large_vector);
    auto end_copy = std::chrono::high_resolution_clock::now();
    std::cout << "Copy time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end_copy - start_copy).count() << "ms\n";

    // Move test
    auto start_move = std::chrono::high_resolution_clock::now();
    test_move(large_vector); // Pass by reference to allow modification
    auto end_move = std::chrono::high_resolution_clock::now();
    std::cout << "Move time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end_move - start_move).count() << "ms\n";

    return 0;
}
