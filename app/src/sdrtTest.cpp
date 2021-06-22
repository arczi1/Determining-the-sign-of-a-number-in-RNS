#include "../catch/catch.h"
#include "mathHelp.hpp"
#include "rnsNumber.hpp"
#include "sdrt.hpp"

#include <vector>

const std::string testGroup{ "SDRT algorithm Test" };

TEST_CASE("SDRT determines correct positive sign 1", testGroup) {
    auto residues{ std::vector<int>{3, 4, 3, 0} }; 
    auto base{ std::vector<int>{8, 7, 5, 3} };
    RNSNumber sut{ residues, base }; // 123

    REQUIRE(determineSignUsignSDRT(sut) == 1);
};

TEST_CASE("SDRT determines correct positive sign 2", testGroup) {
    auto residues{ std::vector<int>{5, 5, 0, 2} }; 
    auto base{ std::vector<int>{8, 7, 5, 3} };
    RNSNumber sut{ residues, base }; // 5

    REQUIRE(determineSignUsignSDRT(sut) == 1);
};

TEST_CASE("SDRT determines correct positive sign 3", testGroup) {
    auto residues{ std::vector<int>{5, 0, 1, 0} }; 
    auto base{ std::vector<int>{8, 7, 5, 3} };
    RNSNumber sut{ residues, base }; // 21

    REQUIRE(determineSignUsignSDRT(sut) == 1);
};

TEST_CASE("SDRT determines correct negative sign 1", testGroup) {
    auto residues{ std::vector<int>{7, 6, 4, 2} }; 
    auto base{ std::vector<int>{8, 7, 5, 3} };
    RNSNumber sut{ residues, base }; // -1

    REQUIRE(determineSignUsignSDRT(sut) == 0);
};

TEST_CASE("SDRT determines correct negative sign 2", testGroup) {
    auto residues{ std::vector<int>{4, 2, 1} }; 
    auto base{ std::vector<int>{5, 3, 2} };
    RNSNumber sut{ residues, base }; // -1

    REQUIRE(determineSignUsignSDRT(sut) == 0);
};

TEST_CASE("SDRT determines correct negative sign 3", testGroup) {
    auto residues{ std::vector<int>{3, 2, 0, 1} }; 
    auto base{ std::vector<int>{8, 7, 5, 3} };
    RNSNumber sut{ residues, base }; // -5

    REQUIRE(determineSignUsignSDRT(sut) == 0);
};