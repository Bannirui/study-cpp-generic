#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
    std::vector<int> a{1, 2, 3, 4, 5};
    std::vector<int> b{2, 4, 6, 8, 0};
    std::swap_ranges(a.begin(), a.end(), b.begin());
    std::copy(a.begin(), a.end(), std::ostream_iterator<int>(std::cout, "\t"));
    std::cout << std::endl;
    std::copy(b.begin(), b.end(), std::ostream_iterator<int>(std::cout, "\t"));
    return 0;
}
