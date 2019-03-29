#pragma once
#include "Warehouse.h"
#include "GoodsCollectionController.h"
#include"TruckController.h"

class WarehouseController {
private:
	Warehouse* warehouse;
	GoodsCollectionController goodsCollectionController;
	TruckController truckController;

public:
	void setWarehouse(Warehouse* warehouse);
	void setGoodsCollection(uint32_t floor, uint32_t xPos, uint32_t yPos);
	GoodsCollectionController* getGoodsCollectionController();
	GoodController* getGoodController();
	Warehouse* getWarehouse();
	void setTruck(uint32_t floor, uint32_t xPos, uint32_t yPos);
	TruckController* getTruckController();
};