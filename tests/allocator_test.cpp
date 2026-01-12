//
// Created by dingrui on 1/13/26.
//

#include <algorithm>
#include <iostream>
#include <vector>

#include "../src/x_allocator.hpp"

template<typename T>
void print(std::vector<T, XAllocator<T> > &v) {
    std::cout << "capacity: " << v.capacity() << "\t size: " << v.size() << std::endl;
    std::cout << "data: ";
    std::for_each(v.begin(), v.end(), [](int &x)-> void { std::cout << x << ","; });
    std::cout << std::endl;
}

int main() {
    std::vector<int, XAllocator<int> > v = {1, 2, 3};
    print<int>(v);
    for (int i = 0; i < 5; i++) {
        v.push_back(i * 10);
        print<int>(v);
    }

    return 0;
}
