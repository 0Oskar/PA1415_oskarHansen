#ifndef _TRUCKVIEWER_H_
#define _TRUCKVIEWER_H_
#include <SFGUI/Widgets.hpp>
#include <SFML/Window.hpp>
#include<memory>
#include "GoodsCollection.h"

#include"TruckController.h"

class TruckViwer
{
private:
	const Truck* truck;
	TruckController* truckController;
	shared_ptr<sfg::Window> window;
	shared_ptr<sfg::Box> windowBox;
	shared_ptr<sfg::Label> manufactoryLabel;
	shared_ptr<sfg::Entry> manufactorName;
	shared_ptr<sfg::Label> batteryTypeLabel;
	shared_ptr<sfg::Entry> batteryType;
	shared_ptr<sfg::Label> lastDayOfServiceLabel;
	shared_ptr<sfg::Entry> lastDateOfService;
	shared_ptr<sfg::Label> xAndYCordLabel;
	shared_ptr<sfg::Entry> xCord;
	shared_ptr<sfg::Entry> yCord;
	shared_ptr<sfg::Button> moveTruck;
	uint32_t moveTruckSignal = 0;


	shared_ptr<sfg::Button> updateButton;
	uint32_t updateSignal = 0;

	void fillWindow();
public:
	TruckViwer();
	void setTruck(const Truck* truck);
	void setController(TruckController* truckController);
	void setVisible(bool val);
	void update(float seconds);
	void handleEvent(sf::Event event);
	sf::FloatRect getRect();

};

#endif // !_TRUCKVIEWER_H_
