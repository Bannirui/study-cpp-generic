//
// Created by dingrui on 1/11/26.
//

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

int main() {
    std::vector<int> v{1, 2, 3, 5, 6};

    {
        auto p = std::find(v.begin(), v.end(), 3);
        if (p != v.end()) {
            std::cout << p - v.begin() << "\t" << *p << std::endl;
        }
    }
    {
        auto p = std::find_if(v.begin(), v.end(), [](int &x)-> bool { return x > 4; });
        if (p != v.end()) {
            std::cout << p - v.begin() << "\t" << *p << std::endl;
        }
    }
    return 0;
}
