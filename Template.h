//
// Created by Isaac Wedaman on 2/20/25.
//
#include <vector>
#include <ctime>
#include <chrono>

using namespace std;

#ifndef TEMPLATE_H
#define TEMPLATE_H



template <typename T>

class Template {
    vector <T> templates;


private:

public:

    vector<T> randomizead(vector<T> originalVector) {
        int originalVectorsize = originalVector.size();
        stringstream ss;
        const void* address;
        vector<T> result(originalVector.size());
        int memAddressSum;
        //loops through the original vector getting memory addresses
        while (originalVector.size() > 0) {
            int i=0;
            address = &originalVector[i];
            ss << "0x" << std::hex << std::uppercase << std::setw(16) << std::setfill('0') << reinterpret_cast<uintptr_t>(address);
            //loops through the memory address to get all digits and sums them together.
            for (int j = 0; j < ss.str().size(); j++) {
                if (isdigit(ss.str()[j])) {
                    memAddressSum += int(ss.str()[j]);
                }
            }
            //gets the curent time in milliseconds
            auto now = std::chrono::system_clock::now();
            auto duration = now.time_since_epoch();
            auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count()%1000;

            //adds sum of memory address integers to milisconds to get some more randomized number
            int randomNumber = memAddressSum + milliseconds * 7;

            //checks if the space in the vector is already taken
            int testvar = result[randomNumber % originalVectorsize];
            if (testvar == 0) {
                result[randomNumber % originalVectorsize] = originalVector[i];
            }else {
                int k=0;
                while (result[k] != 0) {
                    auto startTime = chrono::system_clock::now();
                    auto length = startTime.time_since_epoch();
                    auto milliseconds = chrono::duration_cast<chrono::milliseconds>(length).count()%1000;
                    k = milliseconds*7 % result.size();
                }
                result[k] = originalVector[i];
            }
            originalVector.erase(originalVector.begin());
            i++;
        }

        return result;
    }

    //i got this method from geeks for geeks: the "fisher - yates" algorithm
    void randomizeiw() {
        //you do not need to shuffle a vector of size one.
        if (templates.size() <= 1) return;

        //seeding the random generator
        random_device rd;
        mt19937 gen(rd());

        //for each item in the vector, then generate a random index, and swap (using std::swap)
        //the indexes, and the data contained.
        for (size_t i = templates.size() - 1; i > 0; --i) {
            uniform_int_distribution<size_t> dist(0, i);
            size_t j = dist(gen);
            swap(data[i], data[j]);
        }
    }

    //this method utilizes the <algorithm> package
    void sort() {
        sort(templates.begin(), templates.end());
    }

    int find(const T& value) const {
        //have an index counter, and see if the inputted value can be found using the
        //"find" function from <algorithm>
        //-1 is returned if not
        int index;
        index = find(templates.begin(), templates.end(), value);

        //searches through the data, and if the search stop (item found), the distance to that item
        //is calculated, and returned, or -1 if not
        if (index != templates.end()) {
            return distance(templates.begin(), index);
        } else {
            return -1;
        }
    }

    ostream& operator<<(ostream& os, const Template<T>& obj) {
        for (const auto& val : obj.templates) {
            os << val << " ";
        }
        return os;
    }


};



#endif //TEMPLATE_H
