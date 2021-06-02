#include "rnsNumber.hpp"

RNSNumber::RNSNumber(int number, std::vector<int> base)
        : base(base) {
        
            for(auto element : base)
            {
                residues.push_back(number % element);
            }
    }

RNSNumber::RNSNumber(std::vector<int> residues, std::vector<int> base)
        : residues(residues), base(base) {

    }       

std::vector<int> RNSNumber::getResidues() {
    return residues;
}

std::vector<int> RNSNumber::getBase() {
    return base;
}
