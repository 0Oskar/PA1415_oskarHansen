#include"truck.h"
#include<iostream>

sf::Time elapsed_time;
sf::Clock r;
Truck::Truck(sf::Vector2u pos)
{
	//this->forkPosition = nullptr;
	this->pos = pos;
	this->shouldMoveTo = sf::Vector2u(pos);
}

void Truck::moveTowards(int x, int y)
{
	this->shouldMoveTo = sf::Vector2u(x, y);
}

sf::Vector2u Truck::getCurrentPos() const
{
	return this->pos;
}

const bool Truck::isLocked()
{
	return this->locked;
}
void Truck::setLock(const bool &lockStatus)
{
	this->locked = lockStatus;
}
void Truck::setDateOfLatestService(const std::string &newDate)
{
	this->truckInfo.setDateOfLatestService(newDate);
}
std::string Truck::getDateOfLatestService() const
{
	return this->truckInfo.getDateOfLatestService();
}
void Truck::setTruckManufactor(const std::string &newManufactor)
{
	this->truckInfo.setTruckManufactor(newManufactor);
}
std::string Truck::getTruckManufactor() const
{
	return this->truckInfo.getTruckManufactor();
}
void Truck::setBatteryType(const std::string &newBatteryType)
{
	this->truckInfo.setBatteryType(newBatteryType);
}
std::string Truck::getBatteryType() const
{
	return this->truckInfo.getBatteryType();
}

void Truck::update(float sec)
{
	elapsed_time += r.restart();
	sf::Time delta_time = sf::seconds(0.5);
	std::cout << elapsed_time.asSeconds() << " >= " << delta_time.asSeconds() << std::endl;
	if (elapsed_time >= delta_time)
	{

		sf::Vector2u moveThisTick;
		if (this->pos != this->shouldMoveTo)
		{
			if (this->pos.x > shouldMoveTo.x)
			{
				moveThisTick.x = -1;
			}
			else if (this->pos.x < shouldMoveTo.x)
			{
				moveThisTick.x = 1;
			}
			else
			{
				moveThisTick.x = 0;
			}

			if (this->pos.y > shouldMoveTo.y)
			{
				moveThisTick.y = -1;
			}
			else if (this->pos.y < shouldMoveTo.y)
			{
				moveThisTick.y = 1;
			}
			else
			{
				moveThisTick.y = 0;
			}
			this->pos += moveThisTick;

			elapsed_time = elapsed_time.Zero;
		}
	}
}