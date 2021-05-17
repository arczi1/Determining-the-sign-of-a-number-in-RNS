#pragma once

#include <vector>

class RNSNumber
{
public:
    RNSNumber(int number, std::vector<int> moduli);
    RNSNumber(std::vector<int> residues, std::vector<int> moduli);

    std::vector<int> getResidues();
    std::vector<int> getModuli();

private:
    std::vector<int> residues;
    std::vector<int> moduli;
};
