//
// Created by dingrui on 1/10/26.
//

#include "x_data.h"

#include <iostream>

XData::XData(int sz) {
    std::cout << "XData::XData(int sz)" << std::endl;
    this->p = new int(sz);
}

XData::~XData() {
    std::cout << "XData::~XData()" << std::endl;
    if (this->p) {
        delete this->p;
    }
}

XData::XData(const XData &other) {
    std::cout << "XData::XData(XData &other)" << std::endl;
    // the pointer will be free multiple times
    // this->p = other.p;
    this->p = new int;
    *this->p = *(other.p);
}

XData::XData(XData &&other) {
    std::cout << "XData::XData(XData &&other)" << std::endl;
    this->p = other.p;
    other.p = nullptr;
    std::cout << "this->p=other.p; other.p=NULL;" << std::endl;
}

void XData::Show() {
    if (this->p) {
        std::cout << "XData::Show() p=" << this->p << ", *p=" << *this->p << std::endl;
    }
}
