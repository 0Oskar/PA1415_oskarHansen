#include "catch.hpp"
#include "WarehouseController.h"

TEST_CASE("WarehouseController can set a Warehouse reference", "[Warehouse]"){
	WarehouseController controller;
	Warehouse warehouse;
	controller.setWarehouse(&warehouse);
	REQUIRE(controller.getWarehouse() == &warehouse);
	controller.setWarehouse(nullptr);
	REQUIRE(controller.getWarehouse() == nullptr);
}
