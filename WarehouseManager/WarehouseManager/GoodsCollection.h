#pragma once
#include <cstdint>
#include <vector>
#include "Good.h"

using namespace std;

class GoodsCollection {
private:
	const uint32_t id;
	vector<Good> goods;
public:
	GoodsCollection(uint32_t id);
	void addGood(Good&& good);
	bool removeGood(uint32_t index);
	Good* getGood(uint32_t index);
	const vector<Good>& getGoods() const;
};
