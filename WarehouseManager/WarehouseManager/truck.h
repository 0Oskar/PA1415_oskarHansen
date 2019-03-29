#ifndef _TRUCK_H_
#define _TRUCK_H_

#include<SFML/Window.hpp>
#include"TruckInformation.h"

class Truck
{
private:
	TruckInformation truckInfo;
	sf::Vector2u pos;
	sf::Vector2u shouldMoveTo;
	bool locked;





public:
	Truck(sf::Vector2u pos);
	void moveTowards(int x, int y);
	sf::Vector2u getCurrentPos() const;
	const bool isLocked();
	void setLock(const bool &lockStatus);
	void setDateOfLatestService(const std::string &newDate);
	std::string getDateOfLatestService() const;
	void setTruckManufactor(const std::string &newManufactor);
	std::string getTruckManufactor() const;
	void setBatteryType(const std::string &newBatteryType);
	std::string getBatteryType() const;
	void update(float seconds);

};

#endif // !_TRUCK_H_
