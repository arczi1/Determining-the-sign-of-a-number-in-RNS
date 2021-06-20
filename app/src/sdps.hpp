#pragma once

#include "rnsNumber.hpp"
#include "mathHelp.hpp"
#include <math.h>

enum class Sign {
    Plus,
    Minus
};

int determineSignUsignSDPS(RNSNumber x) {
    int sign = 1;
    int tail = 0;
    int gx_k{};
    int low{};
    int high{};
    int carry{};
    int sum{};
    constexpr int bitsInByte = 8;
    int w = sizeof(int) * bitsInByte; 
    const RNSNumber W{MathHelp::countW(x.getBase())};
    
    //0
    MathHelp::WideOneMatrix E{};
    E.numbers = MathHelp::tensorProduct(x, W).getResidues();
    E.direction = MathHelp::WideOneMatrix::Direction::vertical;

    //1
      std::vector<int> ones;
    for (int i = 0; i < E.numbers.size(); i++)
    {
        ones.push_back(1);
    }
    MathHelp::WideOneMatrix onesHorizontal{};
    onesHorizontal.numbers = ones;
    onesHorizontal.direction = MathHelp::WideOneMatrix::Direction::horizontal;
    gx_k = MathHelp::multiplication(onesHorizontal, E);

    //2
    // low <- <gx_k>_(2^w)
    low = MathHelp::modulo(gx_k, pow(2, w));
    //3
    //sign <- low>>(w-1)
    sign = low >> (w-1); 
    //4
    if(sign == 0) {
        low += pow(2, w-1); 
    }
    //5
    for(int k=1; /* k != n; k++*/;) {
        //6
        //u is an integer in range 0<=u<=2^[w/2]
        std::vector<int> ui;
        for (int i = 0; i < x.getBase().size(); i++) {
            ui.push_back(pow(2, w) - x.getBase().at(i));
        }
        MathHelp::WideOneMatrix usHorizontal{};
        usHorizontal.numbers = ui;
        usHorizontal.direction = MathHelp::WideOneMatrix::Direction::horizontal;
        gx_k = MathHelp::multiplication(usHorizontal, E);

        //7
        high = gx_k >> w;
        //8
        int z = high + low; 
        //9
        sum = MathHelp::modulo(z, pow(2,w));
        //10
        carry = z >> w;
        //11
        if((carry == 1) || (sum != (pow(2, w)-1))) {
            sign = sign xor carry; //12
            return sign;           //13
        }
        //15
        low = MathHelp::modulo(gx_k, pow(2, w));       
    }
      
    return sign;
}