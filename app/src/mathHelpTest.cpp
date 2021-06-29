#include "../catch/catch.h"
#include "mathHelp.hpp"
#include "rnsNumber.hpp"

#include <vector>

const std::string testGroup{ "Math help Test" };

TEST_CASE("Modulo is calculated properly", testGroup) {
    REQUIRE(MathHelp::modulo(12, 5) == 2);
    REQUIRE(MathHelp::modulo(13, 4) == 1);
    REQUIRE(MathHelp::modulo(12, 4) == 0);
    REQUIRE(MathHelp::modulo(12, 7) == 5);
}

TEST_CASE("Tensor product of modulos is calculated properly", testGroup) {
    REQUIRE(MathHelp::tensorProduct(5, 4, 3) == 2);
    REQUIRE(MathHelp::tensorProduct(2, 3, 7) == 6);
}

TEST_CASE("Tensor product of rns numbers is calculated properly", testGroup) {
    auto residues1{ std::vector<int>{3, 4, 3, 0} }; // 123
    auto residues2{ std::vector<int>{5, 5, 0, 2} }; // 5
    auto base{ std::vector<int>{8, 7, 5, 3} };
    RNSNumber sut1{ residues1, base };
    RNSNumber sut2{ residues2, base };

    REQUIRE(MathHelp::tensorProduct(sut1, sut2).getResidues() == std::vector<int>{7, 6, 0, 0});
}

TEST_CASE("Multiplication of wideOneMatrixes (first horizontal, second vertical) is calculated properly", testGroup) {
    MathHelp::WideOneMatrix first{std::vector<int>{1, 2, 3}, MathHelp::WideOneMatrix::Direction::horizontal};
    MathHelp::WideOneMatrix second{std::vector<int>{3, 2, 1}, MathHelp::WideOneMatrix::Direction::vertical};

    REQUIRE(MathHelp::multiplication(first, second) == 10);
}

TEST_CASE("Transpose of wideOneMatrixes", testGroup) {
    MathHelp::WideOneMatrix sut{std::vector<int>{1, 2, 3}, MathHelp::WideOneMatrix::Direction::horizontal};
    MathHelp::WideOneMatrix sutAfterTranspose = MathHelp::transpose(sut);
    REQUIRE(sutAfterTranspose.direction == MathHelp::WideOneMatrix::Direction::vertical);
}

TEST_CASE("XOR of two bits", testGroup) {
    bool one{true};
    bool zero{false};
    REQUIRE(MathHelp::XOR(zero, zero) == zero);
    REQUIRE(MathHelp::XOR(zero, one) == one);
    REQUIRE(MathHelp::XOR(one, zero) == one);
    REQUIRE(MathHelp::XOR(one, one) == zero);
}

TEST_CASE("W constant calculation", testGroup){
    std::vector<int> base = {16, 15, 13};
    std::vector<int> residues = {11,  7, 11};

    REQUIRE(MathHelp::countW(base).getBase()==base);
    REQUIRE(MathHelp::countW(base).getResidues()==residues);
}
