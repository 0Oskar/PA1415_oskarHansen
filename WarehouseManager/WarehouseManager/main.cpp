#include <SFML\Graphics.hpp>
#include <SFGUI\SFGUI.hpp>
#include <SFGUI\Widgets.hpp>
#include <iostream>
#include "Warehouse.h"
#include "WarehouseView.h"
#include "StartScreen.h"
#include "WarehouseController.h"
#include "GoodsCollectionController.h"
#include "GoodController.h"

void setup(vector<Warehouse>& warehouses, StartScreen&, WarehouseView&, WarehouseController&);
void setupMockWarehouseHandler(vector<Warehouse>& emptyHandler);
void setupMockWarehouse(Warehouse& warehouse);

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 800), "Warehouse Manager");
	window.resetGLStates();
	sfg::SFGUI sfgui;
	StartScreen startScreen;
	vector<Warehouse> warehouseHandler;
	WarehouseView warehouseView;
	WarehouseController warehouseController;

	setupMockWarehouseHandler(warehouseHandler);
	setup(warehouseHandler, startScreen, warehouseView, warehouseController);

	sf::Event event;
	sf::Clock clock;
	startScreen.update(0.0);
	warehouseView.update(0.0);

	try {
		while (window.isOpen()) {
			while (window.pollEvent(event)) {
				startScreen.handleEvent(event);
				warehouseView.handleEvent(event);

				if (event.type == sf::Event::Closed) {
					window.close();
				}
				if (event.type == sf::Event::MouseButtonReleased) {
					if (event.mouseButton.button == sf::Mouse::Left) {
						cout << event.mouseButton.x << ", " << event.mouseButton.y << endl;
					}
				}
			}

			if (clock.getElapsedTime().asMicroseconds() >= 1000) {
				auto dt = clock.restart().asSeconds();

				startScreen.update(dt);
				warehouseView.update(dt);

				clock.restart();
			}

			window.clear();
			window.draw(warehouseView);
			sfgui.Display(window);
			window.display();
		}
	}
	catch (const char* e) {
		cout << "Exception: " << e << endl;
		system("pause");
	}

	return 0;
}

void setup(vector<Warehouse>& warehouseHandler, StartScreen& startScreen, WarehouseView& warehouseView, WarehouseController& warehouseController) {
	auto loadWarehouseFunction = [&] {
		warehouseView.setVisible(true);
		warehouseView.setWarehouse(&warehouseHandler[startScreen.getSelectedWarehouse()]);
		warehouseController.setWarehouse(&warehouseHandler[startScreen.getSelectedWarehouse()]);
	};
	startScreen.connectLoadWarehouseButton(loadWarehouseFunction);
	for (Warehouse& warehouse : warehouseHandler) {
		startScreen.addWarehouse(warehouse.getId());
	}
	warehouseView.setController(&warehouseController);
}

void setupMockWarehouseHandler(vector<Warehouse>& emptyHandler) {
	Warehouse warehouse0;
	Warehouse warehouse1;

	setupMockWarehouse(warehouse0);
	setupMockWarehouse(warehouse1);
	warehouse1.addShelf(0, 5, 5);
	emptyHandler.push_back(warehouse0);
	emptyHandler.push_back(warehouse1);
}

void setupMockWarehouse(Warehouse& warehouse) {
	uint32_t currentFloor = warehouse.addFloor(20, 20);

	warehouse.addShelf(currentFloor, 1, 1);
	warehouse.addShelf(currentFloor, 1, 2);
	warehouse.addShelf(currentFloor, 1, 3);
	warehouse.addShelf(currentFloor, 1, 4);
	warehouse.addShelf(currentFloor, 1, 5);

	warehouse.addShelf(currentFloor, 5, 5);



	warehouse.addGoodsCollection(currentFloor, 1, 1);
	warehouse.addGood(currentFloor, 1, 1, Good(GoodInformation("TestGood", 0.999), 11));
	warehouse.addGoodsCollection(currentFloor, 1, 2);
	warehouse.addGoodsCollection(currentFloor, 1, 4);

	warehouse.addTruck(currentFloor, 1, 7);
}
