#ifndef _TRUCKINFORMATION_H_
#define _TRUCKINFORMATION_H_
#include<string>
class TruckInformation
{
private:
	std::string dateOfLatestService;
	std::string truckManufactor;
	std::string batteryType;
public:
	TruckInformation();
	TruckInformation(const std::string &dateOfLatestService, const std::string &truckManufactor, const std::string &batteryType);
	void setDateOfLatestService(const std::string &newDate);
	std::string getDateOfLatestService() const;
	void setTruckManufactor(const std::string &newManufactor);
	std::string getTruckManufactor() const;
	void setBatteryType(const std::string &newBatteryType);
	std::string getBatteryType() const;




};
#endif // !_TRUCKINFORMATION_H_
