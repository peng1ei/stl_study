// Common.cpp : Source file for your target.
//
#include "Common.h"

namespace stlp {

    std::string SplitType2String(SplitType st) {
        switch (st) {
        case SplitType::SPACE: return " ";
        case SplitType::COMMA: return ",";
        case SplitType::SPACE_COMMA: return " ,";
        case SplitType::COMMA_SPACE: return ", ";
        }
    }

    std::string SplitTypeName2String(SplitType st) {
        switch (st) {
        case SplitType::SPACE: return "SPACE";
        case SplitType::COMMA: return "COMMA";
        case SplitType::SPACE_COMMA: return "SPACE_COMMA";
        case SplitType::COMMA_SPACE: return "COMMA_SPACE";
        }
    }

    /**********************************************************
     * Single element output format of custom type (class)
     **********************************************************/
    ELEM_OUT_FORMAT(SplitType) {
        out << "{" << SplitTypeName2String(obj) << "}";
        return out;
    }

    ELEM_OUT_FORMAT(std::complex<double>) {
        out << "(" << obj.real() << ", " << obj.imag() << ")";
        return out;
    }
}
