//
// Created by pl on 2020/9/20.
//

#ifndef STLSTUDY_PRINTDEQUE_HPP
#define STLSTUDY_PRINTDEQUE_HPP
#include "Common.h"
#include <utility>
#include <deque>

namespace stlp {

    template <typename T>
    void PrintDequeElems(const std::deque<T>& deq, const std::string& title = "Deque", SplitType st = SplitType::SPACE) {
        if (deq.empty()) {
            std::cout << " elems: The input deque is empty." << std::endl;
            return;
        }

        PrintDequeElems<T>(deq.begin(), deq.end(), title, st);
    }

    template <typename T, typename Iter = std::deque<T>::const_iterator>
    void PrintDequeElems(Iter begin, Iter end, const std::string& title = "Deque", SplitType st = SplitType::SPACE) {
        //static_assert(std::is_scalar<T>::value || std::is_same<T, std::string>::value,
        //    "The element type of the container is non-arithmetic.");

        COUT_TITLE << " elems: { ";
        for (; begin != end - 1; ++begin) {
            std::cout << *begin << SplitType2String(st);
        }
        std::cout << *begin << " }" << std::endl;
    }

    template <typename T>
    void PrintDequeSize(const std::deque<T>& deq, const std::string& title = "Deque") {
        COUT_TITLE << " size: " << deq.size() << std::endl;
    }

    template <typename T>
    void PrintDequeMaxSize(const std::deque<T>& deq, const std::string& title = "Deque") {
        COUT_TITLE << " max size: " << deq.max_size() << std::endl;
    }

    template <typename T>
    void PrintDeque(const std::deque<T>& deq, const std::string& title = "Deque", bool display_max_size = false, SplitType st = SplitType::SPACE) {
        std::cout << "---------------------------[Deque] " << title << " [0x" << &deq << "]" << "---------------------------" << std::endl;
        PrintDequeElems(deq, "", st);
        PrintDequeSize(deq, "");

        if (display_max_size)
            PrintDequeMaxSize(deq, "");
        std::cout << std::endl;
    }

    template <typename T, typename... Args>
    void PrintMultiDeque() {}

    template <typename T, typename... Args>
    void PrintMultiDeque(const std::string &title, const std::deque<T> &deq, Args... args) {
        std::cout << "---------------------------[Deque] " << title << " [0x" << &deq << "]" << "---------------------------" << std::endl;
        PrintDequeElems(deq, "", SplitType::SPACE);
        PrintDequeSize(deq, "");
        std::cout << std::endl;

        PrintMultiDeque<T>(args...);
    }


} // namespace stlp

#endif //STLSTUDY_PRINTDEQUE_HPP
