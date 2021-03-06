//
// Created by pl on 2020/9/18.
//
#include <deque>
#include <vector>
#include <algorithm>
#include <cassert> // assert
#include "PrintSTL.hpp"
#include "ConstructCopyDestroy.hpp"

void TestStdCopy() {
    std::deque<int> dq{1, 2, 3, 4, 5, 6, 7 , 8, 9, 0};
    PrintDeque(dq);

    std::vector<int> vec;
    vec.resize(6);
    //vec.reserve(6);

    //int count = std::distance(vec.begin(), vec.end());
    assert((std::distance(vec.begin(), vec.end()) >= 6));

    stlp::PrintVector(vec, "copy before");

    std::copy(dq.begin(), dq.begin() + 6, vec.begin());

    stlp::PrintVector(vec, "copy after");
}

int main() {
    TestConstructCopyDestroy();

    return 0;
}

