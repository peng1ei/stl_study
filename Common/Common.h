// Common.h : Header file for your target.
#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <complex>
#include <type_traits>

#define COUT_TITLE (std::cout << title << " ")
#define ELEM_OUT_FORMAT(ObjectType) std::ostream& operator<<(std::ostream& out, const ObjectType& obj)
#define FRIEND_OSTREAM_FUNC(ObjectType) friend std::ostream& operator<<(std::ostream& out, const ObjectType& obj);

namespace stlp {

    enum class SplitType {
        SPACE,          // " "
        COMMA,          // ","
        SPACE_COMMA,    // " ,"
        COMMA_SPACE     // ", "
    };

    // Only supports arithmetic types (either an integral or a floating point type)
    template <typename T>
    class Element {
    public:
        Element() : debug_(true), elem_(6) {
            static_assert(std::is_arithmetic<T>::value, "The element type of the container is non-arithmetic.");
            if (debug_) std::cout << "Element() - Default Construct" << std::endl;
        }
        explicit Element(const T& e, bool debug = false) : debug_(debug), elem_(e) {
            static_assert(std::is_arithmetic<T>::value, "The element type of the container is non-arithmetic.");
            if (debug_) std::cout << "Element(const T& e, bool debug = false) - Construct" << std::endl;
        }
        Element(const Element<T>& other) : debug_(other.debug_), elem_(other.elem_) {
            static_assert(std::is_arithmetic<T>::value, "The element type of the container is non-arithmetic.");
            if (debug_) std::cout << "Element(const Element<T>& other) - Copy Construct" << std::endl;
        }

        ~Element() {
            if (debug_) std::cout << "~Element() - Deconstruct" << std::endl;
        }

        Element& operator=(const Element<T>& other) {
            if (debug_) std::cout << "Element& operator=(const Element<T>& other) - Assignment Construct" << std::endl;
            elem_ = other.elem_;
            return *this;
        }

    private:
        bool debug_;
        T elem_;

        template <typename U>
        FRIEND_OSTREAM_FUNC(Element<U>)
    };

    template <typename U>
    ELEM_OUT_FORMAT(Element<U>) {
        out << obj.elem_;
        return out;
    }

    template <typename T>
    ELEM_OUT_FORMAT(std::vector<T>) {
        out << "89";
        return out;
    }

    std::string SplitType2String(SplitType st);
    std::string SplitTypeName2String(SplitType st);

    ELEM_OUT_FORMAT(SplitType);
    ELEM_OUT_FORMAT(std::complex<double>);
}
