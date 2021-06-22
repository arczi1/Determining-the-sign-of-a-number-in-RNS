#pragma once

#include "rnsNumber.hpp"

#include <iostream>
namespace MathHelp {
    
int modulo(int num, int divider);
int tensorProduct(int num1, int num2, int divider);
RNSNumber tensorProduct(RNSNumber num1, RNSNumber num2);

struct WideOneMatrix {
    enum class Direction {
        horizontal,
        vertical,
    };

    std::vector<int> numbers;
    Direction direction;
};

int multiplication(WideOneMatrix first, WideOneMatrix second);
WideOneMatrix transpose(WideOneMatrix matrix);
bool XOR(bool first, bool second);
RNSNumber countW(std::vector<int> base);
std::vector<int> generateReciprocalTable(int m_i, int w, int len);
}
