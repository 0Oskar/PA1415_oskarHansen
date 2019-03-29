#ifndef _TRUCKCONTROLLER_H_
#define _TRUCKCONTROLLER_H_
#include"truck.h"

class TruckController
{
private:


private:
	int nrOfTrucks;
	Truck* trucks;
	




public:
	TruckController();
	void addOrder(uint32_t fromXPos, uint32_t fromYPos, uint32_t toXPos, int32_t ToyPos, Good &goodToMove);
	void moveTruck(uint32_t truckIndex, uint32_t fromYPos, uint32_t toXPos);

	



};



#endif // !_TRUCKCONTROLLER_H_
