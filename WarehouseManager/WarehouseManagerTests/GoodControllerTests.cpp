#include "catch.hpp"
#include "GoodController.h"

TEST_CASE("GoodControllers can set a Good reference", "[Good]") {
	GoodController controller;
	Good good(GoodInformation("TestGood", 99), 100);

	controller.setGood(&good);
	REQUIRE(controller.getGood() == &good);
	controller.setGood(nullptr);
	REQUIRE(controller.getGood() == nullptr);
}

TEST_CASE("GoodControllers can set a Goods properties", "[Good], [Controller]") {
	GoodController controller;
	GoodController nullController;
	Good good(GoodInformation("TestGood", 99), 100);

	controller.setGood(&good);
	nullController.setGood(nullptr);

	SECTION("GoodControllers can set a Goods name") {
		controller.setName("TestPassed");
		REQUIRE(good.getName() == "TestPassed");
		nullController.setName("");
	}


	SECTION("GoodControllers can set a Goods quantity") {
		controller.setQuantity(1);
		REQUIRE(good.getQuantity() == 1);
		nullController.setQuantity(1);
	}

	SECTION("GoodControllers can set a Goods weight") {
		controller.setWeight(1);
		REQUIRE(good.getWeight() == 1);
		nullController.setWeight(1);
	}
}