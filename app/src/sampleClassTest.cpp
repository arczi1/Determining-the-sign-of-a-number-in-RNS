#include "../catch/catch.h"
#include "sampleClass.hpp"

const std::string testGroup{ "Sample Class Test" };

TEST_CASE("sampleClass returns true", testGroup) {
    SampleClass sut;
    REQUIRE(sut.returnTrue() == true);
}