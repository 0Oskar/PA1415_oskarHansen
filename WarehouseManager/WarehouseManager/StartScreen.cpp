#include "StartScreen.h"

StartScreen::StartScreen() {
	this->box = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL);

	this->warehouseSelect = sfg::ComboBox::Create();
	this->loadWarehouseButton = sfg::Button::Create("Load Warehouse");

	box->SetSpacing(8.f);
	box->Pack(warehouseSelect);
	box->Pack(loadWarehouseButton);
	box->SetAllocation(sf::FloatRect(330, 200, 0, 0));

	loadWarehouseButton->GetSignal(sfg::Widget::OnLeftClick).Connect([&] { this->box->Show(false); });
}

void StartScreen::handleEvent(sf::Event& e) {
	box->HandleEvent(e);
}

void StartScreen::update(float seconds) {
	box->Update(seconds);
}

void StartScreen::connectLoadWarehouseButton(function<void()> delegate) {
	loadWarehouseButton->GetSignal(sfg::Widget::OnLeftClick).Connect(delegate);
}

void StartScreen::addWarehouse(uint32_t warehouseId) {
	warehouseSelect->AppendItem(to_string(warehouseId));
	warehouseSelect->SelectItem(0);
}

uint32_t StartScreen::getSelectedWarehouse() {
	return (uint32_t)warehouseSelect->GetSelectedItem();
}