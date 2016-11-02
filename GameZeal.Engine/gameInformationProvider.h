#pragma once
#include <string>

class gameInformationProvider
{
public:
	static std::string gameInformationProvider::getObjectProperty(int id, std::string propertyName);
	static void gameInformationProvider::setObjectProperty(int id, std::string propertyName, std::string value);
	static void gameInformationProvider::setObjectProperty(int id, std::string propertyName, int value);
};

