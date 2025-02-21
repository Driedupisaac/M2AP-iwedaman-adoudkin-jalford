#ifndef RANDOMVECTOR_H
#define RANDOMVECTOR_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

template <typename T>
class RandomVector {
private:
    std::vector<T> data;

public:
    // Constructor
    RandomVector() = default;

    // Add item to the vector
    void addItem(const T& item) {
        data.push_back(item);
    }

    // Sort the vector
    void sortVector() {
        std::sort(data.begin(), data.end());
    }

    // Find an item in the vector
    bool findItem(const T& item) const {
        return std::find(data.begin(), data.end(), item) != data.end();
    }

    // Overload << operator for printing
    friend std::ostream& operator<<(std::ostream& os, const RandomVector<T>& rv) {
        for (const auto& item : rv.data) {
            os << item << " ";
        }
        return os;
    }

    // Fisher-Yates shuffle (GeeksForGeeks implementation)
    void shuffle() {
        if (data.size() <= 1) return;  // No need to shuffle if the vector size is 1 or less.

        // Seeding the random generator
        random_device rd;
        mt19937 gen(rd());

        // Shuffle the vector using Fisher-Yates
        for (size_t i = data.size() - 1; i > 0; --i) {
            std::uniform_int_distribution<size_t> dist(0, i);
            size_t j = dist(gen);
            std::swap(data[i], data[j]);
        }
    }

    // adoudkins
    void randomize_adoudkins() {
        if (data.siza() <= 1) return;

        int time = time();
    }

    // jcalford's randomization method (your method)
    void randomize_jcalford() {
        for (size_t i = 0; i < data.size(); ++i) {
            size_t swapIndex = (i ^ 31) % data.size();  // XOR with 31 and take modulo
            std::swap(data[i], data[swapIndex]);
        }
    }



};

#endif
