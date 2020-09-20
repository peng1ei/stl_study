//
// Created by pl on 2020/9/20.
//

#ifndef STLSTUDY_CONSTRUCTCOPYDESTROY_HPP
#define STLSTUDY_CONSTRUCTCOPYDESTROY_HPP
#include "PrintSTL.hpp"
#include <deque>

void TestConstructCopyDestroy() {
    /************************************************************
     *    Constructor
     ************************************************************/
    // 1. empty container constructor (default constructor)
    // no elems
    std::deque<int> dq_default;
    PrintDeque(dq_default);

    // 2. fill constructor
    // 会调用默认构造函数
    std::deque<int> dq_fill(6);
    std::deque<double> dq_fill_double(10);
    std::deque<Element<int>> dq_fill_custom(2);
    PrintDeque(dq_fill);
    PrintDeque(dq_fill_double);
    PrintDeque(dq_fill_custom);

    // 使用指定的值进行初始化
    std::deque<int> dq_fill_value(6, 9);
    std::deque<Element<int>> dq_fill_custom_value(6, Element<int>(8, false));
    PrintDeque(dq_fill_value);
    PrintDeque(dq_fill_custom_value);
    //PrintMultiDeque<int>("Deque1", dq_fill_value, "Deque2", dq_fill_value, "Deque3", dq_fill_value);

    // 3. Range constructor
    std::deque<int> dq_range(dq_fill_value.begin(), dq_fill_value.begin() + 5);
    PrintDeque(dq_range);

    int array[6]{9, 8, 2, 1, 6, 5};
    std::deque<int> dq_range_array(array, array + sizeof(array) / sizeof(array[0]));
    PrintDeque(dq_range_array, "Range init with array range");

    // 4. Copy constructor
    std::deque<int> dq_copy(dq_range);
    PrintDeque(dq_copy, "Deque init with copy construct");

    // 5. Move constructor
    std::deque<int> dq_move(std::move(dq_range_array));
    PrintDeque(dq_move, "dq_move");
    PrintDeque(dq_range_array, "Move to dq_move");

    // 6. initializer list constructor
    std::deque<int> dq_initializer_list{8, 1, 2, 4, 6, 9, 0};
    PrintDeque(dq_initializer_list, "dq_initializer_list");

    /************************************************************
     *    Assignment operator (operator =)
     ************************************************************/
    // assign constructor
    std::deque<int> dq_assign_copy = dq_initializer_list;
    PrintDeque(dq_assign_copy, "dq_assign_copy");

    // assign move
    std::deque<int> dq_assign_move = std::move(dq_initializer_list);
    PrintDeque(dq_assign_move, "dq_assign_move");

    // assign initializer list
    std::deque<int> dq_assign_initializer_list = {1, 2, 3, 4, 5, 6};
    PrintDeque(dq_assign_initializer_list, "dq_assign_initializer_list");
}

#endif //STLSTUDY_CONSTRUCTCOPYDESTROY_HPP
