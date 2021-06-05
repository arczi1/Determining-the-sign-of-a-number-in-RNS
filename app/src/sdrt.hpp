#pragma once

#include "rnsNumber.hpp"
#include "mathHelp.hpp"

enum class Sign {
    Plus,
    Minus
};

int determineSignUsignSDRT(RNSNumber x) {
    int sign = 1;
    int tail = 0;
    int h3{};
    int body{};
    int tmp{};
    int carry{};
    int sum{};
    constexpr int bitsInByte = 8;
    int w = sizeof(int) * bitsInByte; // tutaj prawdopodobnie ilosc bitow w int;
                                      // w podobno mialo byc dlugoscia slowa, ale czym jest slowo xD
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
    int h1 = MathHelp::multiplication(onesHorizontal, E);

    //2
    std::vector<int> us;
    for (int i = 0; i < x.getBase().size(); i++)
    {
        us.push_back(pow(2, w) - x.getBase().at(i));
    }
    MathHelp::WideOneMatrix usHorizontal{};
    usHorizontal.numbers = us;
    usHorizontal.direction = MathHelp::WideOneMatrix::Direction::horizontal;
    int h2 = MathHelp::multiplication(usHorizontal, E);
    
    //3
    for(int k = 3; /*k != n + 3*/ ;) {
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
            int sum = MathHelp::modulo(body, pow(2, w));
            //11
            sign = sum >> (w - 1);
            //12, 13, 14
            if(MathHelp::modulo(sum, pow(2, w-1)) != (pow(2, w-2) - 1)) return sign;
        }
        //15
        else {
            //16
            body = MathHelp::modulo(h1, pow(2, w)) + MathHelp::modulo(h2 >> w, pow(2, w)) + MathHelp::modulo(h3 >> (2*w), pow(2, w));
            //17
            tmp = ((body + static_cast<int>(tail * pow(2, w))) >> 1);
            //18
            tail = MathHelp::modulo(body, 2);
            //19
            carry = (tmp >> w);
            //20
            sum = MathHelp::modulo(tmp, pow(2,w));
            //21, 22, 23, 24
            if(carry == 1 || sum != (pow(2, w) - 1)) {
                sign = sign xor carry;
                return sign;
            }
        } 
    }
    return sign;
}