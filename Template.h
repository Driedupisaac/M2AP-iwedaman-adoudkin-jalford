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

    vector<T> randomize(vector<T> originalVector) {
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




};



#endif //TEMPLATE_H
