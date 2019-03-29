#include"catch.hpp"
#include "Truck.h"



TEST_CASE("Truck creation test", "[Truck]") {
	sf::Vector2u posToSet(0, 0);
	Truck truck(posToSet);


	SECTION("Truck pos ok") {
		REQUIRE(truck.getCurrentPos() == posToSet);
	}
}

TEST_CASE("Truck can set truck properties correctly", "[Truck]") {

	Truck truck(sf::Vector2u(1, 1));

	SECTION("TruckController can set and get batterytype") {
		truck.setBatteryType("ion");
		REQUIRE(truck.getBatteryType() == "ion");
	}


	SECTION("TruckController can set and get dateoflatestservice") {
		truck.setDateOfLatestService("1993-12-12");
		REQUIRE(truck.getDateOfLatestService() == "1993-12-12");
	}
	SECTION("TruckController can set and get manufactorer") {
		truck.setTruckManufactor("Linde");
		REQUIRE(truck.getTruckManufactor() == "Linde");
	}

}