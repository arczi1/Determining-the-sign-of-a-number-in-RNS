#pragma once

#include "rnsNumber.hpp"

#include <iostream>

int modulo(int num, int divider) {
    return num % divider;
}

int tensorProduct(int num1, int num2, int divider) {
    return modulo(num1*num2, divider); 
}

RNSNumber tensorProduct(RNSNumber num1, RNSNumber num2) {
    if(num1.getBase() != num2.getBase()) 
        return RNSNumber{std::vector<int>{}, std::vector<int>{}};
    
    std::vector<int> newResidues{};
    for(int i = 0; i < num1.getBase().size(); i++) {
        newResidues.push_back(tensorProduct(num1.getResidues().at(i), 
                                            num2.getResidues().at(i), 
                                            num1.getBase().at(i)));
    }

    return RNSNumber{newResidues, num1.getBase()};
}

struct WideOneMatrix {
    enum class Direction {
        horizontal,
        vertical,
    };

    std::vector<int> numbers;
    Direction direction;
};

int multiplication(WideOneMatrix first, WideOneMatrix second) {
    if(first.direction != WideOneMatrix::Direction::horizontal ||
       second.direction != WideOneMatrix::Direction::vertical) 
        std::cout << "Unsupported way of multiplication matrixes!" << std::endl;
    
    int product{};
    for(int i = 0; i < first.numbers.size(); i++) {
        product += first.numbers.at(i) * second.numbers.at(i);
    }

    return product;
}

WideOneMatrix transpose(WideOneMatrix matrix) {
    WideOneMatrix afterTranspose{};
    afterTranspose.numbers = matrix.numbers;
    if(matrix.direction == WideOneMatrix::Direction::horizontal)
        afterTranspose.direction = WideOneMatrix::Direction::vertical;
    else
        afterTranspose.direction = WideOneMatrix::Direction::horizontal;
    
    return afterTranspose;
}

bool XOR(bool first, bool second) {
    return (first && !second) || (!first && second);
}
