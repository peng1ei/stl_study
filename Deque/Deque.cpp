//
// Created by pl on 2020/9/18.
//
#include <deque>
#include <vector>
#include <algorithm>
#include <cassert> // assert
#include "PrintVector.hpp"

int main() {
    std::deque<int> dq{1, 2, 3, 4, 5, 6, 7 , 8, 9, 0};

    std::vector<int> vec;
    //vec.resize(6);
    vec.reserve(6);

    int count = std::distance(vec.begin(), vec.end());
    assert((std::distance(vec.begin(), vec.end()) >= 6));

    stlp::PrintVectorStatus(vec, "copy before");

    std::copy(dq.begin(), dq.begin() + 6, vec.begin());

    stlp::PrintVectorStatus(vec, "copy after");

    return 0;
}

