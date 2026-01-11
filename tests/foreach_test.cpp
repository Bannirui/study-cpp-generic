#include <iostream>
#include <vector>
#include <functional>

template<class T, class RetType>
class PrintInfo : public std::unary_function<T, RetType> {
public:
    PrintInfo() = default;

    T get_sum() { return this->m_sum; }
    T get_max() { return this->m_max; }
    T get_min() { return this->m_min; }

    RetType operator()(T &x) {
        if (this->m_cnt == 0) {
            this->m_max = x;
            this->m_min = x;
        } else {
            if (this->m_max < x) {
                this->m_max = x;
            }
            if (this->m_min > x) {
                this->m_min = x;
            }
        }
        this->m_sum += x;
        ++this->m_cnt;
        return static_cast<RetType>(this->m_sum / this->m_cnt);
    }

private:
    T m_max;
    T m_min;
    T m_sum{0};
    int m_cnt{0};
};

int main() {
    std::vector<float> v = {1.1, 2.2, 3.3, 4.4, 5.6};
    PrintInfo<float, double> p = for_each(v.begin(), v.end(), PrintInfo<float, double>());
    std::cout << p.get_max() << std::endl;
    std::cout << p.get_min() << std::endl;
    std::cout << p.get_sum() << std::endl;
    return 0;
}
