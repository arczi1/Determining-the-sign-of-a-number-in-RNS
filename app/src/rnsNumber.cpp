#include "rnsNumber.hpp"

RNSNumber::RNSNumber(int number, std::vector<int> moduli)
        : moduli(moduli) {
        // to do: conversion from decimal
    }

RNSNumber::RNSNumber(std::vector<int> residues, std::vector<int> moduli)
        : residues(residues), moduli(moduli) {

    }

std::vector<int> RNSNumber::getResidues() {
    return residues;
}

std::vector<int> RNSNumber::getModuli() {
    return moduli;
}
