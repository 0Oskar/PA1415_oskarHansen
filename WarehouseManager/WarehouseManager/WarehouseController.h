#pragma once
#include "Warehouse.h"
#include "GoodsCollectionController.h"
#include"TruckController.h"

class WarehouseController {
private:
	Warehouse* warehouse;
	GoodsCollectionController goodsCollectionController;

public:
	void setWarehouse(Warehouse* warehouse);
	void setGoodsCollection(uint32_t floor, uint32_t xPos, uint32_t yPos);
	GoodsCollectionController* getGoodsCollectionController();
	GoodController* getGoodController();
	Warehouse* getWarehouse();
};