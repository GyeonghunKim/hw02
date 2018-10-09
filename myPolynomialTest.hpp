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

// I set TOL 10e-6 because round-off error scale of floating-point system in CPP is ~ 10e-7
#define TOL 10e-6
// if VERBOSE true, Many of intermediate calculation result will print
#define VERBOSE true

// determine whether difference of two input variable in L2 sense is less than TOL
template <typename T>
bool isSame_twoContainer_L2sense_inTOL(T a, T b){
    return (L2_difference_two_container(a, b) < TOL);
}




bool test_add_two_container_array(){
    auto a = lin_array<double, 100> (0, 99);
    auto b = lin_array<double, 100>(0, 2 * 99);  // b = 2 * a
    auto c_true = lin_array<double, 100>(0, 3 * 99);  // c = 3 * a
    auto c_calc = add_two_container(a, b);
    if(VERBOSE){
        std::cout << "***********************************************************************************************" << std::endl;
        std::cout << "This commment is from test_add_two_container_array()" << std::endl;
        print_container(a);
        print_container(b);
        print_container(c_calc);
        std::cout << "return  value is: "<<isSame_twoContainer_L2sense_inTOL(c_true, c_calc) << "\n" << std::endl;
        std::cout << "***********************************************************************************************" << std::endl;
    }
    return isSame_twoContainer_L2sense_inTOL(c_true, c_calc);
}

bool test_add_two_container_vector(){
    auto a = lin_vector<double> (0, 99, 100);
    auto b = lin_vector<double> (0, 99*2, 100);  // b = 2 * a
    auto c_true = lin_vector<double> (0, 99*3, 100);  // c = 3 * a
    auto c_calc = add_two_container(a, b);
    if(VERBOSE){
        std::cout << "***********************************************************************************************" << std::endl;
        std::cout << "This commment is from test_add_two_container_vector()" << std::endl;
        print_container(a);
        print_container(b);
        print_container(c_calc);
        std::cout << "return  value is: " << isSame_twoContainer_L2sense_inTOL(c_true, c_calc) << "\n" << std::endl;
        std::cout << "***********************************************************************************************" << std::endl;
    }
    return isSame_twoContainer_L2sense_inTOL(c_true, c_calc);
}

bool test_add_two_container(){
    auto tmp1 = test_add_two_container_array();
    auto tmp2 = test_add_two_container_vector();
    if(VERBOSE){
        std::cout << "***********************************************************************************************" << std::endl;
        std::cout << "test of add_two_container() ";
        if(tmp1){
            std::cout << "passed";
        }
        else{
            std::cout << "failed";
        }
        std::cout << " for array."<< "\n" << "test of add_two_container() ";
        if(tmp2){
            std::cout << "passed";
        }
        else{
            std::cout << "failed";
        }
        std::cout << " for vector.\n" << std::endl;
        std::cout << "***********************************************************************************************" << std::endl;
    }
    return tmp1 && tmp2;
}

bool test_max_container_array(){
    const size_t NN = 101;
    std::array<double, NN> a {0,};
    for(int i = 0; i < int(NN); ++i){
        a[i] = -0.5*std::pow((i - 50),2) + 10.0;
    }
    if(VERBOSE){
        std::cout << "***********************************************************************************************" << std::endl;
        std::cout << "This commment is from test_max_container_array()" << std::endl;
        print_container(a);
        std::cout << "maximum value is : " << max_container(a) << std::endl;
        std::cout << "***********************************************************************************************" << std::endl;
    }
    if ((max_container(a) - 10 < TOL) && (-1*max_container(a) + 10 < TOL)){
        return true;
    }
    return false;
}

bool test_max_container_vector(){
    const size_t NN = 101;
    std::vector<double> a(NN);
    for(int i = 0; i < int(NN); ++i){
        a[i] = -0.5*std::pow((i - 50),2) + 10.0;
    }
    if(VERBOSE){
        std::cout << "***********************************************************************************************" << std::endl;
        std::cout << "This commment is from test_max_container_vector()" << std::endl;
        print_container(a);
        std::cout << "maximum value is : " << max_container(a) << std::endl;
        std::cout << "***********************************************************************************************" << std::endl;
    }
    if ((max_container(a) - 10< TOL) && (-1*max_container(a) + 10 < TOL)){
        return true;
    }
    return false;
}


bool test_max_container() {
    auto tmp1 = test_max_container_array();
    auto tmp2 = test_max_container_vector();
    if(VERBOSE){
        std::cout << "***********************************************************************************************" << std::endl;
        std::cout << "test of max_container() ";
        if(tmp1){
             std::cout << "passed";
        }
        else{
            std::cout << "failed";
        }
        std::cout << " for array."<< "\n" << "test of max_container() ";
        if(tmp2){
            std::cout << "passed";
        }
        else{
            std::cout << "failed";
        }
        std::cout << " for vector." << std::endl;
        std::cout << "***********************************************************************************************" << std::endl;
    }
    return tmp1 && tmp2;
}

bool test_evaluate_array(){
    auto a = lin_array<double, 100> (0, 99);
    auto x = 1.0;
    auto y_from_evaluate = evaluate(a, x);
    auto y_true = 99*100/2;
    if(VERBOSE) {
        std::cout << "0 + 1 + *** + 98 + 99 = " << std::endl;
        std::cout << "from evaluate : " << y_from_evaluate << "\n" << "from summation formula : " << y_true << std::endl;
    }
    return y_from_evaluate == y_true;
}
bool test_evaluate_vector(){
    auto a = lin_vector<double> (0, 99, 100);
    auto x = 1.0;
    auto y_from_evaluate = evaluate(a, x);
    auto y_true = 99*100/2;
    if(VERBOSE) {
        std::cout << "0 + 1 + *** + 98 + 99 = " << std::endl;
        std::cout << "from evaluate : " << y_from_evaluate << "\n" << "from summation formula : " << y_true << std::endl;
    }
    return y_from_evaluate == y_true;
}

bool test_evaluate(){
    auto tmp1 = test_evaluate_array();
    auto tmp2 = test_evaluate_vector();
    if(VERBOSE){
        std::cout << "***********************************************************************************************" << std::endl;
        std::cout << "test of test_evaluate() ";
        if(tmp1){
            std::cout << "passed";
        }
        else{
            std::cout << "failed";
        }
        std::cout << " for array."<< "\n" << "test of test_evaluate() ";
        if(tmp2){
            std::cout << "passed";
        }
        else{
            std::cout << "failed";
        }
        std::cout << " for vector." << std::endl;
        std::cout << "***********************************************************************************************" << std::endl;
    }
    return tmp1 && tmp2;
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
    results.push_back(run_test(test_add_two_container, "test_add_two_container"));
    results.push_back(run_test(test_max_container, "test_max_container"));
    results.push_back(run_test(test_evaluate, "test_evaluate"));


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
