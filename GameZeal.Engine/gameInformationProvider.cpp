#include "gameInformationProvider.h"
#include <iostream>


std::string gameInformationProvider::getObjectProperty(int id, std::string propertyName)
{
	return std::string("Arena");
}

void gameInformationProvider::setObjectProperty(int id, std::string propertyName, std::string value)
{
	std::cout << "setting " + propertyName + " : " + value;
}

void gameInformationProvider::setObjectProperty(int id, std::string propertyName, int value)
{
	std::cout << "setting " + propertyName + " : " + std::to_string(value);
}
