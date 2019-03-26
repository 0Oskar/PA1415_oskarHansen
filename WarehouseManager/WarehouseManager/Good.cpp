#include "Good.h"

size_t Good::idCounter = 0;

Good::Good() : quantity(0), id(idCounter++), locked(false) {

}

Good::Good(GoodInformation goodInfo, uint32_t quantity) : goodInfo(goodInfo), quantity(quantity), id(idCounter++), locked(false) {

}

void Good::setQuantity(uint32_t newQuantity) {
	this->quantity = newQuantity;
}

void Good::setWeight(float newWeight) {
	this->goodInfo.setWeight(newWeight);
}

void Good::setName(string newName) {
	this->goodInfo.setName(newName);
}

string Good::getName() const {
	return goodInfo.getName();
}

float Good::getWeight() const {
	return goodInfo.getWeight();
}

uint32_t Good::getQuantity() const {
	return quantity;
}

const size_t Good::getId() const {
	return id;
}

const bool Good::isLocked()
{
	return this->locked;
}

void Good::setLock(bool lock)
{
	this->locked = lock;
}