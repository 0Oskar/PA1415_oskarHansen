#include "Warehouse.h"

uint32_t Warehouse::idCounter = 0;

Warehouse::Warehouse() : id(idCounter++) {

}

uint32_t Warehouse::addFloor(uint32_t width, uint32_t height) {
	this->floors.push_back(Floor(floors.size(), width, height));
	return floors.size() - 1;
}

bool Warehouse::addShelf(uint32_t floorIndex, uint32_t xPos, uint32_t yPos) {
	return floors[floorIndex].addShelf(xPos, yPos);
}

bool Warehouse::addGoodsCollection(uint32_t floorIndex, uint32_t xPos, uint32_t yPos) {
	return this->floors[floorIndex].addGoodsCollection(xPos, yPos);
}

const GoodsCollection* Warehouse::getGoodsCollection(uint32_t floorIndex, uint32_t xPos, uint32_t yPos) const {
	return floors[floorIndex].getGoodsCollection(xPos, yPos);
}

GoodsCollection* Warehouse::getGoodsCollection(uint32_t floorIndex, uint32_t xPos, uint32_t yPos) {
	return floors[floorIndex].getGoodsCollection(xPos, yPos);
}

bool Warehouse::addGood(uint32_t floorIndex, uint32_t xPos, uint32_t yPos, Good good) {
	return floors[floorIndex].addGood(xPos, yPos, good);
}

bool Warehouse::removeGood(uint32_t floorIndex, uint32_t xPos, uint32_t yPos, uint32_t goodIndex) {
	return floors[floorIndex].removeGood(xPos, yPos, goodIndex);
}

bool Warehouse::removeGoodsCollection(uint32_t floorIndex, uint32_t xPos, uint32_t yPos) {
	return floors[floorIndex].removeGoodsCollection(xPos, yPos);
}

bool Warehouse::removeShelf(uint32_t floorIndex, uint32_t xPos, uint32_t yPos) {
	return floors[floorIndex].removeShelf(xPos, yPos);
}

void Warehouse::setIdCounter(uint32_t value) {
	Warehouse::idCounter = value;
}

uint32_t Warehouse::getId() const {
	return this->id;
}

const Floor* Warehouse::getFloor(uint32_t floorIndex) const {
	return &floors[floorIndex];
}

Floor* Warehouse::getFlor(uint32_t floorIndex)
{
	return &floors[floorIndex];
}

bool Warehouse::addTruck(uint32_t floorIndex, uint32_t xPos, uint32_t yPos)
{
	this->floors[floorIndex].addTruck(xPos, yPos);

	return true;
}
const Truck* Warehouse::getTruck(uint32_t floorIndex, uint32_t xPos, uint32_t yPos) const
{
	return this->floors[floorIndex].getTruck(xPos, yPos);
}

Truck* Warehouse::getTruck(uint32_t floorIndex, uint32_t xPos, uint32_t yPos) 
{
	return this->floors[floorIndex].getTruck(xPos, yPos);

}
void Warehouse::update(float sec)
{
	for (int i = 0; i < floors.size(); i++)
	{
		this->floors[i].update(sec);
	}
}