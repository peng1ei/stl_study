#include "Common.h"
#include <vector>
#include <type_traits>

namespace stlp {

    template <typename T>
    void PrintVectorElems(const std::vector<T>& vec, const std::string& title = "Vec", SplitType st = SplitType::SPACE) {
        if (vec.empty()) {
            std::cout << " elems: The input vector is empty." << std::endl;
            return;
        }

        PrintVectorElems<T>(vec.begin(), vec.end(), title, st);
    }

    template <typename T, typename Iter = std::vector<T>::const_iterator>
    void PrintVectorElems(Iter begin, Iter end, const std::string& title = "Vec", SplitType st = SplitType::SPACE) {
        //static_assert(std::is_scalar<T>::value || std::is_same<T, std::string>::value, 
        //    "The element type of the container is non-arithmetic.");

        COUT_TITLE << " elems: { ";
        for (; begin != end - 1; ++begin) {
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
        std::cout << "---------------------------[Vector] " 
            << title << "[0x" << &vec << "]" << "---------------------------" << std::endl;
        PrintVectorElems(vec, "", st);
        PrintVectorSize(vec, "");
        PrintVectorCapacity(vec, "");
        PrintVectorMaxSize(vec, "");
        std::cout << std::endl;
    }

} // namespace stlp