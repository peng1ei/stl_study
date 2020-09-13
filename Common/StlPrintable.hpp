#pragma once
#include <iostream>
#include <vector>
#include <string>

namespace stlp {

#define COUT_TITLE (std::cout << title)

    enum class SplitType {
        SPACE,          // " "
        COMMA,          // ","
        SPACE_COMMA,    // " ,"
        COMMA_SPACE,    // ", "
    };

    static std::string SplitType2String(SplitType st) {
        switch (st) {
        case SplitType::SPACE: return " ";
        case SplitType::COMMA: return ",";
        case SplitType::SPACE_COMMA: return " ,";
        case SplitType::COMMA_SPACE: return ", ";
        }
    }

    template <typename T>
    void PrintVectorElems(const std::vector<T> &vec, const std::string &title = "Vec", SplitType st = SplitType::SPACE) {
        if (vec.empty()) {
            std::cout << " elems: The input vector is empty." << std::endl;
            return;
        }            

        PrintVectorElems<T>(vec.begin (), vec.end (), title, st);
    }

    template <typename T, typename Iter = std::vector<T>::const_iterator>
    void PrintVectorElems(Iter begin, Iter end, const std::string& title = "Vec", SplitType st = SplitType::SPACE) {
        COUT_TITLE << " elems: { ";
        for (; begin != end-1; ++begin) {
            std::cout << *begin << SplitType2String(st);
        }
        std::cout << *begin << " }" << std::endl;
    }

    template <typename T>
    void PrintVectorSize(const std::vector<T>& vec, const std::string& title = "Vec") {
        COUT_TITLE << " size: " << vec.size() << std::endl;
    }

    template <typename T>
    void PrintVectorCapacity(const std::vector<T>& vec, const std::string& title = "Vec") {
        COUT_TITLE << " capacity: " << vec.capacity() << std::endl;
    }

    template <typename T>
    void PrintVectorMaxSize(const std::vector<T>& vec, const std::string& title = "Vec") {
        COUT_TITLE << " max size: " << vec.max_size() << std::endl;
    }

    template <typename T>
    void PrintVectorStatus(const std::vector<T>& vec, const std::string& title = "Vec", SplitType st = SplitType::SPACE) {
        //std::cout << "=========================[Vector] " << title << "=========================" << std::endl;
        std::cout << "---------------------------[Vector] " << title << "---------------------------" << std::endl;
        PrintVectorElems(vec, "", st);
        PrintVectorSize(vec, "");
        PrintVectorCapacity(vec, "");
        PrintVectorMaxSize(vec, "");
        std::cout << std::endl;
    }

} // namespace stlp
