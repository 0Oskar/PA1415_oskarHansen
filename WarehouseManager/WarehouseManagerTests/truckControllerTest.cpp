#include"catch.hpp"
#include "TruckController.h"



TEST_CASE("TruckController can set a Truck reference", "[Truck]") {
	TruckController controller;
	Truck truck(sf::Vector2u(1, 1));

	controller.setTruck(&truck);
	REQUIRE(controller.getTruck() == &truck);
	controller.setTruck(nullptr);
	REQUIRE(controller.getTruck() == nullptr);
}

TEST_CASE("TruckController can set truck properties", "[Truck], [Controller]") {
	TruckController controller;
	Truck truck(sf::Vector2u(1, 1));

	controller.setTruck(&truck);
	SECTION("TruckController can set and get batterytype") {
		controller.setBatteryType("ion");
		REQUIRE(truck.getBatteryType() == "ion");
	}


	SECTION("TruckController can set and get dateoflatestservice") {
		controller.setDateOfLatestService("1993-12-12");
		REQUIRE(truck.getDateOfLatestService() == "1993-12-12");
	}
	SECTION("TruckController can set and get manufactorer") {
		controller.setTruckManufactor("Linde");
		REQUIRE(truck.getTruckManufactor() == "Linde");
	}
	
}