#include "GoodsCollection.h"

GoodsCollection::GoodsCollection(uint32_t id) : id(id) {

}

void GoodsCollection::addGood(Good&& good) {
	this->goods.push_back(good);
}

bool GoodsCollection::removeGood(uint32_t index) {
	if (index < goods.size()) {
		goods.erase(goods.begin() + index);
	}
	return index <= goods.size();
}

Good* GoodsCollection::getGood(uint32_t index) {
	return &goods[index];
}

const vector<Good>& GoodsCollection::getGoods() const {
	return goods;
}
