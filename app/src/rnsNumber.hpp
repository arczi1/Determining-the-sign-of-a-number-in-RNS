#pragma once

#include <vector>

class RNSNumber
{
public:
    RNSNumber(int number, std::vector<int> base);
    RNSNumber(std::vector<int> residues, std::vector<int> base);

    std::vector<int> getResidues();
    std::vector<int> getBase();

private:
    std::vector<int> residues;
    std::vector<int> base;
};
