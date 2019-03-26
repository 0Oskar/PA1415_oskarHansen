#include "catch.hpp"
#include "Warehouse.h"

TEST_CASE("Warehouses can be constructed", "[Warehouse]") {
	Warehouse warehouse0;
	Warehouse warehouse1;
	Warehouse warehouse2;

	SECTION("Warehouse id gets assigned properly") {
		REQUIRE(warehouse1.getId() == warehouse0.getId() + 1);
		REQUIRE(warehouse2.getId() == warehouse0.getId() + 2);
	}
}

TEST_CASE("Warehouse can be edited", "[Warehouse]") {
	Warehouse warehouse;

	REQUIRE(warehouse.addFloor(40, 40) == 0);
	REQUIRE(warehouse.addFloor(40, 40) == 1);
	REQUIRE(warehouse.addFloor(40, 40) == 2);
	
	REQUIRE(warehouse.addShelf(0, 1, 1));
	REQUIRE(warehouse.addShelf(1, 1, 1));
	REQUIRE(warehouse.addShelf(2, 1, 1));
	
	REQUIRE(warehouse.removeShelf(2, 1, 1));

	REQUIRE(warehouse.addGoodsCollection(0, 1, 1));

	REQUIRE(warehouse.addGood(0, 1, 1, Good(GoodInformation("TestGood", 1), 10)));
	
	REQUIRE(warehouse.removeGood(0, 1, 1, 0));
	
	REQUIRE(warehouse.removeGoodsCollection(0, 1, 1));
	
}
