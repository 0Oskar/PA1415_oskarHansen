#include "GoodInformation.h"

GoodInformation::GoodInformation() : name(), weight(0) {
	
}

GoodInformation::GoodInformation(string name) : name(name), weight(0) {
	
}

GoodInformation::GoodInformation(string name, float weight) : name(name), weight(weight) {

}

void GoodInformation::setWeight(float newWeight) {
	this->weight = newWeight;
}

void GoodInformation::setName(string newName) {
	this->name = newName;
}

string GoodInformation::getName() const {
	return name;
}

float GoodInformation::getWeight() const {
	return weight;
}
