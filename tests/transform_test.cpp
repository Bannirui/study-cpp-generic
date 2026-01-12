//
// Created by dingrui on 1/12/26.
//

#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
#include <fstream>
#include <string>
#include <iterator>

template<class T>
class Encrypt {
};

template<>
class Encrypt<std::string> {
public:
    std::string operator()(const std::string &str) const {
        std::string ret = str;
        for (auto it = ret.begin(); it != ret.end(); ++it) {
            *it = *it + 1;
        }
        return ret;
    }
};

template<>
class Encrypt<int> {
public:
    int operator()(const int &src) const {
        int ret = src + 1;
        return ret;
    }
};

int main() {
    std::vector<std::string> v;
    std::ifstream in("asset/tmp.txt");
    std::string str;
    while (!in.eof()) {
        std::getline(in, str, '\n');
        v.push_back(str);
    }
    in.close();

    std::transform(v.begin(), v.end(), std::back_inserter(v), Encrypt<std::string>());
    std::copy(v.begin(), v.end(), std::ostream_iterator<std::string>(std::cout, "\t"));
    return 0;
}
