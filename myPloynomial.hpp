//
// Created by ghkim on 18. 10. 2.
//

#pragma once

#include <iostream>
#include <typeinfo>

template <typename Container>
void print_container(const Container &container1){
    auto length = container1.size();
    std::cout << "[";
    for (int i = 0; i < length; ++i){
        std::cout << container1[i] << "\t";
    }
    std::cout << "]" << std::endl;
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
auto max(const Container &container1){
    auto length = container1.size();
    auto max_val = container1[0];
    // don't have to compare max_val with container[0] because max_val initialized with container[0]
    for(int i = 1; i < length; ++i){
        if(container1[i] > max_val){max_val = container1[i];}
    }
    return max_val;
}

