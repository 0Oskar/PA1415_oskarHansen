#include "Floor.h"

Floor::Floor(uint32_t id, uint32_t width, uint32_t height) : id(id), width(width), height(height) {
	this->tileMap.resize(width);
	for (vector<Tile>& col : this->tileMap) {
		col.resize(height);
	}
	auto hasher = [](sf::Vector2u a, sf::Vector2u b) { return ((a.x * 7 + b.x * 11) + (a.y * 13 + b.y * 17)) % 10001; };
}

bool Floor::addGoodsCollection(uint32_t xPos, uint32_t yPos) {
	bool success = false;
	if (tileMap[xPos][yPos] == Tile::EmptyShelf) {
		this->goodsCollections.insert(make_pair(sf::Vector2u(xPos, yPos), GoodsCollection(goodsCollectionIdCounter++)));
		tileMap[xPos][yPos] = Tile::OccupiedShelf;
		success = true;
	}

	return success;
}

const GoodsCollection* Floor::getGoodsCollection(uint32_t xPos, uint32_t yPos) const {
	if (goodsCollections.count(sf::Vector2u(xPos, yPos))) {
		return &goodsCollections.at(sf::Vector2u(xPos, yPos));
	}
	else {
		return nullptr;
	}
}

GoodsCollection* Floor::getGoodsCollection(uint32_t xPos, uint32_t yPos) {
	if (goodsCollections.count(sf::Vector2u(xPos, yPos))) {
		return &goodsCollections.at(sf::Vector2u(xPos, yPos));
	}
	else {
		return nullptr;
	}
}

bool Floor::addGood(uint32_t xPos, uint32_t yPos, Good good) {
	GoodsCollection* collection = nullptr;

	if (goodsCollections.count(sf::Vector2u(xPos, yPos))) {
		collection = &goodsCollections.at(sf::Vector2u(xPos, yPos));
		collection->addGood(std::move(good));
	}

	return collection != nullptr;
}

bool Floor::addShelf(uint32_t xPos, uint32_t yPos) {
	if (this->tileMap[xPos][yPos] == NoShelf) {
		tileMap[xPos][yPos] = Tile::EmptyShelf;
	}

	return tileMap[xPos][yPos] == Tile::EmptyShelf;
}

bool Floor::removeShelf(uint32_t xPos, uint32_t yPos) {
	if (this->tileMap[xPos][yPos] == EmptyShelf) {
		tileMap[xPos][yPos] = Tile::NoShelf;
	}

	return tileMap[xPos][yPos] == Tile::NoShelf;
}

bool Floor::removeGoodsCollection(uint32_t xPos, uint32_t yPos) {
	return goodsCollections.erase(sf::Vector2u(xPos, yPos));
}

bool Floor::removeGood(uint32_t xPos, uint32_t yPos, uint32_t goodIndex) {
	return goodsCollections.at(sf::Vector2u(xPos, yPos)).removeGood(goodIndex);
}

uint32_t Floor::getId() const {
	return this->id;
}

uint32_t Floor::getWidth() const {
	return this->width;
}

uint32_t Floor::getHeight() const {
	return this->height;
}

Floor::Tile Floor::getTile(uint32_t xPos, uint32_t yPos) const throw(...) {
	if (this->width <= xPos && this->height <= yPos) {
		throw "Tried to get out of bounds tile";
	}

	return tileMap[xPos][yPos];
}


bool Floor::addTruck(uint32_t xPos, uint32_t yPos)
{

	this->trucks.push_back(Truck(sf::Vector2u(xPos, yPos)));


	return true;
}
const Truck* Floor::getTruck(uint32_t xPos, uint32_t yPos) const
{
	for (int truckNr = 0; truckNr < this->trucks.size(); truckNr++)
	{
		if (this->trucks.at(truckNr).getCurrentPos() == sf::Vector2u(xPos, yPos))
		{
			return &this->trucks.at(truckNr);
		}
	}

	return nullptr;
}

Truck* Floor::getTruck(uint32_t xPos, uint32_t yPos)
{
	for (int truckNr = 0; truckNr < this->trucks.size(); truckNr++)
	{
		if (this->trucks.at(truckNr).getCurrentPos() == sf::Vector2u(xPos, yPos))
		{
			return &this->trucks.at(truckNr);
		}
	}

	return nullptr;
}