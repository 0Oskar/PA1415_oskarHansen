#include "catch.hpp"
#include "GoodsCollectionController.h"

TEST_CASE("GoodsCollectionController can set a GoodsCollection reference", "[GoodsCollection]") {
	GoodsCollectionController controller;
	GoodsCollection collection(0);

	controller.setGoodsCollection(&collection);
	REQUIRE(controller.getGoodsCollection() == &collection);
	controller.setGoodsCollection(nullptr);
	REQUIRE(controller.getGoodsCollection() == nullptr);
}
