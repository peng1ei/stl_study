//
// Created by pl on 2020/9/20.
//

#ifndef STLSTUDY_SHRINKTOFIT_HPP
#define STLSTUDY_SHRINKTOFIT_HPP
#include "PrintSTL.hpp"

void TestShinkToFit() {
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    //vec.reserve(12);
    PrintVector(vec, "Src vec");

    vec.resize(5);
    PrintVector(vec, "Resize vec");

    vec.shrink_to_fit();
    PrintVector(vec, "After shrink_to_fit");
}

#endif //STLSTUDY_SHRINKTOFIT_HPP
