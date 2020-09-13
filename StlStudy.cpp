// StlStudy.cpp : Defines the entry point for the application.
//

#include "StlStudy.h"
#include "Common/StlPrintable.hpp"

void TestResizeReserve() {
    std::vector<int> vec{ 1, 2, 3, 4, 5 };

    std::cout << "-------------src-------------0" << std::endl;
    std::cout << "size: " << vec.size() << std::endl;
    std::cout << "capacity: " << vec.capacity() << std::endl;

    std::cout << "-------------n < size-------------0" << std::endl;
    vec.resize(3);

    std::cout << "size: " << vec.size() << std::endl;
    std::cout << "capacity: " << vec.capacity() << std::endl;

    std::cout << "-------------n >= size-------------0" << std::endl;
    vec.resize(9, 66);

    std::cout << "size: " << vec.size() << std::endl;
    std::cout << "capacity: " << vec.capacity() << std::endl;
    for (auto& e : vec) {
        std::cout << e << " ";
    }


    std::cout << "-------------capacity n < size-------------0" << std::endl;
    vec.reserve(6);

    std::cout << "size: " << vec.size() << std::endl;
    std::cout << "capacity: " << vec.capacity() << std::endl;

    std::cout << "-------------capacity n >= size-------------0" << std::endl;
    vec.reserve(20);

    std::cout << "size: " << vec.size() << std::endl;
    std::cout << "capacity: " << vec.capacity() << std::endl;

    std::vector<int> vec2;
    vec2.reserve(100);

    std::cout << "vec2 size: " << vec2.size() << std::endl;
    std::cout << "vec2 capacity: " << vec2.capacity() << std::endl;

}

void TestResizeReserve2() {
    using namespace stlp;

    std::vector<int> vec{ 1, 2, 3, 4, 5 };
    PrintVectorStatus(vec, "src");

    vec.resize(3);
    PrintVectorStatus(vec, "n < size");

    vec.resize(9, 66);
    PrintVectorStatus(vec, "n >= size");

    vec.reserve(6);
    PrintVectorStatus(vec, "capacity n < size");

    vec.reserve(20);
    PrintVectorStatus(vec, "capacity n >= size");

    std::vector<int> vec2;
    vec2.reserve(100);
    PrintVectorStatus(vec2, "vec2");
}

int main()
{
	std::cout << "=============Hello STL=============" << std::endl << std::endl;

	std::vector<int> vec{ 1, 2, 3, 4, 5 };
	
	//stlp::PrintVectorStatus<int>(std::vector<int>(), "Empty Vec");
	//stlp::PrintVectorStatus<int>(vec);
	//stlp::PrintVectorElems<int>(vec.begin()+1, vec.begin () + 3, "vec[2,3]");
	//stlp::PrintVectorElems<int>(vec.begin() + 1, vec.begin() + 4);

    TestResizeReserve2();

    std::cout << "Please enter any character to exit the program." << std::endl;
	getchar();
	return 0;
}
