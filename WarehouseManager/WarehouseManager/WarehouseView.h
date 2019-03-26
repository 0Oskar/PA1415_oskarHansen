#pragma once
#include "Warehouse.h"
#include <SFML/Graphics.hpp>
#include "GoodsCollectionView.h"
#include "GoodView.h"
#include "WarehouseController.h"

class WarehouseView : public sf::Drawable {
private:
	const Warehouse* currentWarehouse;
	const Floor* currentFloor;
	WarehouseController* controller;
	GoodsCollectionView goodsCollectionView;
	uint32_t tileDrawSize = 32;
	sf::Texture whiteTexture;
	sf::Sprite noShelfSprite;
	sf::Sprite emptyShelfSprite;
	sf::Sprite occupiedShelfSprite;
	bool visible = false;
public:
	WarehouseView();
	WarehouseView(const Warehouse* warehousePtr);
	void setWarehouse(const Warehouse* warehousePtr);
	void setCurrentlyDisplayedFloor(uint32_t floorId);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void handleEvent(sf::Event);
	void update(float seconds);
	void setVisible(bool val);
	void setController(WarehouseController* controller);
	GoodsCollectionView* getGoodsCollectionView();
	GoodView* getGoodView();
};
