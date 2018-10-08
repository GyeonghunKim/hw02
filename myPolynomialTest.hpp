//
// Created by ghkim on 18. 10. 2.
//

#pragma once

#include <iostream>
#include <functional>
#include <string>
#include <array>
#include <vector>
#include "myPloynomial.hpp"

// headers for random functions
#include <ctime>
#include <random>

#define VERBOSE false

bool test_add_two_container_array(){

}

bool test_max_container_array(){

}

bool test_evaluate_array(){

}

bool test_add_two_container_vector(){

}

bool test_max_container_vector(){

}

bool test_evaluate_vector(){

}


// function which run test and print result
// I refer to Eric's code
// This function is same with 1st homework of TPCS2 class
bool run_test(std::function<bool(void)> func, const std::string& function_name){
    bool isTrue = func();
    if (isTrue){
        std::cout << "test passed -> " << function_name << "\n";
    }
    else{
        std::cout << "test failed -> " << function_name << "\n";
    }
    return isTrue;
}

// function which run all 4 tests and print result
// I refer to Eric's code
// This function is almost same with 1st homework of TPCS2 class

bool run_all_tests(){
    std::vector<bool> results;
    // test four functions
    results.push_back(run_test(test_add_two_container_array, "test_add_two_container_array"));
    results.push_back(run_test(test_max_container_array, "test_max_container_array"));
    results.push_back(run_test(test_evaluate_array, "test_evaluate_array"));
    results.push_back(run_test(test_add_two_container_vector, "test_add_two_container_vector"));
    results.push_back(run_test(test_max_container_vector, "test_max_container_vector"));
    results.push_back(run_test(test_evaluate_vector, "test_evaluate_vector"));

    bool one_is_false = false;

    // print which is passed and which is failed
    for (int i = 0; i<4; ++i){
        if(!results[i]){ one_is_false = true; }
    }
    // print all test passed or some test failed
    if(!one_is_false){
        std::cout <<"**************all test passed!!****************";
    }
    else{
        std::cout <<"**************some test failed!!****************";
    }

}
