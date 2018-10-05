//
// Created by ghkim on 18. 10. 2.
//

# pragma once

# include <iostream>
#include <array>
#include <vector>
#include "myPloynomial.hpp"

const bool test_add_two_container(){
    //test container as array
    std::array<int, 4> a{1, 2, 3 ,4};
    std::array<int, 4> b{5, 6, 7, 8};
    print_container(a);
    print_container(b);
    auto c = add_two_container(a, b);
    print_container(c);
    auto tmp = max(c);
    std::cout << tmp << std::endl;
    auto ttmp = inner_prod(a, b);
    std::cout << ttmp<<std::endl;
    std::array<int, 4> co{1, 1, 1, 1};
    std::array<int, 3> x{1, 2, 3};
    print_polynomial(co);
    auto y = evaluate(co, x);
    print_container(y);


}
