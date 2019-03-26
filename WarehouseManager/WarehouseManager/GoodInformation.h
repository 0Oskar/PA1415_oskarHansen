#pragma once
#include <cstdint>
#include <vector>
#include <string>

using namespace std;

class GoodInformation {
private:
	string name;
	float weight;
public:
	GoodInformation();
	GoodInformation(string name);
	GoodInformation(string name, float weight);
	void setWeight(float newWeight);
	void setName(string newName);
	string getName() const;
	float getWeight() const;
};
