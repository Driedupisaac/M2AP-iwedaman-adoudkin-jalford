//
// Created by Alex Doudkin on 2/21/25.
//

#include <ctype.h>
#include <iostream>
#include <sstream>
#include <string>
#include <iostream>
#include <string>
using namespace std;

int main() {


    //get random memory address multiply
    vector<int> v;
    v.push_back(1);
    int z = v[0];

    //time stamp to get semi random value
    auto now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
    milliseconds = (milliseconds * 7) % 10000;

    cout << milliseconds << endl;
    cout << &v << endl;



}