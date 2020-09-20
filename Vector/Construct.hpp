#pragma once
#include "PrintSTL.hpp"

void TestConstruct() {
    std::vector<int> vec{1, 2, 4, 5, 6};
    stlp::PrintVector(vec);
}
