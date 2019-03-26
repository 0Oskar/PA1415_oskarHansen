#pragma once
#include "GoodsCollection.h"
#include "GoodController.h"

class GoodsCollectionController {
private:
	GoodsCollection* goodsCollection;
	GoodController goodController;
public:
	void addGood(Good good);
	void setGood(uint32_t index);
	void setGoodsCollection(GoodsCollection* newGoodsCollection);
	GoodsCollection* getGoodsCollection();
	GoodController* getGoodController();
};
