#pragma once
#include <SFML\Graphics.hpp>
#include <SFGUI\SFGUI.hpp>
#include <SFGUI\widgets.hpp>
#include "Warehouse.h"

using namespace std;

class StartScreen {
private:
	shared_ptr<sfg::Box> box;
	shared_ptr<sfg::ComboBox> warehouseSelect;
	shared_ptr<sfg::Button> loadWarehouseButton;
public:
	StartScreen();
	void handleEvent(sf::Event& e);
	void connectLoadWarehouseButton(function<void()> delegate);
	uint32_t getSelectedWarehouse();
	void addWarehouse(uint32_t warehouseId);
	void update(float seconds);
};
