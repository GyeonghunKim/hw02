//
// Created by ghkim on 18. 10. 2.
//

#pragma once

#include <iostream>
#include <typeinfo>
#include <type_traits>
#include <cmath>
#include <vector>
#include <array>

// ************************* List of Functions *********************************************************
// 1) Print functinos
// print_container() which print components of container in [1, 2, 3, ... ] form
// print_polynomial() which print components of container in ploynomial form.
//
// 2) generate linear container
// lin_vector() which generate vector whose value is linearly increase.
// lin_array() which generate array whose value is linearly increase.
//
// 3) functions which are used in test functions
// inner_prod() which calculate inner product of two container
// componentwise_prod() which multiply two container componentwise
// subtract_two_container() which subtract two container componentwise
// L2_difference_two_container() which calculate difference between two containers in L2 sense.
// additive_inverse_container() which return additive inverse of input container
//
// 4) functions which are required from homework
// add_two_container() which add two container componentwise
// max_container() which find maximum value in container
// evaluate() which evaluate ploynomial function which use container values as coefficients
// *****************************************************************************************************

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

// generate vector with linear spaced value with start value, stop value and number of points
template <typename T>
std::vector<T> lin_vector(const double &start, const double &stop, const int &num_points){
    std::vector<T> z(num_points);
    for(int i = 0; i < num_points; ++i){
        z[i] = start + i * (stop - start)/(num_points - 1);
    }
    return z;
}

// generate array with linear spaced value with start value, stop value and number of points
template <typename T, size_t size>
std::array<T,size> lin_array(const double &start, const double &stop){
    auto num_points = int(size);
    std::array<T, size> z;
    for(int i = 0; i < num_points; ++i){
        z[i] = start + i * (stop - start)/(num_points - 1);
    }
    return z;
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
// for example, componentwise_prod([1, 2, 3], [4, 5, 6]) = [1*4, 2*5, 3*6]
template <typename Container>
auto componentwise_prod(const Container &container1, const Container &container2){
    auto length = container1.size();
    Container result_container = container1;
    for (int i = 1; i < length; ++i){
        result_container[i] *= container2[i];
    }
    return result_container;
}

// return componentwise subtract of two container
template <typename Container>
Container subtract_two_container(const Container &container1, const Container &container2){
    auto length = container1.size();
    auto subtracted_container = container1;
    for(int i = 0; i < length; ++i) {
        subtracted_container[i] -= container2[i];
    }
    return subtracted_container;
}

// Calculate difference of two container in L2 sense.
// Informations for L2 norm: http://mathworld.wolfram.com/L2-Norm.html
template <typename Container>
auto L2_difference_two_container(const Container &container1, const Container &container2){
    auto tmp_container = subtract_two_container(container1, container2);
    return std::sqrt(inner_prod(tmp_container, tmp_container));
}

// return additive_inverse of container. (I dealt container as element of some "well defined" vector space)
template <typename Container>
auto additive_inverse_container(const Container &container1){
    auto length = container1.size();
    Container container2 = container1;
    for (int i = 0; i < length; ++i){
        container2[i] = -1 * container1[i];
    }
    return container2;
}

// calculate addition of two container componentwise.
template <typename Container>
Container add_two_container(const Container &container1, const Container &container2){
    auto length = container1.size();
    auto added_container = container1;
    for(int i = 0; i < length; ++i) {
        added_container[i] += container2[i];
    }
    return added_container;
}


// return maximum value of container.
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

// evaluate value of polynomial whose coefficients are in container y and x value is x.
template <typename Container, typename Input>
auto evaluate(const Container &y, Input x){
    // order+1 of polynomial is size of y
    const auto order_plus_one = y.size();
    // "out" is return value
    // return type should be type of y[0] * x
    // initialize "out" with y[0] (constant term)
    decltype(y[0] * x) out = y[0];
    auto x_multiplied = x;
    // By introducing multiplied_x, I don't have to calculate N times of multiplication to calculate x^(N+1)
    // O(N^2) => O(N)
    for(int i = 1; i < order_plus_one; ++i){
        out += x_multiplied * y[i];
        x_multiplied *= x;
    }
    return out;
}
