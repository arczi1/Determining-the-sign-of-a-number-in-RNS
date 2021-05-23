#include "../catch/catch.h"
#include "mathHelp.hpp"
#include "rnsNumber.hpp"

#include <vector>

const std::string testGroup{ "Math help Test" };

TEST_CASE("Modulo is calculated properly", testGroup) {
    REQUIRE(modulo(12, 5) == 2);
    REQUIRE(modulo(13, 4) == 1);
    REQUIRE(modulo(12, 4) == 0);
    REQUIRE(modulo(12, 7) == 5);
}

TEST_CASE("Tensor product of modulos is calculated properly", testGroup) {
    REQUIRE(tensorProduct(5, 4, 3) == 2);
    REQUIRE(tensorProduct(2, 3, 7) == 6);
}

TEST_CASE("Tensor product of rns numbers is calculated properly", testGroup) {
    auto residues1{ std::vector<int>{3, 4, 3, 0} }; // 123
    auto residues2{ std::vector<int>{5, 5, 0, 2} }; // 5
    auto base{ std::vector<int>{8, 7, 5, 3} };
    RNSNumber sut1{ residues1, base };
    RNSNumber sut2{ residues2, base };

    REQUIRE(tensorProduct(sut1, sut2).getResidues() == std::vector<int>{7, 6, 0, 0});
}

TEST_CASE("Multiplication of wideOneMatrixes (first horizontal, second vertical) is calculated properly", testGroup) {
    WideOneMatrix first{std::vector<int>{1, 2, 3}, WideOneMatrix::Direction::horizontal};
    WideOneMatrix second{std::vector<int>{3, 2, 1}, WideOneMatrix::Direction::vertical};

    REQUIRE(multiplication(first, second) == 10);
}

TEST_CASE("Transpose of wideOneMatrixes", testGroup) {
    WideOneMatrix sut{std::vector<int>{1, 2, 3}, WideOneMatrix::Direction::horizontal};
    WideOneMatrix sutAfterTranspose = transpose(sut);
    REQUIRE(sutAfterTranspose.direction == WideOneMatrix::Direction::vertical);
}

TEST_CASE("XOR of two bits", testGroup) {
    bool one{true};
    bool zero{false};
    REQUIRE(XOR(zero, zero) == zero);
    REQUIRE(XOR(zero, one) == one);
    REQUIRE(XOR(one, zero) == one);
    REQUIRE(XOR(one, one) == zero);
}
