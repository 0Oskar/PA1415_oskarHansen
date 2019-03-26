#pragma once
#include <cstdint>
#include <vector>
#include "Floor.h"

using namespace std;

class Warehouse {
private:
	static uint32_t idCounter;
	const uint32_t id;
	vector<Floor> floors;
public:
	explicit Warehouse();
	uint32_t addFloor(uint32_t width, uint32_t height);
	bool addShelf(uint32_t floorIndex, uint32_t xPos, uint32_t yPos);
	/*Requires a shelf at the position*/
	bool addGoodsCollection(uint32_t floorIndex, uint32_t xPos, uint32_t yPos);
	const GoodsCollection* getGoodsCollection(uint32_t floorIndex, uint32_t xPos, uint32_t yPos) const;
	GoodsCollection* getGoodsCollection(uint32_t floorIndex, uint32_t xPos, uint32_t yPos);
	bool addGood(uint32_t floorIndex, uint32_t xPos, uint32_t yPos, Good good);
	bool removeGood(uint32_t floorIndex, uint32_t xPos, uint32_t yPos, uint32_t goodIndex);
	bool removeGoodsCollection(uint32_t floorIndex, uint32_t xPos, uint32_t yPos);
	bool removeShelf(uint32_t floorIndex, uint32_t xPos, uint32_t yPos);
	static void setIdCounter(uint32_t value);
	const Floor* getFloor(uint32_t floorIndex) const;
	uint32_t getId() const;
};
