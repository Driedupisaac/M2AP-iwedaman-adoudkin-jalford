//
// Created by Isaac Wedaman on 2/20/25.
//
#include <vector>
#include <ctime>
#include <chrono>
#include<iomanip>
#include <sstream>

using namespace std;

#ifndef TEMPLATE_H
#define TEMPLATE_H

template <typename T>

class Template {
    vector <template> templates;


private:

public:

    //alex doudkins stuff
    int addressToInt(const void* address) {
    	std::stringstream ss;
    	ss << "0x" << std::hex << std::uppercase << std::setw(16) << std::setfill('0') << reinterpret_cast<uintptr_t>(address);
    	string a = ss.str();
        int sum = 0;

    	for (int i = 0; i < a.size(); i++) {
        	if (isdigit(a[i])) {
            	sum += a[i];
        	}
    	}

        auto now = std::chrono::system_clock::now();
    	auto duration = now.time_since_epoch();
    	auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
    	milliseconds = (milliseconds * 7) % 10000;

        return sum * milliseconds;
	}


	static vector<T> randomize(vector<T> v) {

		if (v.siza() <= 1) return;
                //creating a fector to add to after randomly selecting from vector v
		vector<T> temp(v.size());
		T* mem = &temp[0];
		for (size_t i = 0; i < v.size(); ++i) {
  			T* mem = &temp[i];
  			temp[i] = v[addressToInt(mem)%v.size()];
		}

		return temp;


      }


};



#endif //TEMPLATE_H
