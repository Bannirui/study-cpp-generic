//
// Created by dingrui on 1/13/26.
//

#include <new>

#include "../src/x_data.h"

int main() {
    // global new
    XData *p = (XData *) ::operator new(sizeof(XData) * 3);
    XData *p1 = p;
    // placement new
    new(p1)XData(1);
    p1->~XData();

    XData *p2 = p + 1;
    new(p2)XData(2);
    p2->~XData();

    ::operator delete(p);
    return 0;
}
