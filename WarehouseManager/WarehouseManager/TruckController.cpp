#include"TruckController.h"


void TruckController::moveTruck(Truck* truck, const uint32_t &toXPos, const uint32_t &toYPos)
{
	this->truck->moveTowards(toXPos, toYPos);
}
void TruckController::setLock(bool lockStatus)
{
	this->truck->setLock(lockStatus);
}
void TruckController::setDateOfLatestService(const std::string &newDate)
{
	this->truck->setDateOfLatestService(newDate);

}
void TruckController::setTruckManufactor(const std::string &newManufactor)
{
	this->truck->setTruckManufactor(newManufactor);

}
void TruckController::setBatteryType(const std::string &newBatteryType)
{
	this->truck->setBatteryType(newBatteryType);
}

Truck* TruckController::getTruck()
{
	return this->truck;
}
void TruckController::setTruck(Truck* newTruck)
{
	this->truck = newTruck;
}