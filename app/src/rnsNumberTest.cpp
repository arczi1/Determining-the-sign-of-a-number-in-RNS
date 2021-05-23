#include "../catch/catch.h"
#include "rnsNumber.hpp"

#include <vector>

const std::string testGroup{ "RNS Number Test" };

TEST_CASE("RNS number can be created", testGroup) {
    auto residues{ std::vector<int>{3, 4, 3, 0} }; // 123
    auto base{ std::vector<int>{8, 7, 5, 3} };
    RNSNumber sut{ residues, base };
    REQUIRE(sut.getResidues() == std::vector<int>{3, 4, 3, 0});
    REQUIRE(sut.getBase() == std::vector<int>{8, 7, 5, 3});
}