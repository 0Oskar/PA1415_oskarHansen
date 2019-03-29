#ifndef _TRUCKCONTROLLER_H_
#define _TRUCKCONTROLLER_H_
#include"truck.h"


class TruckController
{

private:
	Truck* truck;
	
public:
	void moveTruck(Truck* truck, const uint32_t &toXPos, const uint32_t &toYPos);
	void setLock(bool lockStatus);
	void setDateOfLatestService(const std::string &newDate);
	void setTruckManufactor(const std::string &newManufactor);
	void setBatteryType(const std::string &newBatteryType);
	void setTruck(Truck* newTruck);
	Truck* getTruck();



	



};



#endif // !_TRUCKCONTROLLER_H_
