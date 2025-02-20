//
// Created by Isaac Wedaman on 2/20/25.
//
#include <vector>
using namespace std;

#ifndef TEMPLATE_H
#define TEMPLATE_H



template <typename T>

class Template {
    vector <template> templates;


 private:
    std::vector<T> data;

    //i got this method from geeks for geeks: the "fisher - yates" algorithm
    void shuffle() {
        //you dont need to shuffle a vector of size one.
        if (data.size() <= 1) return;

        //seeding the random generator
        random_device rd;
        mt19937 gen(rd());

        //for each item in the vector, then generate a random index, and swap (using std::swap)
        //the indexes, and the data contained.
        for (size_t i = data.size() - 1; i > 0; --i) {
            uniform_int_distribution<size_t> dist(0, i);
            size_t j = dist(gen);
            swap(data[i], data[j]);
        }
    }

};



#endif //TEMPLATE_H
