//
// Created by ghkim on 18. 10. 2.
// Last modified on 18. 10. 9.
// SNU-ID: 2016-16746
// GitHub address: https://github.com/GyeonghunKim
//
// Homework 02
//
// In this homework I solve several problems related to template and container types(std::array and std::vector)
// I create three functions.
// First function is "add_two_container" which add two container componentwise.
// Second function is "max_container" which return maximum value in container.
// Last function is "evaluate" which evaluate value of polynomial function.
//
// Answers for questions in Part4
// 1) add_two_container
//  a) I think two is not enough because I didn't tests which written at b)
//  b) I can test is there's any nan value in result vector.
//  Also I can create test functions which input two containers which has different type or different size.
//  c) As I recommend (b), when two input container has different size or type, add_two_container will break.
//
// 2) max_container
//  a) I think two is not enough because I didn't tests which written at b)
//  b) I can test return value is in input container. If not, It must be wrong output.
//  c) This function will break when two input container has different size or type.
//
// 3) evaluate
//  a) I think two is not enough because I didn't tests which written at b)
//  b) I can test if return value will be doubled when all coefficients are doubled.
//  c) This function will break when input coefficient's type is not about number such as array of string.
//

#include "myPolynomialTest.hpp"
#include "myPloynomial.hpp"

int main() {
    run_all_tests();

    return 0;
}

