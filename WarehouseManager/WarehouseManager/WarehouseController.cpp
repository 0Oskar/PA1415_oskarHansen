#include "WarehouseController.h"

void WarehouseController::setWarehouse(Warehouse* warehouse) {
	this->warehouse = warehouse;
}

void WarehouseController::setGoodsCollection(uint32_t floor, uint32_t xPos, uint32_t yPos) {
	this->goodsCollectionController.setGoodsCollection(warehouse->getGoodsCollection(floor, xPos, yPos));
}

GoodsCollectionController* WarehouseController::getGoodsCollectionController() {
	return &goodsCollectionController;
}

GoodController* WarehouseController::getGoodController() {
	return goodsCollectionController.getGoodController();
}

Warehouse* WarehouseController::getWarehouse() {
	return warehouse;
}

TruckController*  WarehouseController::getTruckController()
{
	return &this->truckController;
}

void WarehouseController::setTruck(uint32_t floor, uint32_t xPos, uint32_t yPos)
{
	this->truckController.setTruck(warehouse->getTruck(floor, xPos, yPos));

}