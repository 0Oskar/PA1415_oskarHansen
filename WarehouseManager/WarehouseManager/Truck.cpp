#include"truck.h"

Truck::Truck(sf::Vector2u pos)
{
	this->pos = pos;
	this->moveTowards = sf::Vector2u(pos);
}



sf::Vector2u Truck::getCurrentPos() const
{
	return this->pos;
}