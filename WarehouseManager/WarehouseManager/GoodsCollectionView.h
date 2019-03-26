#pragma once
#include <SFGUI/Widgets.hpp>
#include <SFML/Window.hpp>
#include "GoodsCollection.h"
#include "GoodView.h"
#include "GoodsCollectionController.h"

class GoodsCollectionView {
private:
	const GoodsCollection* goodsCollection;
	GoodsCollectionController* controller;
	GoodView goodView;
	shared_ptr<sfg::Window> mainWindow;
	shared_ptr<sfg::Box> mainWindowBox;
	shared_ptr<sfg::ScrolledWindow> scrolledWindow;
	shared_ptr<sfg::Box> scrolledWindowBox;
	shared_ptr<sfg::Button> addGoodButton;
	void fillWindow();
public:
	GoodsCollectionView();
	GoodsCollectionView(GoodsCollection* goodsCollection);
	void setGoodsCollection(const GoodsCollection* goodsCollection);
	void setVisible(bool val);
	void update(float seconds);
	void handleEvent(sf::Event event);
	void setController(GoodsCollectionController* controller);
	sf::FloatRect getRect();
	GoodView* getGoodView();
};
