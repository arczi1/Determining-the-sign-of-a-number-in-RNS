#pragma once

#include "rnsNumber.hpp"
#include "mathHelp.hpp"

int determineSignUsignSDRT(RNSNumber x) {   
    const RNSNumber W = MathHelp::countW(x.getBase());
    int numberOfElements = x.getResidues().size();
    
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
    int h1 = MathHelp::multiplication(onesHorizontal, E);

    //2
    int w = 4;    
    int twoToThePowerOfW = static_cast<int>(pow(2, w));
    std::vector<int> us;
    for (int i = 0; i < numberOfElements; i++)
    {
        us.push_back(twoToThePowerOfW - x.getBase().at(i));
    }
    MathHelp::WideOneMatrix usHorizontal{
        .numbers = us,
        .direction = MathHelp::WideOneMatrix::Direction::horizontal
    };
    int h2 = MathHelp::multiplication(usHorizontal, E);
    
    //3
    int tail = 0;
    int h3{};
    int body{};
    int tmp{};
    int carry{};
    int sum{};
    int sign = 1;
    int n = 3;
    int d = n + 3;
    for(int k = 3; k < d; k++) { 
        //4
        h1 = h2;
        
        //5
        h2 = h3;
        
        //6 tutaj jest to h z reciprocal table chyba
        int hk = 0; 
        //int hi = ((1/x.getBase().at(hk)) - ()) * pow(2, w * hk);
        //h3 =;
        
        //7
        if(k == 3) {
            //8
            body = h1 + (h2 >> w) + (h3 >> (2*w));
            //9
            tail = MathHelp::modulo(body, 2);
            //10
            int sum = MathHelp::modulo(body, twoToThePowerOfW);
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
            tmp = ((body + static_cast<int>(tail * twoToThePowerOfW)) >> 1);
            //18
            tail = MathHelp::modulo(body, 2);
            //19
            carry = (tmp >> w);
            //20
            sum = MathHelp::modulo(tmp, twoToThePowerOfW);
            //21, 22, 23, 24
            if(carry == 1 || sum != (twoToThePowerOfW - 1)) {
                sign = sign ^ carry; // sign moze byc 1 albo 0, tak samo carry
                return sign;
            }
        } 
    }
    //27
    return sign;
}