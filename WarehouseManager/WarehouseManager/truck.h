#ifndef _TRUCK_H_
#define _TRUCK_H_

#include<SFML/Window.hpp>


class Truck
{
private:
	sf::Vector2u pos;
	sf::Vector2u moveTowards;


public:
	Truck(sf::Vector2u pos);
	sf::Vector2u getCurrentPos() const;

};

#endif // !_TRUCK_H_
