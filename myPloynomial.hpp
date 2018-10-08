//
// Created by ghkim on 18. 10. 2.
//

#pragma once

#include <iostream>
#include <typeinfo>
#include <type_traits>

// **** List of Functions ****
// print_container() which print components of container in [1, 2, 3, ... ] form
// print_polynomial() which print components of container in ploynomial form.
// inner_prod() which calculate inner product of two container
// componentwise_prod() which multiply two container componentwise
// max_container() which find maximum value in container
// add_two_container() which add two container componentwise
// evaluate() which evaluate ploynomial function which use container values as coefficients

// print components in container in serial
// for my convince

template <typename Container>
void print_container(const Container &container1){
    auto length = container1.size();
    std::cout << "[";
    for (int i = 0; i < length; ++i){
        std::cout << container1[i] << "\t";
    }
    std::cout << "]" << std::endl;
}

// print polynomial with coefficients in input container
// for my convince
template <typename Container>
void print_polynomial(const Container &container1){
    auto length = container1.size();
    std::cout << "P(x) = " << container1[0] << "+\t";
    for (int i = 1; i < length - 1; ++i){
        std::cout << container1[i] << "*x^" << i << " +\t";
    }
    std::cout << container1[length-1] << "*x^" << length-1 << std::endl;
}

// calculate inner product of two input containers
// for my convince
template <typename Container>
auto inner_prod(const Container &container1, const Container &container2){
    auto length = container1.size();
    // use auto to get datatype of element of container
    auto inner_prod_result = container1[0]*container2[0];
    for (int i = 1; i < length; ++i){
        inner_prod_result += (container1[i] * container2[i]);
    }
    return inner_prod_result;
}


// calculate componentwise product of two container
// for my convince
template <typename Container>
auto componentwise_prod(const Container &container1, const Container &container2){
    auto length = container1.size();
    Container result_container = container1;
    for (int i = 1; i < length; ++i){
        result_container[i] *= container2[i];
    }
    return result_container;
}


template <typename Container>
Container add_two_container(const Container &container1, const Container &container2){
    auto length = container1.size();
    Container added_container;
    for(int i = 0; i < length; ++i) {
        added_container[i] = container1[i] + container2[i];
    }
    return added_container;
}

template <typename Container>
auto max_container(const Container &container1){
    auto length = container1.size();
    auto max_val = container1[0];
    // don't have to compare max_val with container[0] because max_val initialized with container[0]
    for(int i = 1; i < length; ++i){
        if(container1[i] > max_val){max_val = container1[i];}
    }
    return max_val;
}



template <typename Container, typename Input>
auto evaluate(const Container &y, Input &x) -> Input{
    // order of polynomial
    const auto order_plus_one = y.size();
    // length of inputdata
    const auto length = x.size();
    // "out" is return value
    // initialize out with 0
    Input out {0,};

    auto cur_coef = y[0];
    for (int i = 0; i < length; ++i){
        out[i] += cur_coef;
    }
    auto x_multiplied = x;
    for(int i = 1; i < order_plus_one; ++i){
        if(i != 1){
            x_multiplied = componentwise_prod(x_multiplied, x);
            cur_coef = y[i];
        }
        for(int j = 0; j < length; ++j){
            out[j] += cur_coef * x_multiplied[j];
        }
    }
    return out;
}
