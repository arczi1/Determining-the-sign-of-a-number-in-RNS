#include "rnsNumber.hpp"

RNSNumber::RNSNumber(int number, std::vector<int> base)
        : base(base) {
        // to do: conversion from decimal
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
