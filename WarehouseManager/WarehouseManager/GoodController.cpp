#include "GoodController.h"

void GoodController::setGood(Good* good) {
	this->good = good;
}

void GoodController::setQuantity(uint32_t newQuantity) {
	if (good) {
		good->setQuantity(newQuantity);
	}
}

void GoodController::setWeight(float newWeight) {
	if (good) {
		if (newWeight < 0) {
			newWeight = 0;
		}
		good->setWeight(newWeight);
	}
}

void GoodController::setName(string newName) {
	if (good) {
		good->setName(newName);
	}
}

Good* GoodController::getGood() {
	return good;
}

void GoodController::setLock(bool newLockStatus)
{
	if (this->good)
	{
		good->setLock(newLockStatus);
	}
}
