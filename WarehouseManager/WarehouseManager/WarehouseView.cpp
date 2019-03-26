#include "WarehouseView.h"

WarehouseView::WarehouseView() {
	this->currentWarehouse = nullptr;
	this->currentFloor = nullptr;

	setSprites();
}

WarehouseView::WarehouseView(const Warehouse* warehousePtr) : currentWarehouse(warehousePtr) {
	setSprites();
}

void WarehouseView::setSprites()
{
	sf::Image img;
	img.create(tileDrawSize, tileDrawSize, sf::Color::White);
	this->whiteTexture.loadFromImage(img);

	this->noShelfSprite.setTexture(whiteTexture);

	this->emptyShelfSprite.setTexture(whiteTexture);
	emptyShelfSprite.setColor(sf::Color::Yellow);

	this->occupiedShelfSprite.setTexture(whiteTexture);
	occupiedShelfSprite.setColor(sf::Color::Blue);

	this->truckSprite.setTexture(whiteTexture);
	truckSprite.setColor(sf::Color::Red);
}

void WarehouseView::setWarehouse(const Warehouse* warehousePtr) {
	this->currentWarehouse = warehousePtr;
	setCurrentlyDisplayedFloor(0);
}

void WarehouseView::setCurrentlyDisplayedFloor(uint32_t floorId) {
	if (currentWarehouse) {
		this->currentFloor = this->currentWarehouse->getFloor(floorId);
	}
}

void WarehouseView::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	if (this->currentFloor && visible) {

		for (uint32_t row = 0; row < this->currentFloor->getWidth(); ++row) {
			states.transform = sf::Transform::Identity;
			states.transform.translate(row * tileDrawSize, 0);
			for (uint32_t col = 0; col < this->currentFloor->getHeight(); ++col) {
				if (currentFloor->getTruck(row, col) != nullptr)
				{
					target.draw(truckSprite, states);
					states.transform.translate(0, tileDrawSize);
				}
				else
				{
					Floor::Tile currentTile = this->currentFloor->getTile(row, col);
					if (currentTile == Floor::Tile::NoShelf) {
						target.draw(noShelfSprite, states);
					}
					else if (currentTile == Floor::Tile::EmptyShelf) {
						target.draw(emptyShelfSprite, states);
					}
					else if (currentTile == Floor::Tile::OccupiedShelf) {
						target.draw(occupiedShelfSprite, states);
					}
					states.transform.translate(0, tileDrawSize);
				}
			}
		}


	}
}

void WarehouseView::handleEvent(sf::Event event) {
	if (!this->currentFloor || !visible) {
		return;
	}
	goodsCollectionView.handleEvent(event);

	if (event.type == sf::Event::MouseButtonReleased) {
		if (event.mouseButton.button == sf::Mouse::Left) {
			sf::Vector2f clickPos(event.mouseButton.x, event.mouseButton.y);
			if (!goodsCollectionView.getRect().contains(clickPos)) {
				const GoodsCollection* goodsCollection = currentFloor->getGoodsCollection(event.mouseButton.x / 32, event.mouseButton.y / 32);
				if (goodsCollection) {
					goodsCollectionView.setGoodsCollection(goodsCollection);
					controller->setGoodsCollection(currentFloor->getId(), event.mouseButton.x / 32, event.mouseButton.y / 32);
				}
			}
		}
	}
}

void WarehouseView::update(float seconds) {
	goodsCollectionView.update(seconds);
}

void WarehouseView::setVisible(bool val) {
	visible = val;
}

GoodsCollectionView* WarehouseView::getGoodsCollectionView() {
	return &goodsCollectionView;
}

GoodView* WarehouseView::getGoodView() {
	return goodsCollectionView.getGoodView();
}

void WarehouseView::setController(WarehouseController* controller) {
	this->controller = controller;
	this->goodsCollectionView.setController(controller->getGoodsCollectionController());
	this->goodsCollectionView.getGoodView()->setController(controller->getGoodController());
}
