//
// Created by dingrui on 1/10/26.
//

#pragma once

class XData {
public:
    XData(int sz);

    ~XData();

    XData(const XData &other);

    XData(XData &&other);

    void Show();

private:
    int *p;
};
