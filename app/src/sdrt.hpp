#pragma once

#include "rnsNumber.hpp"
#include "mathHelp.hpp"

int determineSignUsignSDRT(RNSNumber x) {   
    const RNSNumber W = MathHelp::countW(x.getBase());
    int numberOfElements = x.getResidues().size();
    
    int w = 4;  
    std::vector<std::vector<int>> h;
    for(int i = 0; i < numberOfElements; i++)
        h.push_back(MathHelp::generateReciprocalTable(x.getBase().at(i), w, numberOfElements));

    //0
    MathHelp::WideOneMatrix E {
        .numbers = MathHelp::tensorProduct(x, W).getResidues(),
        .direction = MathHelp::WideOneMatrix::Direction::vertical
    };

    //1
    MathHelp::WideOneMatrix onesHorizontal {
        .numbers = std::vector<int>(numberOfElements, 1),
        .direction = MathHelp::WideOneMatrix::Direction::horizontal
    };
    int h2 = MathHelp::multiplication(onesHorizontal, E);

    //2
    int h3{};
    for (int i = 0; i < numberOfElements; i++)
    {
        h3 += h.at(i).at(1) * E.numbers.at(i);
    }
        
    //3
    int tail = 0;
    int h1{};
    int body{};
    int tmp{};
    int carry{};
    int sum{};
    int sign = 0;
    int d = numberOfElements + 3;
    int twoToThePowerOfW = static_cast<int>(pow(2, w));
    for(int k = 3; k <= d; k++) { 
        //4, 5
        h1 = h2;
        h2 = h3;
        
        //6        
        for (int i = 0; i < numberOfElements; i++)
        {
            h3 += h.at(i).at(k-1) * E.numbers.at(i);
        }
        
        //7
        if(k == 3) {
            //8
            body = h1 + (h2 >> w) + (h3 >> (2*w));
            //9
            tail = MathHelp::modulo(body, 2);
            //10
            sum = MathHelp::modulo(body, twoToThePowerOfW);
            //11
            sign = sum >> (w - 1);
            //12, 13, 14
            if((MathHelp::modulo(sum, pow(2, w-1)) >> 1) != (pow(2, w-2) - 1)) return sign;
        }
        //15
        else {
            //16
            body = MathHelp::modulo(h1, twoToThePowerOfW) + MathHelp::modulo(h2 >> w, twoToThePowerOfW) + MathHelp::modulo(h3 >> (2*w), twoToThePowerOfW);
            //17
            tmp = ((body + tail * twoToThePowerOfW) >> 1);
            //18
            tail = MathHelp::modulo(body, 2);
            //19
            carry = (tmp >> w);
            //20
            sum = MathHelp::modulo(tmp, twoToThePowerOfW);
            //21, 22, 23, 24
            if((carry == 1) || (sum != (twoToThePowerOfW - 1))) {
                return MathHelp::XOR(sign, carry);
            }
        } 
    }
    //27
    return sign;
}