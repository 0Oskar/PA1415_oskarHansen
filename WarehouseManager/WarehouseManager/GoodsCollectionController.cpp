#include "GoodsCollectionController.h"

void GoodsCollectionController::addGood(Good good) {
	if (goodsCollection) {
		goodsCollection->addGood(std::move(good));
	}
}

void GoodsCollectionController::setGood(uint32_t index) {
	goodController.setGood(goodsCollection->getGood(index));
}

void GoodsCollectionController::setGoodsCollection(GoodsCollection* newGoodsCollection) {
	goodsCollection = newGoodsCollection;
}

GoodController* GoodsCollectionController::getGoodController() {
	return &goodController;
}

GoodsCollection* GoodsCollectionController::getGoodsCollection() {
	return goodsCollection;
}