#include "GoodsCollectionView.h"

GoodsCollectionView::GoodsCollectionView() {
	mainWindow = sfg::Window::Create();
	mainWindow->SetTitle("Goods collection");
	mainWindow->SetStyle(sfg::Window::Style::BACKGROUND | sfg::Window::Style::CLOSE | sfg::Window::Style::TITLEBAR);
	mainWindow->GetSignal(sfg::Window::OnCloseButton).Connect([&] { setGoodsCollection(nullptr); });
	mainWindow->SetRequisition(sf::Vector2f(300, 200));
	mainWindow->SetPosition(sf::Vector2f(400, 400));

	scrolledWindow = sfg::ScrolledWindow::Create();
	scrolledWindowBox = sfg::Box::Create(sfg::Box::Orientation::VERTICAL);
	scrolledWindow->SetRequisition(sf::Vector2f(120, 200));
	scrolledWindow->AddWithViewport(scrolledWindowBox);

	addGoodButton = sfg::Button::Create("Add...");

	mainWindowBox = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL);
	mainWindowBox->Pack(addGoodButton);
	mainWindowBox->Pack(scrolledWindow);
	mainWindowBox->Pack(goodView.getWindow());

	mainWindow->Add(mainWindowBox);

	setVisible(false);
	addGoodButton->GetSignal(sfg::Button::OnLeftClick).Connect([&] {
		if (controller) {
			controller->addGood(Good());
			fillWindow();
		}
	});

	goodView.getSaveButton()->GetSignal(sfg::Button::OnLeftClick).Connect([&] {
		fillWindow();
	});
}

GoodsCollectionView::GoodsCollectionView(GoodsCollection* goodsCollection) {
	this->goodsCollection = goodsCollection;
	scrolledWindow = sfg::ScrolledWindow::Create();
	scrolledWindowBox = sfg::Box::Create();
	scrolledWindow->SetRequisition(sf::Vector2f(100, 100));
	fillWindow();
}

void GoodsCollectionView::fillWindow() {
	scrolledWindowBox->RemoveAll();

	if (goodsCollection) {
		const vector<Good> goods = goodsCollection->getGoods();
		for (uint32_t i = 0; i < goods.size(); ++i) {
			auto newButton = sfg::Button::Create(goods[i].getName());
			newButton->SetRequisition(sf::Vector2f(100, 25));
			newButton->GetSignal(sfg::Button::OnLeftClick).Connect([&, i] {
				controller->setGood(i);
				goodView.setGood(&goodsCollection->getGoods()[i]);
			});
			scrolledWindowBox->Pack(newButton);
		}
	}
}

void GoodsCollectionView::setGoodsCollection(const GoodsCollection* goodsCollection) {
	this->goodsCollection = goodsCollection;
	if (goodsCollection) {
		setVisible(true);
		goodView.setVisible(false);
		fillWindow();
	}
	else {
		setVisible(false);
	}
}

void GoodsCollectionView::setVisible(bool val) {
	mainWindow->Show(val);
}

void GoodsCollectionView::update(float seconds) {
	mainWindow->Update(seconds);
}

void GoodsCollectionView::handleEvent(sf::Event event) {
	mainWindow->HandleEvent(event);
}

sf::FloatRect GoodsCollectionView::getRect() {
	return this->mainWindow->GetAllocation();
}

GoodView* GoodsCollectionView::getGoodView() {
	return &goodView;
}

void GoodsCollectionView::setController(GoodsCollectionController* controller) {
	this->controller = controller;
}
