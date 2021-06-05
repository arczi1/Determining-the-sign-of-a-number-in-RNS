#include "mathHelp.hpp"
#include "rnsNumber.hpp"

#include <iostream>
#include <cmath>

namespace MathHelp {
    
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

RNSNumber countW(std::vector<int> base) {
    int M = 1;
    for (int i = 0; i < base.size(); i++)
    {
        M *= base.at(i);
    }
    std::vector<int> residues;
    for (int i = 0; i < base.size(); i++)
    {
        residues.push_back(MathHelp::modulo(1/(M/base.at(i)), base.at(i)));
    }
    return RNSNumber{ residues, base };
}

std::vector<int> generateHVec(int k, int w) {
    return {};
}

int generateHElement(int k, int w, RNSNumber x) {
    if(k == 1) return 1;
    if(k == 2) return pow(2, w) - x.getBase().at(k); // s is close to 2^w/2, so h_i(2) = u_i holds with a very high probability
    //int hi = ((1/x.getBase().at(k)) - (generateHElement(k - 1, w, x) * (1 / pow(2, /*j**/w)))) * pow(2, w * k);
    return 0;
}

}