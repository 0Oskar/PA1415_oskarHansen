#pragma once
#include "Good.h"

class GoodController {
private:
	Good* good;
public:
	void setGood(Good* good);
	void setQuantity(uint32_t newQuantity);
	void setWeight(float newWeight);
	void setName(string newName);
	void setLock(bool newLockStatus);
	Good* getGood();
};
