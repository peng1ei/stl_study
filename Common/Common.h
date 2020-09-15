// Common.h : Header file for your target.
#pragma once
#include <string>
#include <iostream>
#include <complex>

#define COUT_TITLE (std::cout << title << " ")
#define ELEM_OUT_FORMAT(ObjectType) std::ostream& operator<<(std::ostream& out, const ObjectType& obj)

namespace stlp {

    enum class SplitType {
        SPACE,          // " "
        COMMA,          // ","
        SPACE_COMMA,    // " ,"
        COMMA_SPACE     // ", "
    };

    std::string SplitType2String(SplitType st);
    std::string SplitTypeName2String(SplitType st);

    ELEM_OUT_FORMAT(SplitType);
    ELEM_OUT_FORMAT(std::complex<double>);
}
