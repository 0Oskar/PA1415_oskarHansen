#include"TruckInformation.h"

TruckInformation::TruckInformation()
{
	this->batteryType = "";
	this->truckManufactor = "";
	this->dateOfLatestService = "YYYY-MM-DD";
}

TruckInformation::TruckInformation(const std::string &dateOfLatestService, 
	const std::string &truckManufactor, const std::string &batteryType)
{
	this->batteryType = batteryType;
	this->truckManufactor = truckManufactor;
	this->dateOfLatestService = dateOfLatestService;
}


void TruckInformation::setDateOfLatestService(const std::string &newDate)
{
	this->dateOfLatestService = newDate;
}

std::string TruckInformation::getDateOfLatestService() const
{
	return this->dateOfLatestService;
}

void TruckInformation::setTruckManufactor(const std::string &newManufactor)
{
	this->truckManufactor = newManufactor;
}

std::string TruckInformation::getTruckManufactor() const
{
	return this->truckManufactor;
}

void TruckInformation::setBatteryType(const std::string &newBatteryType)
{
	this->batteryType = newBatteryType;
}

std::string TruckInformation::getBatteryType() const
{
	return this->batteryType;
}