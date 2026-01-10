//
// Created by dingrui on 1/10/26.
//

#include <iostream>

#include "../src/x_data.h"

XData gen() {
    XData x(10);
    return x;
}

int main() {
    {
        XData x1(10);
        XData x2(std::move(x1));
        x1.Show();
        x2.Show();
    }
    {
        // in cpp 17, only one object, no move and copy constructor
        XData x(gen());
        x.Show();
    }
    {
        XData x1(10);
        XData x2(100);
        x1.Show();
        x2.Show();
    }
    {
        XData x1(10);
        XData x2(x1);
        x1.Show();
        x2.Show();
    }
    return 0;
}
