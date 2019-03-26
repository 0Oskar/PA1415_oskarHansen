#pragma once
#include <cstdint>
#include <vector>
#include "GoodsCollection.h"
#include <SFML/System.hpp>
#include <map>
#include"truck.h"
using namespace std;

namespace {
	struct vecComp {
		bool operator()(sf::Vector2u a, sf::Vector2u b) const {
			bool returnVal = a.x < b.x;
			if (a.x == b.x) {
				returnVal = a.y < b.y;
			}
			return returnVal;
		}
	};
}

class Floor {
public:
	enum Tile {
		NoShelf,
		EmptyShelf,
		OccupiedShelf,
		Error
	};
private:
	uint32_t width;
	uint32_t height;
	const uint32_t id;
	uint32_t goodsCollectionIdCounter = 0;
	vector<vector<Tile>> tileMap;
	map<sf::Vector2u, GoodsCollection, vecComp> goodsCollections;
	vector<Truck> trucks;
public:
	Floor(uint32_t id, uint32_t width, uint32_t height);
	bool addGoodsCollection(uint32_t xPos, uint32_t yPos);
	const GoodsCollection* getGoodsCollection(uint32_t xPos, uint32_t yPos) const;
	GoodsCollection* getGoodsCollection(uint32_t xPos, uint32_t yPos);
	bool addGood(uint32_t xPos, uint32_t yPos, Good good);
	bool addShelf(uint32_t xPos, uint32_t yPos);
	bool removeGoodsCollection(uint32_t xPos, uint32_t yPos);
	bool removeGood(uint32_t xPos, uint32_t yPos, uint32_t goodIndex);
	bool removeShelf(uint32_t xPos, uint32_t yPos);
	uint32_t getId() const;
	uint32_t getWidth() const;
	uint32_t getHeight() const;
	Tile getTile(uint32_t xPos, uint32_t yPos) const throw(...);
	bool addTruck(uint32_t xPos, uint32_t yPos);
	const Truck* getTruck(uint32_t xPos, uint32_t yPos) const;
	Truck* getTruck(uint32_t xPos, uint32_t yPos);

};
