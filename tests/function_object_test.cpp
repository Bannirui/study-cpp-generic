//
// Created by dingrui on 1/11/26.
//

#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
class XDouble {
public:
    void operator()(T &t) {
        t *= 2;
    }
};

int main() {
    std::vector<int> v{1, 2, 3, 4};
    std::for_each(v.begin(), v.end(), [](int &x) { std::cout << x << "\t"; });
    std::cout << std::endl;

    XDouble<int> x;
    std::for_each(v.begin(), v.end(), x);
    std::for_each(v.begin(), v.end(), [](int &x) { std::cout << x << "\t"; });
    std::cout << std::endl;

    auto func = [](int &x)-> void {
        x *= 3;
    };
    std::for_each(v.begin(), v.end(), func);
    std::for_each(v.begin(), v.end(), [](int &x) { std::cout << x << "\t"; });
}
