#pragma once
#include <cstdint>
#include <vector>
#include "GoodInformation.h"

using namespace std;

class Good {
private:
	static size_t idCounter;
	size_t id;
	GoodInformation goodInfo;
	uint32_t quantity;
public:
	Good();
	Good(GoodInformation goodInfo, uint32_t quantity);
	void setQuantity(uint32_t newQuantity);
	void setName(string newName);
	void setWeight(float newWeight);
	string getName() const;
	float getWeight() const;
	uint32_t getQuantity() const;
	const size_t getId() const;
};
